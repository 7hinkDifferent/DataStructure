#include <iostream>
#include <iomanip>
using namespace std;

double Fib(double n) {
    return (n < 2) ? n : Fib(n - 1) + Fib(n - 2);
}

int main() {
    // for (int i = 0; i < 100; i++) {
    //     cout << "Fib(" << i << "): " << Fib(i) << endl;  
    // }
    double f = 1.0;
    double g = 0.0;
    int n = 0;
    while (1000 > n++) {
        g = g + f;
        f = g - f;
        cout << "Fib(" << n << "):" << g << endl;
    }
}