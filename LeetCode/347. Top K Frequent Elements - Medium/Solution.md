# Penjelasan Fungsi `topKFrequent` - Leetcode 347

Fungsi `topKFrequent` digunakan untuk mencari k elemen yang paling sering muncul dalam sebuah array integer.

## Cara kerja

Fungsi menghitung frekuensi kemunculan setiap elemen menggunakan `unordered_map`. Kemudian, elemen dikelompokkan berdasarkan frekuensi menggunakan `map` dengan urutan menurun. Selanjutnya, fungsi mengambil k elemen dengan frekuensi tertinggi dan mengembalikannya sebagai hasil.

## Contoh

Contoh:

- Input: nums = [1,1,1,2,2,3], k = 2
- Proses: Frekuensi: 1 → 3x, 2 → 2x, 3 → 1x
- Output: [1,2]

## Inti

Inti kode: Hitung frekuensi, urutkan berdasarkan frekuensi, ambil k elemen teratas.

## Complexity

### Time Complexity = `O(n log n)`

Menghitung frekuensi membutuhkan `O(n)`, pengelompokan dan pengurutan dengan map membutuhkan `O(n log n)`.

### Space Complexity = `O(n)`

Menyimpan frekuensi dan hasil dalam struktur data tambahan, sehingga kompleksitas ruang O(n).

## Code

```cpp []
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Kelompokkan elemen berdasarkan frekuensi, urut menurun berdasarkan frekuensi
        map<int, vector<int>, greater<int>> freqGroups;
        for (auto& p : freq) {
            freqGroups[p.second].push_back(p.first);
        }

        vector<int> result;
        for (auto& group : freqGroups) {
            for (int num : group.second) {
                if (result.size() == k) break;
                result.push_back(num);
            }
            if (result.size() == k) break;
        }
        
        return result;
    }
};
```
