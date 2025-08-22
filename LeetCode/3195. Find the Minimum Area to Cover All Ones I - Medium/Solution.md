# 📝 Penjelasan Fungsi `minimumArea` - Leetcode `3195. Find the Minimum Area to Cover All Ones I`

Fungsi `minimumArea` digunakan untuk mencari luas minimum persegi panjang yang dapat menutupi seluruh angka 1 pada grid biner.

## ❓ Soal

Diberikan grid 2D berisi 0 dan 1, cari luas minimum persegi panjang (sisi sejajar sumbu) yang mencakup semua angka 1 di grid.

[Link Soal](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/submissions/1744029513/?envType=daily-question&envId=2025-08-22)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini mencari batas paling kiri, kanan, atas, dan bawah dari semua angka 1 di grid, lalu menghitung area persegi panjang yang menutupinya.

## 💡 Inti

Inti dari kode ini adalah mencari indeks minimum dan maksimum baris dan kolom yang mengandung angka 1, lalu menghitung area persegi panjang dari batas-batas tersebut.

## ⚙️ Cara kerja

1. Inisialisasi batas atas (`Xstart`), bawah (`Xend`), kiri (`Ystart`), kanan (`Yend`) dengan nilai ekstrim.
2. Iterasi seluruh elemen grid:
   - Jika ditemukan angka 1, update batas atas/bawah/kiri/kanan sesuai posisi.
3. Setelah iterasi, jika tidak ada angka 1 (`Yend < 0`), return 0.
4. Jika ada, hitung area: `(Xend - Xstart + 1) * (Yend - Ystart + 1)`.

## 📦 Contoh

- Input: `[[0,1,0],[1,0,1]]`
  - Semua 1 terletak di area dari (0,1) ke (1,2), area = 2 * 3 = 6.
- Input: `[[1,0],[0,0]]`
  - Hanya satu angka 1 di (0,0), area = 1 * 1 = 1.

## 📊 Complexity

### ⏱️ Time Complexity = `O(m * n)`

Setiap elemen grid dicek satu kali.

### 🗂️ Space Complexity = `O(1)`

Hanya menggunakan variabel penghitung, tanpa struktur data tambahan.

## 💻 Code

```cpp []
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        const int x = grid.size(),
                  y = grid[0].size();
        int Xstart {x}, Xend {-1},
            Ystart {y}, Yend {-1};
        for(int i = 0; i < x; ++i) {
            for(int j = 0; j < y; ++j) {
                if (grid[i][j]) {
                    if (i < Xstart) Xstart  = i;
                    if (i > Xend)   Xend    = i;
                    if (j < Ystart) Ystart  = j;
                    if (j > Yend)   Yend    = j;
                }
            }
        }
        return (Yend < 0) ? 0 : (Xend - Xstart + 1) * (Yend - Ystart + 1);
    }
};
```
