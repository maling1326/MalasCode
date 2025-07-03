#include <iostream>
#include <random>

int main() {
    srand(time(0));
    int num = rand() % 1000;
    std::cout << num << "\nAND\n";
    num = rand() % 1000;
    std::cout << num;

    return 0;
}