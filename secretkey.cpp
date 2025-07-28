#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;
using ll = long long;

ll decodeValue(const string& value, int base) {
    ll result = 0;
    for (char c : value) {
        int digit = isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
        result = result * base + digit;
    }
    return result;
}

vector<pair<ll, ll>> readPointsFromJson(const string& file, int k) {
    ifstream f(file);
    json data;
    f >> data;
    vector<pair<ll, ll>> points;
    for (auto& el : data.items()) {
        if (el.key() == "keys") continue;
        ll x = stoll(el.key());
        int base = stoi(el.value()["base"].get<string>());
        string value = el.value()["value"];
        ll y = decodeValue(value, base);
        points.push_back({x, y});
    }
    sort(points.begin(), points.end());
    return vector<pair<ll, ll>>(points.begin(), points.begin() + k);
}

ll lagrangeInterpolationAtZero(const vector<pair<ll, ll>>& points) {
    ll result = 0;
    int k = points.size();
    for (int i = 0; i < k; ++i) {
        ll xi = points[i].first;
        ll yi = points[i].second;
        ll num = 1, den = 1;
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            ll xj = points[j].first;
            num *= -xj;
            den *= (xi - xj);
        }
        result += yi * (num / den);
    }
    return result;
}

int main() {
    string file1 = "testcase1.json";
    ifstream in1(file1);
    json j1;
    in1 >> j1;
    int k1 = j1["keys"]["k"];
    vector<pair<ll, ll>> points1 = readPointsFromJson(file1, k1);
    ll secret1 = lagrangeInterpolationAtZero(points1);

    string file2 = "testcase2.json";
    ifstream in2(file2);
    json j2;
    in2 >> j2;
    int k2 = j2["keys"]["k"];
    vector<pair<ll, ll>> points2 = readPointsFromJson(file2, k2);
    ll secret2 = lagrangeInterpolationAtZero(points2);

    cout << "Secret (Test Case 1): " << secret1 << endl;
    cout << "Secret (Test Case 2): " << secret2 << endl;

    return 0;
}
