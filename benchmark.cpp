#include <iostream>
#include <fstream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace chrono;

void hanoi_recursive(int n, char from, char aux, char to) {
    if (n == 1) return;
    hanoi_recursive(n - 1, from, to, aux);
    hanoi_recursive(n - 1, aux, from, to);
}

void iterative_hanoi(int n) {
    char A='A', B='B', C='C';
    if (n % 2 == 0) swap(C,B);
    int moves = pow(2, n) - 1;
    for (int i = 1; i <= moves; i++);
}

int main() {
    ofstream file("results.csv");
    file << "n,recursive_ms,iterative_ms\n";

    for (int n = 1; n <= 30; n++) {
        auto start = high_resolution_clock::now();
        hanoi_recursive(n, 'A', 'B', 'C');
        auto end = high_resolution_clock::now();
        double recursive_time = duration_cast<milliseconds>(end - start).count();

        start = high_resolution_clock::now();
        iterative_hanoi(n);
        end = high_resolution_clock::now();
        double iterative_time = duration_cast<milliseconds>(end - start).count();

        file << n << "," << recursive_time << "," << iterative_time << "\n";

        cout << "n=" << n << " done.\n";
    }

    file.close();
    cout << "Benchmark saved to results.csv\n";
    return 0;
}

