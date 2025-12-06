
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    ofstream gp("plot_script.gp");
    gp << "set datafile separator ','\n"; 
    gp << "set xrange [1:30]\n"; 

    gp << "set title 'Hanoi Execution Time (Recursion vs Iteration)'\n";
    gp << "set xlabel 'Number of Disks'\n";

    gp << "set ylabel 'Time (ms)'\n";
    gp << "set grid\n";

    gp << "set key top left\n";
    gp << "plot 'results.csv' every ::1 using 1:2 with lines lw 2 title 'Recursive', "
          "'results.csv' every ::1 using 1:3 with lines lw 2 title 'Iterative'\n";

    gp.close();

    system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" -persist plot_script.gp");

    return 0;
}