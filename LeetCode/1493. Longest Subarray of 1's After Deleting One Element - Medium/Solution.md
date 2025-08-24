# 📝 Penjelasan Fungsi `longestSubarray` - Leetcode `1493. Longest Subarray of 1's After Deleting One Element`

Fungsi `longestSubarray` digunakan untuk mencari panjang subarray terpanjang yang hanya berisi angka 1 setelah menghapus tepat satu elemen dari array biner `nums`.

## ❓ Soal

Diberikan array biner `nums`, hapus satu elemen, lalu cari panjang subarray terpanjang yang hanya berisi angka 1. Jika tidak ada, return 0.

[Link Soal](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1746698287/?envType=daily-question&envId=2025-08-24)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini menghitung dua segmen berturut-turut angka 1 yang dipisahkan oleh satu angka 0, lalu mencari kombinasi terpanjang setelah satu elemen dihapus (yaitu satu 0 dihapus).

## 💡 Inti

Inti dari kode ini adalah menggabungkan dua segmen angka 1 yang dipisahkan oleh satu 0, dan mencari maksimum dari hasil penggabungan tersebut.

## ⚙️ Cara kerja

1. Inisialisasi variabel: `maxx` untuk hasil maksimum, `l` untuk segmen 1 sebelum 0, `r` untuk segmen 1 setelah 0, dan `del` untuk menghitung jumlah 0 yang ditemukan.
2. Iterasi setiap elemen di `nums`:
   - Jika elemen 0 dan sebelumnya ada segmen 1, update `maxx` dengan `l + r`, lalu geser `l` ke `r` dan reset `r` ke 0, tambah `del`.
   - Jika elemen 1, tambah `r`.
   - Setiap kali `r > 0`, update `maxx` dengan `l + r`.
3. Setelah iterasi, jika tidak ada 0 yang dihapus dan hasil masih 0, return 0.
4. Jika seluruh array 1, hasilnya adalah panjang array dikurangi 1 (karena wajib hapus satu elemen).
5. Return `maxx`.

## 📦 Contoh

- Input: `nums = [1,1,0,1]`
  - Hapus angka 0 di posisi 2, hasil: `[1,1,1]`, output: 3
- Input: `nums = [0,1,1,1,0,1,1,0,1]`
  - Hapus angka 0 di posisi 4, hasil: `[1,1,1,1,1]`, output: 5
- Input: `nums = [1,1,1]`
  - Harus hapus satu elemen, hasil: 2

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Hanya satu kali iterasi seluruh elemen array.

### 🗂️ Space Complexity = `O(1)`

Menggunakan variabel penghitung saja.

## 💻 Code

```cpp []
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxx {0}, del{0}, l {0}, r {0};
        debug("START");
        debug("->", nums);
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && (l != 0 or r != 0)) {
                maxx = max(maxx, l + r);
                l = r;
                r = 0;
                del++;
            }
            else if (nums[i] == 1) 
                r++;

            if (r > 0) maxx = max(maxx, l + r);
            debug(nums[i], i, l, r, del, maxx);
        }
        if (del == 0 and maxx == 0) return 0;
        return (del == 0 and r == nums.size()) ? nums.size() - 1 : maxx;
    }
};
```
