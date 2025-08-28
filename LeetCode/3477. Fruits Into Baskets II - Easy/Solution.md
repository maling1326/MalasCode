# 📝 Penjelasan Fungsi `numOfUnplacedFruits` - Leetcode `3477. Fruits Into Baskets II`

Fungsi `numOfUnplacedFruits` digunakan untuk menghitung berapa banyak jenis buah yang tidak bisa ditempatkan ke keranjang sesuai aturan kapasitas.

## ❓ Soal

Diberikan dua array: `fruits` (jumlah tiap jenis buah) dan `baskets` (kapasitas tiap keranjang). Setiap buah harus ditempatkan ke keranjang paling kiri yang kapasitasnya cukup dan setiap keranjang hanya bisa dipakai satu kali. Hitung berapa jenis buah yang tidak bisa ditempatkan.

[Link Soal](https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-28)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini mencoba menempatkan setiap buah ke keranjang paling kiri yang kapasitasnya cukup, dan menghapus keranjang yang sudah terpakai. Jika tidak ada keranjang yang cukup, buah dihitung sebagai unplaced.

## 💡 Inti

Inti dari kode ini adalah iterasi setiap buah, mencari keranjang pertama yang cukup, lalu menghapus keranjang tersebut agar tidak dipakai lagi.

## ⚙️ Cara kerja

1. Inisialisasi variabel `sum` untuk menghitung buah yang tidak bisa ditempatkan.
2. Iterasi setiap buah dari kiri ke kanan:
   - Untuk setiap buah, cek satu per satu keranjang dari kiri.
   - Jika ada keranjang yang kapasitasnya cukup, hapus keranjang tersebut dan lanjut ke buah berikutnya.
   - Jika tidak ada keranjang yang cukup, tambahkan `sum`.
3. Setelah semua buah diproses, return `sum`.

## 📦 Contoh

- Input: `fruits = [4,2,5]`, `baskets = [3,5,4]`
  - 4 → keranjang 5 (hapus 5)
  - 2 → keranjang 3 (hapus 3)
  - 5 → tidak ada keranjang cukup (keranjang tersisa 4)
  - Output: 1

- Input: `fruits = [3,6,1]`, `baskets = [6,4,7]`
  - 3 → keranjang 6 (hapus 6)
  - 6 → keranjang 7 (hapus 7)
  - 1 → keranjang 4 (hapus 4)
  - Output: 0

## 📊 Complexity

### ⏱️ Time Complexity = `O(n^2)`

Karena untuk setiap buah bisa saja mengecek semua keranjang yang tersisa.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan struktur data tambahan selain variabel penghitung.

## 💻 Code

```cpp []
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int sum = 0;
        for (auto buah = fruits.begin(); buah != fruits.end();) {
            bool dimasukkan = false;
            for (auto keranjang = baskets.begin(); keranjang != baskets.end(); ++keranjang)
                if (*buah <= *keranjang) {
                    keranjang = baskets.erase(keranjang);
                    dimasukkan = true;
                    break;
                }
            buah = fruits.erase(buah);
            if (!dimasukkan) sum++;
        }
        return sum;
    }
};
```
