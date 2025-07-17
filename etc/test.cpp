#include <iostream>
using namespace std;

void buildPrefixSum(int arr[], int prefixSum[], int n) {
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int rangeSum(int prefixSum[], int l, int r) {
    if (l == 0)
        return prefixSum[r];
    else
        return prefixSum[r] - prefixSum[l - 1];
}

int main() {
    
    int a = 0;
    a = (a + 2) % 4;
    // if (a == 3)
        cout << a;

    return 0;
}