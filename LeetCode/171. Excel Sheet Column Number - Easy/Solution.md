# 📝 Penjelasan Fungsi `Excel Sheet Column Number` - Leetcode 171

Fungsi ini digunakan untuk mengubah judul kolom Excel (misal: "AB") menjadi nomor kolom yang sesuai.

## ❓ Soal

[Link Soal](https://leetcode.com/problems/excel-sheet-column-number/description/?envType=problem-list-v2&envId=math)
Inti soal: Diberikan string judul kolom Excel, ubah ke nomor kolom sesuai urutan (A=1, Z=26, AA=27, dst).

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode mengubah setiap huruf menjadi angka (A=1, B=2, ...), lalu menghitung nilainya seperti sistem bilangan basis 26.

## 💡 Inti

Inti kode: Konversi string ke angka dengan basis 26, setiap huruf mewakili satu digit.

## ⚙️ Cara kerja

Bayangkan judul kolom seperti angka di sistem bilangan basis 26, tiap huruf adalah digit, lalu dijumlahkan sesuai posisinya.

## 📦 Contoh

- Input: "A" → Output: 1
- Input: "AB" → Output: 28
- Input: "ZY" → Output: 701

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Iterasi satu kali untuk setiap karakter pada string.

### 🗂️ Space Complexity = `O(1)`

Menggunakan variabel penampung hasil saja.

## 💻 Code

```cpp []
class Solution {
public:
    int titleToNumber(string x) {
        int ans {0};

        for (int i = x.length() - 1; i >= 0; --i)
            ans += (x[i] - 'A' + 1) * pow(26, x.length() - 1 - i);

        return ans;
    }
};
```
