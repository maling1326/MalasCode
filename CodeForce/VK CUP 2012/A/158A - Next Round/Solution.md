# 📝 Penjelasan Fungsi `nextRound` - Codeforces `158A - Next Round`

Fungsi `nextRound` digunakan untuk menghitung jumlah peserta yang lolos ke babak berikutnya berdasarkan skor minimal peserta di posisi ke-k dan hanya jika skornya positif.

## ❓ Soal

Diberikan skor peserta kontes dalam urutan menurun dan dua angka `n` (jumlah peserta) serta `k` (posisi penentu). Hitung berapa peserta yang skornya minimal sama dengan peserta di posisi ke-k dan lebih dari nol.

[Link Soal](https://codeforces.com/problemset/problem/158/A)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini membaca skor peserta satu per satu, menentukan skor minimal dari peserta di posisi ke-k, lalu menghitung berapa peserta yang skornya memenuhi syarat untuk lolos.

## 💡 Inti

Inti dari kode ini adalah membandingkan setiap skor dengan skor peserta di posisi ke-k dan memastikan skornya positif.

## ⚙️ Cara kerja

1. Inisialisasi `min_score` dan `sum` ke 0.
2. Iterasi sebanyak `m` (jumlah peserta).
3. Pada setiap iterasi, baca skor peserta.
4. Jika peserta adalah posisi ke-l, simpan skornya sebagai `min_score`.
5. Jika skor peserta kurang dari `min_score` atau skor <= 0, langsung return jumlah peserta yang lolos (`sum`).
6. Jika lolos, tambahkan `sum`.
7. Setelah selesai, return `sum`.

## 📦 Contoh

- Input: `8 5` dan skor `10 9 8 7 7 7 5 5`
  - Skor minimal posisi ke-5 adalah 7.
  - Peserta dengan skor >= 7 dan > 0 ada 6 orang.
  - Output: `6`
- Input: `4 2` dan skor `0 0 0 0`
  - Skor minimal posisi ke-2 adalah 0.
  - Tidak ada peserta dengan skor > 0.
  - Output: `0`

## 📊 Complexity

### ⏱️ Time Complexity = `O(m)`

Iterasi sebanyak jumlah peserta.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan memori tambahan.

## 💻 Code

```cpp []
class Solution {
public:
    int nextRound(int m, int l) {
        int min_score {0}, sum {0};
        rep(i, m) {
            int temp = (input(temp), temp);
            if (i + 1 == l)                    min_score = temp;
            if (temp < min_score || temp <= 0) return sum;
            sum++;
        }
        return sum;
    }
};
```
