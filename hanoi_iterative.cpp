#include <iostream>
#include <vector>
#include <cmath>
#include <chrono> 

using namespace std;
using namespace std::chrono;

int step_count = 0;

void move_disk(char from, char to) {
    step_count++;
    cout << "Step " << step_count << ": Move disk from " << from << " to " << to << endl;
}

void iterative_hanoi(int n) {
    step_count = 0;
    
    // Setup three towers using Vectors
    vector<int> tower[3]; 
    char names[] = {'A', 'B', 'C'};
    
    // Put disks on first tower
    for(int i = n; i >= 1; i--) {
        tower[0].push_back(i);
    }
    
    int total_moves = (1 << n) - 1;
    
    int src = 0, aux = 1, dst = 2;
    if(n % 2 == 0) {
        aux = 2;
        dst = 1;
    }
    
    for(int i = 1; i <= total_moves; i++) {
        int t1, t2;
        
        if(i % 3 == 1)      { t1 = src; t2 = dst; } 
        else if(i % 3 == 2) { t1 = src; t2 = aux; } 
        else                { t1 = aux; t2 = dst; }
        
        bool move_from_t1;
        
        if(tower[t1].empty()) {
            move_from_t1 = false;
        }
        else if(tower[t2].empty()) {
            move_from_t1 = true;
        }
        else if(tower[t1].back() < tower[t2].back()) {
            move_from_t1 = true;
        }
        else {
            move_from_t1 = false;
        }
        
        if(move_from_t1) {
            int disk = tower[t1].back();
            tower[t1].pop_back();
            tower[t2].push_back(disk);
            move_disk(names[t1], names[t2]);
        } else {
            int disk = tower[t2].back();
            tower[t2].pop_back();
            tower[t1].push_back(disk);
            move_disk(names[t2], names[t1]);
        }
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