# 📝 Penjelasan Fungsi `Plus One` - Leetcode 66

Fungsi ini digunakan untuk menambah satu pada bilangan besar yang direpresentasikan dalam bentuk array digit.

## ❓ Soal

[Link Soal](https://leetcode.com/problems/plus-one/?envType=problem-list-v2&envId=math)
Inti soal: Diberikan array digit yang membentuk bilangan besar, tambahkan satu dan kembalikan hasilnya dalam bentuk array digit.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode melakukan penambahan satu dari digit paling belakang, menangani carry jika ada, dan menambah digit baru jika perlu.

## 💡 Inti

Inti kode: Tambah satu ke digit terakhir, propagasi carry ke depan jika perlu.

## ⚙️ Cara kerja

Bayangkan array digit seperti angka pada kalkulator. Tambahkan satu ke digit paling kanan, jika jadi 10, set ke 0 dan tambahkan satu ke digit di kiri, ulangi jika perlu.

## 📦 Contoh

- Input: [1,2,3] → Output: [1,2,4]
- Input: [4,3,2,1] → Output: [4,3,2,2]
- Input: [9] → Output: [1,0]

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Iterasi maksimal sebanyak jumlah digit.

### 🗂️ Space Complexity = `O(n)`

Hasil array bisa bertambah satu digit jika ada carry di digit paling depan.

## 💻 Code

```cpp []
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        scope ("Function");
        if (digits[digits.size() - 1] != 9)
            digits[digits.size() - 1] += 1;
        else {
            int i = digits.size() - 1;
            do {
                scope("While");
                debug(digits, i, digits[i]);
                digits[i] = 0;
                if (i > 0)
                    digits[i - 1] += 1;
                else {
                    digits.insert(digits.begin(), 1);
                    debug(digits);
                    break;
                }
                i--;
            } while (digits[i] == 10);
        }

        return digits;
    }
};
```
