#include <iostream>
using namespace std;

static const auto __SET_IO             = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int main() {
    int N, K, sums{0}, i {0}, Total_Full;
    cin >> N >> K;

    int full [N],
        half [N];

    for (int i = 0; i < N; i++) { // Input Full
        cin >> full[i];
        Total_Full += full[i];
    }

    for (int i = 0; i < N; ++i)   // Input Potongan
        cin >> half[i];
    
    if (Total_Full < K) {         // Total Full kurang dari Jumlah kentang
        cout << 1;
        return 0;
    }

    while (true) {
        ++i;
        sums = K * i;

        for (int j = 0; j < (N); ++j)
            sums -= min(i * full[j], half[j]);

        if (sums >= 0) {
            sums = i;
            break;
        }
    }

    cout << sums;
    
    return 0;
}