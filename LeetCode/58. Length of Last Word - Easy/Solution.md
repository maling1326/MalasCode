# 📝 Penjelasan Fungsi `lengthOfLastWord` - Leetcode `58. Length of Last Word`

Fungsi `lengthOfLastWord` digunakan untuk mencari panjang kata terakhir dari sebuah string `s` yang terdiri dari kata dan spasi.

## ❓ Soal

Diberikan string `s` yang terdiri dari kata dan spasi, kembalikan panjang kata terakhir (kata = kumpulan karakter non-spasi).

[Link Soal](https://leetcode.com/problems/length-of-last-word/submissions/1731342031/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Fungsi ini memproses string dari belakang, menghapus spasi di akhir, lalu menghitung panjang kata terakhir sebelum spasi berikutnya.

## 💡 Inti

Inti dari kode ini adalah menghapus spasi di akhir string, lalu menghitung jumlah karakter dari belakang hingga bertemu spasi.

## ⚙️ Cara kerja

1. Mulai iterasi dari indeks terakhir string `s`.
2. Jika karakter terakhir adalah spasi, hapus karakter tersebut (`s.pop_back()`).
3. Jika karakter saat ini adalah spasi, kembalikan panjang kata terakhir (`s.size() - i - 1`).
4. Jika tidak ada spasi ditemukan, kembalikan panjang string yang tersisa (`s.size()`).

## 📦 Contoh

- Input: `"Hello World"`
  - Step: Hapus spasi di akhir (tidak ada), hitung dari belakang hingga spasi, output `5`.
- Input: `"   fly me   to   the moon  "`
  - Step: Hapus spasi di akhir, hitung dari belakang hingga spasi, output `4`.
- Input: `"luffy is still joyboy"`
  - Step: Tidak ada spasi di akhir, hitung dari belakang hingga spasi, output `6`.

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Iterasi maksimal sebanyak panjang string.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan struktur data tambahan, hanya memodifikasi string input.

## 💻 Code

```cpp []
class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int i = s.size() - 1; i >= 0; --i) {
            debug(s, s[i], s.size(), i);
            if (s.back() == ' ')
                s.pop_back();
            else if (s[i] == ' ') 
                return s.size() - i - 1;
        }
        return s.size();
    }
};
```
