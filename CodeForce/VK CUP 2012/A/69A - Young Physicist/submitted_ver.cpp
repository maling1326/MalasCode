#include <iostream>

static const auto __SET_IO             = [] {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

int main() {
    int m, a{0}, b{0}, c{0};
    std::cin >> m;
    
    for (int i = 0; i < (m * 3); ++i) {
        int t;
        std::cin >> t;
        if (i % 3 == 0) 
            a += t;
        else if (i % 3 == 1) 
            b += t;
        else if (i % 3 == 2) 
            c += t;
    }

    if (a == 0 and b == 0 and c == 0)
        std::cout << "YES";
    else 
        std::cout << "NO";

    return 0;
}