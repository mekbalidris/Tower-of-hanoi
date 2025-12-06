#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;


void hanoi_recursive(int n, char from, char aux, char to) {
    if (n == 1) return;
    hanoi_recursive(n - 1, from, to, aux);
    hanoi_recursive(n - 1, aux, from, to);
}


void iterative_hanoi_timed(int n) {
    vector<int> towers[3];
    
    
    for(int i = n; i >= 1; i--) {
        towers[0].push_back(i);
    }
    
    
    long long max_moves = (1LL << n) - 1;
    
    int src = 0, aux = 1, dst = 2;
    if(n % 2 == 0) {
        aux = 2;
        dst = 1;
    }
    
    for(long long move = 1; move <= max_moves; move++) {
        int t1, t2;
        
        if(move % 3 == 1)      { t1 = src; t2 = dst; } 
        else if(move % 3 == 2) { t1 = src; t2 = aux; } 
        else                   { t1 = aux; t2 = dst; }
        
        bool move_from_t1;
        
        if(towers[t1].empty()) {
            move_from_t1 = false;
        }
        else if(towers[t2].empty()) {
            move_from_t1 = true;
        }
        else if(towers[t1].back() < towers[t2].back()) {
            move_from_t1 = true;
        }
        else {
            move_from_t1 = false;
        }
        
        
        if(move_from_t1) {
            int disk = towers[t1].back();
            towers[t1].pop_back();
            towers[t2].push_back(disk);
        } else {
            int disk = towers[t2].back();
            towers[t2].pop_back();
            towers[t1].push_back(disk);
        }
    }
}


int main() {
    ofstream file("results.csv");
    file << "n,recursive_ms,iterative_ms\n";

    cout << "Starting Benchmark... (Note: N=30 might take a long time)\n";

   
    for (int n = 1; n <= 30; n++) { 
        
       
        auto start = high_resolution_clock::now();
        hanoi_recursive(n, 'A', 'B', 'C');
        auto end = high_resolution_clock::now();
        double rec_time = duration_cast<milliseconds>(end - start).count();

        
        start = high_resolution_clock::now();
        iterative_hanoi_timed(n);
        end = high_resolution_clock::now();
        double iter_time = duration_cast<milliseconds>(end - start).count();

        file << n << "," << rec_time << "," << iter_time << "\n";
        cout << "n=" << n << " done.";
    }

    file.close();
    cout << "Benchmark saved to results.csv\n";
    return 0;
}
