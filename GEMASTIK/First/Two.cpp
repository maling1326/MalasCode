#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int Total_Min, Walk_Duration;
    std::cin >> Total_Min >> Walk_Duration;

    std::vector<int> Droplets(Total_Min, 0);
    for (int i = 0; i < Total_Min; i++) 
        std::cin >> Droplets[i];

    int limit_upper = Droplets.size() - Walk_Duration - 1,
        limit_lower = Walk_Duration,
        max = Droplets.size() - 1,
        result = 0;

    for (int i = 0; i < limit_upper; i++) {
        for (int j = max; j > limit_lower + i; j--) {
            for (int k = 0; k < Walk_Duration; k++) {
                result += Droplets[i + k];
                result += Droplets[j - k];
            }
            Droplets.emplace_back(result);
            result = 0;
        }
    }
    Droplets.erase(Droplets.begin(), Droplets.begin() + max + 1);

    result = *std::min_element(Droplets.begin(), Droplets.end());;
    std::cout << result;
    return 0;
}