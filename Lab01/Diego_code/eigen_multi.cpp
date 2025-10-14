// eigen_nxn_to_file.cpp
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <random>
#include <thread>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
//Change the elements in NxN
const int N = 1024;

// This is used by random, better tanh STDLIB didnt realized it until now
static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
static std::uniform_int_distribution<int> dist(-100, 100);

// Matrices dinámicas de enteros
MatrixXi A, B;

void random_matrices() {
    //Resizing of the the stuff
    A.resize(N, N);
    B.resize(N, N);

    A = MatrixXi::NullaryExpr(N, N, []() { return dist(rng); });
    B = MatrixXi::NullaryExpr(N, N, []() { return dist(rng); });
}

double operation(bool print_mats = false) {
    auto t0 = chrono::high_resolution_clock::now();
    MatrixXi C = A * B;   // multiplication
    auto t1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = t1 - t0;

    /*if (print_mats && N <= 10) {
        cout << "A:\n" << A << "\n\n";
        cout << "B:\n" << B << "\n\n";
        cout << "C = A * B:\n" << C << "\n\n";
    }*/

    cout << "Time (Eigen int, N=" << N << "): "
         << fixed << setprecision(5) << ms.count() << " ms\n";

    // Same 
    ofstream out("txt_eigen.txt", ios::app);
    if (out) out << N << "," << fixed << setprecision(5) << ms.count() << "\n";
    else     cerr << "Could not open txt_eigen.txt\n";

    return ms.count();
}

int main() {
    //I wanted to experiment with both cycles
    for (int count = 0; count < 10; ++count) {
        random_matrices();
        //Maybe if somone wants to know the time of the operation, i just drop it.
        operation(false);
        // Same sugestion
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    return 0;
}
