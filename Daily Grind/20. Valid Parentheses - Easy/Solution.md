# 📝 Penjelasan Fungsi `Valid Parentheses` - Leetcode 20

Fungsi ini digunakan untuk memeriksa apakah string berisi tanda kurung buka/tutup valid sesuai aturan.

## ❓ Soal

[Link Soal](https://leetcode.com/problems/valid-parentheses/description/)
Inti soal: Diberikan string s berisi karakter '(', ')', '{', '}', '[', ']'. String valid jika setiap kurung buka ditutup oleh kurung yang sama dan urutannya benar.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode menggunakan stack untuk menyimpan kurung buka. Setiap kurung tutup dicek apakah sesuai dengan kurung buka terakhir. Jika urutan dan tipe kurung sesuai, string valid.

## 💡 Inti

Inti kode: Gunakan stack untuk cek urutan dan tipe kurung buka/tutup.

## ⚙️ Cara kerja

Bayangkan stack sebagai tumpukan piring. Setiap kurung buka ditumpuk, kurung tutup harus cocok dengan piring paling atas. Jika cocok, diambil dari tumpukan. Jika tidak, string tidak valid.

## 📦 Contoh

- Input: s = "()" → Output: true
- Input: s = "()[]{}" → Output: true
- Input: s = "(]" → Output: false
- Input: s = "([])" → Output: true

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Melakukan satu kali iterasi pada seluruh karakter string.

### 🗂️ Space Complexity = `O(n)`

Menggunakan stack untuk menyimpan kurung buka.

## 💻 Code

```cpp []
class Solution {
public:
    bool isValid(string s) {
        stack<char> ch;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                ch.push(c);
            else {
                if (ch.empty()) return false;
                if ((ch.top() != '[' && c == ']')
                 || (ch.top() != '{' && c == '}')
                 || (ch.top() != '(' && c == ')'))
                    return false;
                ch.pop();
            }
        }
        return ((ch.empty()) ? true : false);
    }
};
```
