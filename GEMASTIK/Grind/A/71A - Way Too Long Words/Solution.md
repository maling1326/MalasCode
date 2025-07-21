# 📝 Penjelasan Fungsi `LongWords` - Leetcode `71A`

Fungsi ini digunakan untuk mengubah kata yang terlalu panjang menjadi bentuk singkat sesuai aturan soal.

## ❓ Soal

[Link Soal](https://codeforces.com/problemset/problem/71/A)
Inti soal: Jika kata lebih dari 10 karakter, ubah jadi singkatan: huruf pertama + jumlah huruf di tengah + huruf terakhir. Kata ≤10 karakter tetap.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode melakukan iterasi pada setiap kata, jika panjangnya >10 maka diubah jadi singkatan sesuai aturan, jika tidak tetap.

## 💡 Inti

Inti kode: Cek panjang kata, jika >10 ubah jadi singkatan, jika tidak tetap.

## ⚙️ Cara kerja

Bayangkan kata sebagai barisan huruf. Jika terlalu panjang, ambil huruf pertama dan terakhir, hitung jumlah huruf di tengah, lalu gabungkan jadi singkatan.

## 📦 Contoh

- Input: localization
- Proses: l + 10 + n → l10n
- Output: l10n

- Input: word
- Proses: Panjang ≤10, tetap
- Output: word

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Iterasi satu kali untuk setiap kata.

### 🗂️ Space Complexity = `O(n)`

Menyimpan hasil kata dalam vector.

## 💻 Code

```cpp
vector<string> txt (max);
for (int i = 0; i < (max); ++i) {
    input (txt[i]);
    if (txt[i].size() <= 10) continue;
    
    txt[i] = txt[i][0] + to_string(txt[i].size() - 2) + txt[i][txt[i].size() - 1];
}
```
