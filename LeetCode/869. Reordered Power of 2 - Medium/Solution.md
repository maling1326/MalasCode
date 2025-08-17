# 📝 Penjelasan Fungsi `reorderedPowerOf2` - Leetcode `869. Reordered Power of 2`

Fungsi `reorderedPowerOf2` digunakan untuk menentukan apakah digit dari angka `n` bisa diacak ulang sehingga membentuk sebuah bilangan yang merupakan pangkat dua.

## ❓ Soal

Diberikan sebuah bilangan bulat `n`, tentukan apakah mungkin mengacak ulang digit-digitnya (tanpa leading zero) sehingga membentuk bilangan pangkat dua.

[Link Soal](https://leetcode.com/problems/reordered-power-of-2/description/?envType=daily-question&envId=2025-08-16)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini membandingkan frekuensi digit dari `n` dengan semua bilangan pangkat dua yang memiliki jumlah digit sama. Jika ada satu pangkat dua yang digitnya bisa diacak menjadi `n`, maka return `true`.

## 💡 Inti

Inti dari kode ini adalah membandingkan jumlah kemunculan setiap digit antara `n` dan semua pangkat dua yang panjang digitnya sama.

## ⚙️ Cara kerja

1. Hitung frekuensi setiap digit pada `n` dan simpan di array `num`.
2. Cari pangkat dua terkecil yang jumlah digitnya sama dengan `n`.
3. Untuk setiap pangkat dua dengan jumlah digit sama:
   - Hitung frekuensi digitnya.
   - Bandingkan dengan frekuensi digit `n`.
   - Jika sama persis, return `true`.
4. Jika tidak ada yang cocok, return `false`.

## 📦 Contoh

- Input: `n = 46`
  - Digit bisa diacak menjadi `64` (pangkat dua), return `true`.
- Input: `n = 65`
  - Tidak ada kombinasi digit yang membentuk pangkat dua, return `false`.

## 📊 Complexity

### ⏱️ Time Complexity = `O(k * d)`

`k` adalah jumlah pangkat dua yang dicek (maksimal 30), `d` adalah jumlah digit (maksimal 10). Setiap pangkat dua dibandingkan digitnya dengan `n`.

### 🗂️ Space Complexity = `O(1)`

Menggunakan array tetap untuk menghitung frekuensi digit.

## 💻 Code

```cpp []
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        bool equal = false;              // Flag to check if digit frequency matches

        vi num(10);                      // Vector to store digit counts of n (digits 0-9)
        string ns = to_string(n);        // Convert integer n to string to process each digit
        each(it, ns) num[it - '0']++;    // Count how many times each digit appears in n

        // Find the smallest power of two with the same number of digits as n
        int fls = ceil(log2(pow(10, (int)ns.size() - 1)));  
        ll p2 = pow(2, fls);             // Calculate 2^fls

        // Check all powers of two with same digit length as n
        while (to_string(p2).length() == ns.length()) {
            string p2s = to_string(p2);      // Convert current power of two to string

            auto temp = num;                 // Make a copy of original digit counts of n
            each(it, p2s) temp[it - '0']--;  // Subtract digits of current power of two

            // Assume digits match unless found otherwise
            equal = true;
            each(it, temp) {

                // If any digit count not zero, digits don't match
                if (it != 0) {
                    equal = false;
                    break;
                }
            }
            // If digits match exactly, return true
            if (equal) return true;

            // Otherwise, check next higher power of two
            fls++;
            p2 = pow(2, fls);
        }

        // No powers of two with matching digits found
        return false;
    }
}
```
