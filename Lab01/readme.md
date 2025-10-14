# 🧩 Lab 1 – Getting Started: Environment, Command Line, Compiling, Debugging, and Programming Basics

## 🎯 Objectives
- Set up the PACS working environment.  
- Learn to use the **Shell (command line)** for file and process management.  
- Understand what a **compiler** and **debugger** are and how to use them in C++.  
- Practice **C++ sequential programming** with and without the **Eigen** library.  
- Evaluate **program performance** through execution time analysis.  

---

## 🧮 Assignments

### **1️⃣ Standard Matrix Multiplication**
- Implement a basic **NxN matrix multiplication** in C++.  
- Use `double` as the data type and either static or dynamic memory allocation (prefer dynamic).  
- Verify correctness with small matrices, then test larger ones.  

### **2️⃣ Matrix Multiplication with Eigen**
- Recreate the same multiplication using the **Eigen 3.4.0** math library.  
- Compile with optimization and include Eigen headers:
  ```bash
  g++ -O2 -Wall -I $HOME/PACS/lab1/eigen-3.4.0/ my_eigen_matmult.cpp -o my_eigen_matmult

