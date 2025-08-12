#include <iostream>

static const auto __SET_IO             = [] {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

int main() {
    int n, s, a = 0, b = 0, c = 0, d = 0;
    std::cin >> n;

    for (int i = 0; i < (n); ++i) {
        std::cin >> s;
        switch (s) { case 1: a++; break;
                     case 2: b++; break;
                     case 3: c++; break;
                     case 4: d++; break; }
    }

    // Grup 4 orang di masukin Taxi
    s = d;

    // Grup 3 orang dan 1 Orangs
    s += c;
    a -= std::min(c, a);

    // Grup 2 Orang dimasukan
    s += b / 2;
    b %= 2;

    if (b) { // Jika ada sisa dari grup 2, maka digabung dengan grup 1
        s++;
        a -= std::min(2, a);
    }

    // Grup 1 dimasukkan semua
    s += (a + 3) / 4;

    std::cout << s;

    return 0;
}