# 📝 Penjelasan Fungsi `Evaluate Reverse Polish Notation` - Leetcode 150

Fungsi ini digunakan untuk menghitung hasil ekspresi aritmatika dalam notasi Polandia Balik (postfix) menggunakan stack.

## ❓ Soal

[Link Soal](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=problem-list-v2&envId=math)
Inti soal: Diberikan array string token notasi Polandia Balik, hitung hasil ekspresi aritmatika tersebut.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode menggunakan stack untuk menyimpan operand. Jika token operator, ambil dua operand teratas, lakukan operasi, lalu push hasilnya ke stack. Ulangi hingga selesai.

## 💡 Inti

Inti kode: Stack digunakan untuk menyimpan angka, operator mengambil dua angka teratas, hasilnya dimasukkan kembali ke stack.

## ⚙️ Cara kerja Step-by-Step

1. Inisialisasi stack kosong untuk menyimpan angka.
2. Lakukan iterasi untuk setiap token dalam array:
   - Jika token adalah angka, ubah ke integer dan push ke stack.
   - Jika token adalah operator (+, -, *, /):
     - Pop dua angka teratas dari stack (b dan a).
     - Lakukan operasi sesuai operator: a + b, a - b, a * b, atau a / b.
     - Push hasil operasi ke stack.
3. Setelah semua token diproses, nilai paling atas di stack adalah hasil akhir ekspresi dan dikembalikan.

## 📦 Contoh

- ["2","1","+","3","*"]
  - Proses: 2 dan 1 masuk stack, + → 3, 3 masuk stack, * → 9
  - Output: 9

- ["4","13","5","/","+"]
  - Proses: 4 masuk stack, 13 dan 5 masuk stack, / → 2, + → 6
  - Output: 6

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Setiap token diproses satu kali.

### 🗂️ Space Complexity = `O(n)`

Stack maksimal berisi seluruh operand.

## 💻 Code

```cpp []
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string c : tokens) {
            if (c != "+" && c != "-" && c != "*" && c != "/")
                s.push(stoi(c));
            else if (c == "+") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a + b);
            }
            else if (c == "-") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a - b);
            }
            else if (c == "*") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a * b);
            }
            else if (c == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a / b);
            }
        }
        return s.top();
    }
};
```
