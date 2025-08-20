# 📝 Penjelasan Fungsi `maximalSquare` - Leetcode `221. Maximal Square`

Fungsi `maximalSquare` digunakan untuk mencari luas persegi terbesar yang hanya terdiri dari angka 1 di dalam matriks biner.

## ❓ Soal

Diberikan matriks biner berukuran m x n, cari luas persegi terbesar yang hanya berisi angka 1.

[Link Soal](https://leetcode.com/problems/maximal-square/?envType=problem-list-v2&envId=dynamic-programming)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini menggunakan dynamic programming untuk menghitung ukuran persegi terbesar di setiap posisi matriks, dengan memanfaatkan hasil perhitungan sebelumnya.

## 💡 Inti

Inti dari kode ini adalah membangun matriks DP, di mana setiap elemen menyimpan ukuran sisi persegi terbesar yang berakhir di posisi tersebut.

## ⚙️ Cara kerja

1. Inisialisasi matriks DP dengan ukuran sama seperti input, semua bernilai 0.
2. Iterasi setiap elemen matriks:
   - Jika di baris atau kolom pertama, atau nilainya '0', DP diisi 0 atau 1 sesuai nilai aslinya.
   - Jika nilainya '1', DP diisi minimum dari tiga arah (atas, kiri, diagonal kiri-atas) ditambah 1.
   - Update nilai maksimum sisi persegi (`sz`) jika ditemukan yang lebih besar.
3. Setelah semua elemen diproses, return `sz * sz` sebagai luas maksimal.

## 📦 Contoh

- Input:  
  
  ```powershell
  [["1","0","1","0","0"],
   ["1","0","1","1","1"],
   ["1","1","1","1","1"],
   ["1","0","0","1","0"]]
  ```

  - Step: DP akan membentuk nilai maksimal 2 (sisi persegi), sehingga area = 4.
- Input: `[["0","1"],["1","0"]]`
  - Step: Hanya ada persegi 1x1, area = 1.

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
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m  = matrix.size(), 
            n  = matrix[0].size(), 
            sz = 0;
        vvi dp (m, vi(n, 0));

        rep(i, m) {
            rep(j, n) {
                if ( !i || !j || matrix[i][j] == '0') 
                    dp[i][j] = matrix[i][j] - '0';
                else 
                    dp[i][j] = min( dp[ i - 1 ][ j - 1 ], min(dp[ i - 1 ][ j ], dp[ i ][ j - 1 ])) + 1;
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};
```
