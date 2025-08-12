# 📝 Penjelasan Fungsi `Lexicographically Largest Palindromic Subsequence` - Codeforces 202A

Fungsi ini digunakan untuk mencari subsekuensi palindromik terbesar secara leksikografis dari string s.

## ❓ Soal

[Link Soal](https://codeforces.com/problemset/problem/202/A)
Inti soal: Diberikan string s, cari subsekuensi palindromik terbesar secara leksikografis. Output satu string hasilnya.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode mencari karakter terbesar pada string, lalu membentuk subsekuensi palindromik dengan karakter tersebut sebanyak kemunculannya.

## 💡 Inti

Inti kode: Cari karakter terbesar, ambil semua kemunculannya, hasilnya pasti palindrom dan leksikografis terbesar.

## ⚙️ Cara kerja

Bayangkan string sebagai deretan huruf. Cari huruf paling besar, ambil semua yang sama, hasilnya pasti palindrom dan paling besar secara urutan kamus.

## 📦 Contoh

- Input: abacaba
- Proses: Huruf terbesar = c, ambil semua c → "cc"
- Output: cc

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Iterasi satu kali untuk mencari karakter terbesar dan menghitung kemunculannya.

### 🗂️ Space Complexity = `O(n)`

Menyimpan hasil subsekuensi dalam string baru.

## 💻 Code

```cpp []
class Solution {
public:
    void lexicographicallyLargestPalindromicSubsequence(string& s) {
        if (s[0] == s.size() - 1) return;
        sort(s.begin(), s.end());
        s = s.substr(lower_bound(s.begin(), s.end(), s[s.size() - 1]) - s.begin(), s[s.size() - 1]);
        //           ^                                                             ^
        //  Take the position of the same letter as the end of the string        End of the string
    }
};
```
