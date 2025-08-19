# 📝 Penjelasan Fungsi `zeroFilledSubarray` - Leetcode `2348. Number of Zero-Filled Subarrays`

Fungsi `zeroFilledSubarray` digunakan untuk menghitung jumlah subarray yang seluruh elemennya adalah nol pada array `nums`.

## ❓ Soal

Diberikan array integer `nums`, hitung berapa banyak subarray (kontigu, minimal 1 elemen) yang seluruh elemennya bernilai 0.

[Link Soal](https://leetcode.com/problems/number-of-zero-filled-subarrays/description/?envType=daily-question&envId=2025-08-19)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini menghitung secara efisien jumlah subarray nol dengan cara menghitung panjang berturut-turut angka nol, lalu menjumlahkan semua kemungkinan subarray nol dari setiap rangkaian nol tersebut.

## 💡 Inti

Inti dari kode ini adalah: untuk setiap deret nol berturut-turut sepanjang `n`, jumlah subarray nol yang bisa dibentuk adalah `n * (n + 1) / 2`.

## ⚙️ Cara kerja

1. Inisialisasi dua variabel: `zrs` untuk menghitung panjang deret nol berturut-turut, dan `sum` untuk total subarray nol.
2. Iterasi setiap elemen di `nums`:
   - Jika elemen adalah nol, tambah `zrs`.
   - Jika bukan nol, tambahkan hasil `zrs * (zrs + 1) / 2` ke `sum`, lalu reset `zrs` ke 0.
3. Setelah iterasi, jika masih ada deret nol di akhir, tambahkan juga ke `sum`.
4. Return `sum` sebagai hasil akhir.

## 📦 Contoh

- Input: `nums = [1,3,0,0,2,0,0,4]`
  - Deret nol pertama: dua nol → subarray: `[0]`, `[0]`, `[0,0]` → 3
  - Deret nol kedua: dua nol → subarray: `[0]`, `[0]`, `[0,0]` → 3
  - Total: 6

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Hanya satu kali iterasi seluruh elemen array.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan struktur data tambahan, hanya variabel penghitung.

## 💻 Code

```cpp []
using ll            = long long;
#define each(it, v)   for(auto& it : v)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll zrs {0}, sum {0};

        each(it, nums) {
            if (it == 0) ++ zrs;
            else    {sum += zrs * (zrs + 1) / 2; zrs = 0;}
        }

        if (zrs > 0) sum += zrs * (zrs + 1) / 2;
        return sum;
    }
};
```
