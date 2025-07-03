# Penjelasan Fungsi `climbStairs` - Leetcode 70

Fungsi ini menghitung jumlah cara untuk naik tangga dengan `n` anak tangga,  
dengan aturan bisa naik 1 atau 2 anak tangga sekaligus.

## Cara kerja

- `x` dan `y` menyimpan jumlah cara ke dua langkah sebelumnya.
- Pada setiap iterasi, `result` dihitung sebagai jumlah cara ke langkah sekarang (`x + y`).
- Nilai `x` dan `y` kemudian digeser untuk iterasi berikutnya.
- Setelah `n` iterasi, `result` berisi jumlah cara naik ke anak tangga ke-`n`.

## Intinya

Fungsi ini menggunakan konsep deret Fibonacci secara iteratif untuk menyelesaikan masalah.

## Code

```cpp []

class Solution {
public:
    
    long long climbStairs(const int& n) 
    {
        // Inisialisasi awal
        long long result, x = 0, y = 1;
        
        // Hitung jumlah cara naik tangga ke-n (mirip Fibonacci)
        for (int i = 0; i < n; i++) {
            result = x + y;  // jumlah cara ke langkah sekarang
            x = y;           // geser nilai sebelumnya
            y = result;      // update nilai terbaru
        }
        
        return result;       // hasil akhir: jumlah cara naik ke anak tangga ke-n
    }
};
```
