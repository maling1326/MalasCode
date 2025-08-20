# 📝 Penjelasan Fungsi `countSquares` - Leetcode `1277. Count Square Submatrices with All Ones`

Fungsi `countSquares` digunakan untuk menghitung jumlah submatriks persegi yang seluruh elemennya adalah 1 di dalam matriks biner.

## ❓ Soal

Diberikan matriks biner berukuran m x n, hitung berapa banyak submatriks persegi (ukuran berapapun) yang seluruh elemennya adalah 1.

[Link Soal](https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/1742259436/?envType=daily-question&envId=2025-08-20)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini menggunakan dynamic programming untuk menghitung jumlah persegi yang berakhir di setiap posisi matriks, lalu menjumlahkan semuanya.

## 💡 Inti

Inti dari kode ini adalah membangun matriks DP, di mana setiap elemen menyimpan ukuran sisi persegi terbesar yang berakhir di posisi tersebut, dan semua nilai DP dijumlahkan sebagai total persegi.

## ⚙️ Cara kerja

1. Inisialisasi matriks DP dengan ukuran sama seperti input, semua bernilai 0.
2. Iterasi setiap elemen matriks:
   - Jika di baris atau kolom pertama, atau nilainya 0, DP diisi sesuai nilai aslinya (0 atau 1).
   - Jika nilainya 1, DP diisi minimum dari tiga arah (atas, kiri, diagonal kiri-atas) ditambah 1.
   - Tambahkan nilai DP ke total `sz` (jumlah persegi).
3. Setelah semua elemen diproses, return `sz` sebagai jumlah total persegi.

## 📦 Contoh

- Input:
  
  ```powershell
  [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
  ]
  ```

  - Step: Ada 10 persegi 1x1, 4 persegi 2x2, 1 persegi 3x3. Total = 15.
- Input:
  
  ```powershell
  [
    [1,0,1],
    [1,1,0],
    [1,1,0]
  ]
  ```
  
  - Step: Ada 6 persegi 1x1, 1 persegi 2x2. Total = 7.

## 📊 Complexity

### ⏱️ Time Complexity = `O(m * n)`

Setiap elemen matriks hanya diproses sekali.

### 🗂️ Space Complexity = `O(m * n)`

Menggunakan matriks DP dengan ukuran sama seperti input.

## 💻 Code

```cpp []
using vi            = vector<int>;
using vvi           = vector<vi>;
#define rep(i, n)     for(int i = 0; i < (n); ++i)
#define rev(i, n)     for(int i = (n) - 1; i >= 0; --i)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;

        int m  = matrix.size(), 
            n  = matrix[0].size(), 
            sz = 0;
        vvi dp (m, vi(n, 0));

        rep(i, m) {
            rep(j, n) {
                if (!i || !j || matrix[i][j] == 0) {
                    dp[i][j] = matrix[i][j];
                    if (dp[i][j] == 1) sz += 1;
                }
                else {
                    dp[i][j] = min( dp[ i - 1 ][ j - 1 ], min(dp[ i - 1 ][ j ], dp[ i ][ j - 1 ])) + 1;
                    sz += dp[i][j];
                }
            }
        }
        return sz;
    }
};
```
