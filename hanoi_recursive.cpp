#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int step = 0; 

void hanoi_recursive(int n, char from, char aux, char to) {
    if (n == 1) {
        step++;
        cout << "Step " << step << ": Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    
    hanoi_recursive(n - 1, from, to, aux);
    
    step++;
    cout << "Step " << step << ": Move disk " << n << " from " << from << " to " << to << endl;
    
    hanoi_recursive(n - 1, aux, from, to);
}

int main() {
    int n;
    cout << "Recursive Hanoi - Enter number of disks: ";
    cin >> n;

    auto start = high_resolution_clock::now();

    step = 0;
    hanoi_recursive(n, 'A', 'B', 'C');

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "------------------------------------------------\n";
    cout << "Finished moving " << n << " disks.\n";
    cout << "Total time taken: " << duration.count() << " microseconds (" 
         << duration.count() / 1000.0 << " milliseconds)\n";

    return 0;
}