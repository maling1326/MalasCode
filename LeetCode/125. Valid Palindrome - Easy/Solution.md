# 📝 Penjelasan Fungsi `isPalindrome` - Leetcode `125. Valid Palindrome`

Fungsi `isPalindrome` digunakan untuk mengecek apakah string `s` adalah palindrome setelah mengabaikan karakter non-alfanumerik dan mengubah semua huruf menjadi huruf kecil.

## ❓ Soal

Diberikan string `s`, cek apakah setelah diubah menjadi huruf kecil dan menghapus semua karakter non-alfanumerik, string tersebut adalah palindrome (sama dibaca dari depan dan belakang).

[Link Soal](https://leetcode.com/problems/valid-palindrome/description/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini menghapus semua karakter non-alfanumerik dari string, mengubah semua huruf menjadi huruf kecil, lalu membandingkan dua bagian string untuk memastikan apakah palindrome.

## 💡 Inti

Inti dari kode ini adalah normalisasi string (hapus non-alfanumerik dan lowercase), lalu cek apakah dua bagian string sama setelah dibalik.

## ⚙️ Cara kerja

1. Hapus semua karakter non-alfanumerik dari string `s`.
2. Ubah semua huruf di `s` menjadi huruf kecil.
3. Balikkan setengah bagian belakang string.
4. Bandingkan setengah bagian depan dan belakang string.
5. Jika sama, return `true`; jika tidak, return `false`.

## 📦 Contoh

- Input: `s = "A man, a plan, a canal: Panama"`
  - Setelah normalisasi: `"amanaplanacanalpanama"`
  - Bagian Kiri -> `"amanaplana"`
  - Bagian Kanan > `"analpanama"`, di Reverse --> `"amanaplana"`
  - Palindrome, output: `true`
- Input: `s = "race a car"`
  - Setelah normalisasi: `"raceacar"`
  - Bukan palindrome, output: `false`
- Input: `s = " "`
  - Setelah normalisasi: `""`
  - Palindrome, output: `true`

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Setiap karakter hanya diproses beberapa kali (hapus, ubah, balik, bandingkan).

### 🗂️ Space Complexity = `O(n)`

Menggunakan string hasil normalisasi yang bisa sebesar input.

## 💻 Code

```cpp []
class Solution {
public:
    bool isPalindrome(string s) {
        s.erase (remove_if (s.begin(), s.end(), [](char c){          return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return  tolower(c); });
        reverse ( s.begin() + s.size() / 2, s.end()); 
        return s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size() / 2);
    }
};
```
