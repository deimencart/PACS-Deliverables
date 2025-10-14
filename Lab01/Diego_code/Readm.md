# 🧩 Lab 1 – Matrix Multiplication Performance (Sequential vs. Eigen)

**Course:** Programming and Architecture of Computing Systems (PACS)  
**Student:** Diego Méndez Carter  
**Date:** October 5, 2025  
**Grade:** 75 / 100  
**Evaluated by:** Valero Bresó, Alejandro  
---

## 🧑‍🏫 Professor’s Feedback

| **Category** | **Comments by Prof. Valero Bresó (11 Oct 2025, 12:58)** |
|---------------|----------------------------------------------------------|
| **Pros** | - Reported standard deviation for 10 samples and speedup.<br>- Reported computational complexity clearly. |
| **Cons** | - No discussion on memory allocation policy.<br>- No discussion on the results of the `time` command.<br>- Only slight discussion on the differences between Eigen and custom code. |
| **Final Grade** | **75 / 100** |


---

## 🧠 Summary of Deliverable
This lab introduced the basics of **command-line programming, C++ compilation, debugging, and performance measurement**.  
The objective was to compare two sequential matrix multiplication implementations and analyze their performance differences.

### Implementations
1. **Standard C++ Version (`usr_mat_multi.cpp`)**
   - Implemented with three nested loops for `C = A × B`.
   - Used static 2D arrays of type `double`.
   - Randomly generated matrix values (`0–99`).
   - Execution time measured via `<chrono>` and logged in `timings.txt`.

2. **Eigen Library Version (`eigen_multi.cpp`)**
   - Used **Eigen 3.4.0** for optimized matrix operations with dynamic memory allocation.
   - Random matrices generated with `<random>` and timed using `<chrono>`.
   - Results saved in `txt_eigen.txt`.
   - Compiled with:
     ```bash
     g++ -O2 -Wall -I $HOME/PACS/lab1/eigen-3.4.0/ eigen_multi.cpp -o eigen_multi
     ```

Both programs were executed **10 times per matrix size (128, 256, 512, 1024)** to compute the **mean and standard deviation** of the execution times and analyze **speedup**.

---

## 📊 Results

| **Matrix Size (N×N)** | **Standard (ms)** | **Eigen (ms)** | **Speedup** |
|------------------------|------------------:|----------------:|-------------:|
| 128                    | ~12.3 ± 0.6       | ~3.4 ± 0.2      | 3.6×         |
| 256                    | ~94.5 ± 2.1       | ~15.7 ± 0.5     | 6.0×         |
| 512                    | ~752.1 ± 8.7      | ~90.3 ± 1.9     | 8.3×         |
| 1024                   | ~6014.8 ± 42.5    | ~615.7 ± 9.4    | 9.8×         |

- Both versions exhibit **O(N³)** growth.
- **Eigen** performed up to **10× faster** than the hand-coded loop implementation.
- Performance difference is due to **vectorization**, **cache efficiency**, and **compiler-level optimizations**.

---

## 💬 Discussion
The comparison confirmed that although both algorithms share the same **theoretical complexity**, the **Eigen library** implementation achieves **substantially better real-world performance**.  
This is attributed to:
- Optimized memory access and instruction-level parallelism.
- Automatic vectorization.
- Better cache locality and compiler optimizations.

The experiment demonstrated the importance of using specialized libraries for computational tasks in robotics and computer vision contexts.

---

## 📚 Reference
Parthasarathi, R. *Computer Architecture: Engineering and Technology.*  
University of Maryland.  
[http://www.cs.umd.edu/~meesh/cmsc411/CourseResources/CA-online/](http://www.cs.umd.edu/~meesh/cmsc411/CourseResources/CA-online/)

---

**Summary:**  
The lab successfully achieved its core objectives of practicing compilation, execution, and basic performance evaluation.  
However, future reports should include **explicit discussion on memory allocation**, **`time` command breakdown**, and **deeper comparison between Eigen and manual code** to achieve a higher evaluation.


