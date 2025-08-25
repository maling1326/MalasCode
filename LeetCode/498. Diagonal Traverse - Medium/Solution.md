# 📝 Penjelasan Fungsi `findDiagonalOrder` - Leetcode `498. Diagonal Traverse`

Fungsi `findDiagonalOrder` digunakan untuk mengembalikan seluruh elemen matriks `mat` dalam urutan diagonal zig-zag, dimulai dari kiri atas ke kanan bawah.

## ❓ Soal

Diberikan matriks `mat` berukuran m x n, kembalikan array berisi semua elemen matriks dalam urutan diagonal (zig-zag) dari kiri atas ke kanan bawah.

[Link Soal](https://leetcode.com/problems/diagonal-traverse/?envType=daily-question&envId=2025-08-25)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini menelusuri matriks secara diagonal, bergantian arah ke kanan-atas dan kiri-bawah, sesuai aturan traversal diagonal pada soal.

## 💡 Inti

Inti dari kode ini adalah menggunakan dua variabel indeks (`i`, `j`) dan flag arah (`isleft`) untuk bergerak secara zig-zag di dalam matriks, dan menambah elemen ke hasil setiap langkah.

## ⚙️ Cara kerja

1. Inisialisasi array hasil `arr` dan flag arah `isleft` (false = naik kanan, true = turun kiri).
2. Mulai dari posisi (0,0), selama indeks masih dalam batas matriks:
   - Tambahkan elemen `mat[i][j]` ke hasil.
   - Jika `isleft` (turun kiri):
     - Jika di baris terakhir, ubah arah ke kanan-atas dan geser kolom ke kanan.
     - Jika di kolom pertama, ubah arah ke kanan-atas dan geser baris ke bawah.
     - Jika tidak, geser kiri-bawah (`i++`, `j--`).
   - Jika bukan `isleft` (naik kanan):
     - Jika di kolom terakhir, ubah arah ke kiri-bawah dan geser baris ke bawah.
     - Jika di baris pertama, ubah arah ke kiri-bawah dan geser kolom ke kanan.
     - Jika tidak, geser kanan-atas (`i--`, `j++`).
3. Ulangi sampai seluruh elemen dimasukkan ke array hasil.
4. Return array hasil.

## 📦 Contoh

![example](example.jpg)

- Input: `mat = [[1,2,3],[4,5,6],[7,8,9]]`
  - Output: `[1,2,4,7,5,3,6,8,9]`
  - Step: Mulai dari (0,0), zig-zag diagonal hingga akhir matriks.
- Input: `mat = [[1,2],[3,4]]`
  - Output: `[1,2,3,4]`

## 📊 Complexity

### ⏱️ Time Complexity = `O(m * n)`

Setiap elemen matriks hanya diakses satu kali.

### 🗂️ Space Complexity = `O(m * n)`

Array hasil berisi seluruh elemen matriks.

## 💻 Code

```cpp []
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> arr;
        bool isleft = false;
        for (int i = 0, j = 0; i < size(mat) && j < size(mat[0]);) {
            arr.emplace_back(mat[i][j]);
            if (isleft) {
                if (i + 1 == size(mat)) {
                    isleft = false;
                    j++;
                }
                else if (j - 1 == -1) {
                    isleft = false;
                    i++;
                }
                else {j--; i++;}
            }
            else {
                if (j + 1 == size(mat[0])) {
                    isleft = true;
                    i++;
                }
                else if (i - 1 == -1) {
                    isleft = true;
                    j++;
                }
                else {i--; j++;}
            }
        }
        return arr;
    }
};
```
