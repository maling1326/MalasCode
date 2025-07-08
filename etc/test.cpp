#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 5, 4, 3, 2, 1};
    std::vector<int> s = {3, 4};

    for (int i = 0; i < v.size() + s.size(); i++)
    {
        if (i < v.size())
            std::cout << v[i] << ". ";
        if (i > v.size() - 1)
            std::cout << s[i - v.size()] << ", ";
    }

    std::cout << '\n' << v[0 + s.size() - 1];
    

    return 0;
}