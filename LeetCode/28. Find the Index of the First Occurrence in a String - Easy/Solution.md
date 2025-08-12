# Penjelasan Fungsi `strStr` - Leetcode `28`

Fungsi strStr ini digunakan untuk mencari posisi kemunculan pertama sebuah substring (needle) di dalam string lain (haystack). Jika substring ditemukan, fungsi mengembalikan indeks posisi pertama kemunculannya, jika tidak ditemukan mengembalikan -1. Fungsi ini merupakan solusi untuk soal Leetcode nomor 28, yaitu "Implement strStr()".

## Cara kerja

Fungsi menggunakan metode find dari kelas std::string untuk mencari substring needle di dalam string haystack mulai dari indeks 0.

- Jika find menemukan substring, ia mengembalikan indeks posisi pertama substring tersebut.
- Jika tidak ditemukan, find mengembalikan nilai khusus std::string::npos. Fungsi kemudian memeriksa hasil find:
- Jika bukan npos, kembalikan indeks tersebut.
- Jika npos, kembalikan -1 sebagai tanda substring tidak ditemukan.

## Contoh

Misalkan:

- Input: haystack = "hello", needle = "ll"
- Proses: Fungsi mencari "ll" dalam "hello" dan menemukan mulai indeks 2.
- Output: 2

Jika:

- Input: haystack = "aaaaa", needle = "bba"
- Proses: Fungsi mencari "bba" dalam "aaaaa" tapi tidak ditemukan.
- Output: -1

## Inti

Inti dari kode ini adalah pemanfaatan fungsi std::string::find untuk mencari substring dan pengecekan hasilnya untuk menentukan nilai yang dikembalikan.

## Complexity

### Time Complexity = `O()`

- n adalah panjang string haystack

- m adalah panjang string needle

    Metode find dalam implementasi standar biasanya menggunakan algoritma pencarian substring sederhana yang dalam kasus terburuk bisa mencapai O(n*m).

### Space Complexity = `O()`

- Fungsi menggunakan ruang tambahan konstan, hanya variabel val untuk menyimpan hasil pencarian.

## Code

```cpp []
class Solution {
public:
    int strStr(string haystack, string needle) {
        // Cari posisi pertama kemunculan substring 'needle' di 'haystack'
        size_t val = haystack.find(needle, 0);

        // Jika ditemukan, kembalikan indeksnya
        if (val != std::string::npos)
            return val;
        else
            // Jika tidak ditemukan, kembalikan -1
            return -1;
    }
};
```
