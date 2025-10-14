#include <iostream>
#include <chrono>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <iomanip>   // fixed, setprecision
#include <fstream>   // ofstream (solo si quieres guardar el tiempo)
#include <thread>    // this_thread::sleep_for (opcional)
using namespace std;
//Change the matrix number of elements
 const int N=1024;
 double A[N][N], B[N][N], C[N][N];

void random_matrices () {

    // Aleatory fit
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            A[i][j] = rand() % 100;   // 0..99
            B[i][j] = rand() % 100;   // 0..99
            C[i][j] = 0.0;           // C empieza en 0
        }
}

void operation() {
    //I only interested on the time for this section
    auto t0 = chrono::high_resolution_clock::now();

    // C = A * B (i-j-k, claro)
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];

    auto t1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms = t1 - t0;

    /* (Opcional) imprime A, B y C si N es pequeño
    if (N <= 10) {
        cout << "A:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) cout << A[i][j] << (j + 1 == N ? '\n' : ' ');
        }
        cout << "B:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) cout << B[i][j] << (j + 1 == N ? '\n' : ' ');
        }
        cout << "C = A * B:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) cout << C[i][j] << (j + 1 == N ? '\n' : ' ');
        }
    }*/

    // Tiempo en pantalla
    cout << "Tiempo: " << fixed << setprecision(5) << ms.count() << " ms\n";

    //  I fell more confortable saving the timings on a document
    ofstream out("timings.txt", ios::app);
    if (out) out << N << "," << fixed << setprecision(5) << ms.count() << "\n";

}
int main() {
    srand((unsigned) time(nullptr));
    int count = 0;
    //Change the count for more sampling
    while (count <10){
        random_matrices();
        operation(); 
        count++; 
        //This is for give time to the program to update the values
        //Maybe there are other ways to do it 
        //ChatGPT provide me with this solution of the thread, 
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
   
    return 0;
}
