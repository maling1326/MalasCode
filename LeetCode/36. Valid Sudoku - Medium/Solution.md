# 📝 Penjelasan Fungsi `isValidSudoku` - Leetcode `36. Valid Sudoku`

Fungsi `isValidSudoku` digunakan untuk memeriksa apakah papan Sudoku 9x9 valid, yaitu tidak ada angka yang sama pada baris, kolom, maupun kotak 3x3.

## ❓ Soal

Diberikan papan Sudoku 9x9, cek apakah papan tersebut valid. Setiap baris, kolom, dan kotak 3x3 tidak boleh ada angka 1-9 yang berulang. Hanya sel yang terisi yang perlu dicek.

[Link Soal](https://leetcode.com/problems/valid-sudoku/description/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini memanfaatkan tiga matriks untuk melacak kemunculan angka pada setiap baris, kolom, dan kotak 3x3. Jika ditemukan angka yang sama pada baris, kolom, atau kotak yang sama, maka Sudoku tidak valid.

## 💡 Inti

Inti dari kode ini adalah menggunakan array 2D untuk mencatat apakah angka tertentu sudah pernah muncul di baris, kolom, atau kotak 3x3 tertentu.

## ⚙️ Cara kerja

1. Inisialisasi tiga matriks 9x9: `col` untuk kolom, `row` untuk baris, dan `box` untuk kotak 3x3.
2. Iterasi setiap sel pada papan:
   - Jika sel kosong ('.'), lanjut ke sel berikutnya.
   - Hitung indeks angka (0-8) dari karakter.
   - Hitung indeks kotak 3x3 dengan rumus `((i / 3) * 3) + (j / 3)`.
   - Jika angka sudah pernah muncul di baris, kolom, atau kotak tersebut, return `false`.
   - Jika belum, tandai angka tersebut sudah muncul di baris, kolom, dan kotak.
3. Jika seluruh papan sudah dicek tanpa konflik, return `true`.

## 📦 Contoh

- Input:  
  
  ``` powershell
  [["5","3",".",".","7",".",".",".","."],
   ["6",".",".","1","9","5",".",".","."],
   [".",".","9","8",".",".",".","6","."],
   ["8",".",".",".","6",".",".",".","3"],
   ["4",".",".","8",".","3",".",".","1"],
   ["7",".",".",".","2",".",".",".","6"],
   [".","6",".",".",".",".","2","8","."],
   [".",".",".","4","1","9",".",".","5"],
   [".",".",".",".","8",".",".","7","9"]]
  ```

  Output: `true`
- Input:  

  ``` powershell
  [["8","3",".",".","7",".",".",".","."],
   ["6",".",".","1","9","5",".",".","."],
   [".",".","9","8",".",".",".","6","."],
   ["8",".",".",".","6",".",".",".","3"],
   ["4",".",".","8",".","3",".",".","1"],
   ["7",".",".",".","2",".",".",".","6"],
   [".","6",".",".",".",".","2","8","."],
   [".",".",".","4","1","9",".",".","5"],
   [".",".",".",".","8",".",".","7","9"]]
  ```

  Output: `false` (karena ada dua angka 8 di kotak kiri atas)

## 📊 Complexity

### ⏱️ Time Complexity = `O(81)`

Setiap sel pada papan (9x9) dicek satu kali.

### 🗂️ Space Complexity = `O(1)`

Menggunakan matriks 9x9 untuk tracking, tetap (konstan).

## 💻 Code

```cpp []
#define rep(i, n)     for(int i = 0; i < (n); ++i)
using vi                  = vector<int>;
using vvi                 = vector<vi>;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vvi col (9, vi(9, 0)),
            row (9, vi(9, 0)),
            box (9, vi(9, 0));
        rep(i, 9) {
            rep(j, 9) {
                if (board[i][j] != '.') {
                    int now = board[i][j] - '1',
                        cor = ((i / 3) * 3) + (j / 3);
                    if (col[j][now] == 1 or row[i][now] == 1 or box[cor][now] == 1)
                        return false;
                    col[j][now]++;
                    row[i][now]++;
                    box[cor][now]++;
                }
            }
        }
        return true;
    }
};
```
