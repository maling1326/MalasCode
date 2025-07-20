# 📝 Penjelasan Fungsi `Everyone Loves to Sleep` - Codeforces 1714A

Fungsi ini digunakan untuk menghitung berapa lama Vlad bisa tidur sebelum alarm berikutnya berbunyi.

## ❓ Soal

[Link Soal](https://codeforces.com/problemset/problem/1714/A)
Inti soal: Diberikan waktu Vlad tidur dan waktu beberapa alarm berbunyi. Hitung berapa jam dan menit Vlad bisa tidur sebelum alarm terdekat berbunyi. Jika alarm berbunyi saat Vlad tidur, jawabannya 0 0.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode mengubah semua waktu ke satuan menit, lalu mencari selisih waktu tidur dengan alarm terdekat. Jika ada alarm di waktu tidur, hasilnya 0 0.

## 💡 Inti

Inti kode: Konversi waktu ke menit, cari alarm terdekat setelah waktu tidur, hitung selisihnya.

## ⚙️ Cara kerja

Bayangkan waktu sebagai garis. Setiap alarm dan waktu tidur diubah ke menit. Cari alarm terdekat setelah waktu tidur, lalu hitung selisihnya.

## 📦 Contoh

- Input: t = 1, n = 3, H = 7, M = 50, alarm = [(8, 0), (7, 55), (8, 10)]
- Proses: Waktu tidur = 470 menit, alarm = [480, 475, 490]
- Alarm terdekat = 475 (7:55), selisih = 5 menit
- Output: 0 jam 5 menit

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Melakukan iterasi pada seluruh alarm untuk mencari alarm terdekat.

### 🗂️ Space Complexity = `O(n)`

Menyimpan waktu alarm dalam array.

## 💻 Code

```cpp []
class Solution {
public:
    vector<vector<int>> remainingTime (int Example_Time_Max) {
        vvi result (Example_Time_Max);
        bool SkipIteration;
        for (int i = 0; i < (Example_Time_Max); ++i) {
            SkipIteration = false;
            int max, H, M, temp;
            input (max, H, M);
            
            M += H * 60;
            vector<int> nums(max);
            for (int j = 0; j < (max); ++j) {
                input(temp, nums[j]);
                nums[j] += temp * 60;
                temp = 0;
                if (nums[j] == M) {
                    M = nums[j] - M;
                    result[i].push_back(M / 60);
                    result[i].push_back(M % 60);
                    SkipIteration = true;
                }
            }
            if (SkipIteration) continue;
            sort (nums.begin(), nums.end());
            std::stable_partition(nums.begin(), nums.end(), [M](int x) { return x >= M; });

            if (nums[0] < M) {
                M = 1440 - (M - nums[0]);
                result[i].push_back(M / 60);
                result[i].push_back(M % 60);
            }
            else {
                M = nums[0] - M;
                result[i].push_back(M / 60);
                result[i].push_back(M % 60);
            }
        }
        return result;
    }
};
```
