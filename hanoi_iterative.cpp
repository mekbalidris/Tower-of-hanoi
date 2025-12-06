#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

int step_count = 0;

void record_move(char from, char to) {
    move_counter++;
    cout << "Step " << move_counter << ": Move disk from " << from << " to " << to << endl;
}

void iterative_hanoi(int n) {
    char A = 'A', B = 'B', C = 'C';

    if (n % 2 == 0) swap(C, B);

    int total_moves = pow(2, n) - 1;

    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) move_disk(A, C);
        else if (i % 3 == 2) move_disk(A, B);
        else move_disk(B, C);
    }
}

int main() {
    int n;
    cout << "Iterative Hanoi - Enter number of disks: ";
    cin >> n;

    auto start = high_resolution_clock::now();

    step_count = 0;
    iterative_hanoi(n);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "------------------------------------------------\n";
    cout << "Finished moving " << n << " disks.\n";
    cout << "Total time taken: " << duration.count() << " microseconds (" 
         << duration.count() / 1000.0 << " milliseconds)\n";

    return 0;
}