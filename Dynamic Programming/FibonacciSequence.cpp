#include <iostream>
#include <vector>

std::vector<int> memo(100, -1);
static int counter = 0;

int fib(int n) {
    counter++;
    if(memo[n] != -1) {
        return memo[n];
    }
    
    if (n == 0 || n == 1) {
        return n;
    }
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main() {

    int n = 7;
    std::cout<< "\nFib of " << 100 << " = " << fib(109);

    std::cout << "\n\nCounter: " << counter << std::endl;

    return 0;
}