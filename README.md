# 🔐 Shamir's Secret Sharing Scheme - Polynomial Reconstruction

This project demonstrates the reconstruction of a secret using **Lagrange interpolation**, where a secret has been split into shares using **Shamir's Secret Sharing** scheme.

## 🧠 Project Description

Given a secret polynomial of the form:

f(x) = a₀ + a₁x + a₂x² + ... + aₖ₋₁xᵏ⁻¹


You are provided with multiple (x, y) points (`shares`) encoded in JSON format. Your task is to **reconstruct the constant term `a₀` (the original secret)** using Lagrange Interpolation over a finite field.

## 📂 Project Structure
```
.
├── json.hpp # JSON library for C++ (nlohmann/json)
├── secretkey.cpp # Main C++ implementation using Lagrange Interpolation
├── secret_solver.exe # Executable for running the project
├── testcase1.json # Test case file with shares
├── testcase2.json # Another test case file
├── README.md # This file
```

## ⚙️ How to Run

### 🖥️ Using Executable (Windows)

1. Open Command Prompt or PowerShell in the project directory.
2. Run:
   ```bash
   .\secret_solver.exe testcase1.json
or
```bash
.\secret_solver.exe testcase2.json
```
The secret (value of f(0)) will be printed.

🧑‍💻 Compile Manually (Optional)
If you want to compile the code yourself:
```bash
g++ secretkey.cpp -o secret_solver.exe
.\secret_solver.exe testcase1.json
```
Make sure you have json.hpp in the same directory.
