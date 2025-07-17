#include <iostream>

int main() {
    long long A, B, C, D, days = 0;
    std::cin >> A >> B >> C >> D;

    if (B == 0 &&  C == 0) days = (A + D + 2) / 3;
    else if       (B == 0) days = ((A + C + 2) / 3) + (D + 2) / 3;
    else if       (C == 0) days = ((B + D + 2) / 3) + (A + 2) / 3;
    else                   days = ((B + C + 2) / 3) + (A + 2) / 3 + (D + 2) / 3;

    std::cout << days;
    return 0;
}