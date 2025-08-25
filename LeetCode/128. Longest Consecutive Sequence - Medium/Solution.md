# 📝 Penjelasan Fungsi `longestConsecutive` - Leetcode `128. Longest Consecutive Sequence`

Fungsi `longestConsecutive` digunakan untuk mencari panjang urutan angka berurutan terpanjang dalam array integer `nums`.

## ❓ Soal

Diberikan array integer `nums` (tidak terurut), cari panjang urutan angka berurutan terpanjang yang bisa dibentuk dari elemen-elemen array tersebut.

[Link Soal](https://leetcode.com/problems/longest-consecutive-sequence/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini mengurutkan array, menghapus duplikat, lalu menghitung urutan angka berurutan terpanjang dengan satu kali iterasi.

## 💡 Inti

Inti dari kode ini adalah: setelah array diurutkan dan duplikat dihapus, cukup cek apakah elemen berikutnya adalah satu lebih besar dari sebelumnya untuk membentuk urutan berurutan.

## ⚙️ Cara kerja

1. Jika array kosong, langsung return 0.
2. Urutkan array `nums` secara ascending.
3. Hapus elemen duplikat dari array.
4. Inisialisasi variabel `ans` untuk menyimpan hasil maksimum dan `temp` untuk menghitung panjang urutan saat ini.
5. Iterasi mulai dari elemen kedua:
   - Jika elemen sekarang satu lebih besar dari sebelumnya, tambah `temp`.
   - Jika tidak, update `ans` dengan nilai maksimum antara `ans` dan `temp`, lalu reset `temp` ke 1.
6. Setelah iterasi, update `ans` sekali lagi untuk memastikan urutan terakhir dihitung.
7. Return `ans`.

## 📦 Contoh

- Input: `nums = [100,4,200,1,3,2]`
  - Setelah sort & hapus duplikat: `[1,2,3,4,100,200]`
  - Urutan terpanjang: `[1,2,3,4]` → panjang 4
- Input: `nums = [1,0,1,2]`
  - Setelah sort & hapus duplikat: `[0,1,2]`
  - Urutan terpanjang: `[0,1,2]` → panjang 3

## 📊 Complexity

### ⏱️ Time Complexity = `O(n log n)`

Karena proses sort dan hapus duplikat.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan struktur data tambahan yang signifikan, hanya variabel penghitung.

## 💻 Code

```cpp []
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int ans{0}, temp{1};
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int i = 1; i < ssize(nums); ++i) {
            if (nums[i] - 1 == nums[i - 1])
                temp++;
            else {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};
```
