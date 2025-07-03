# Penjelasan Fungsi `possibleStringCount` - Leetcode 3330

Fungsi ini menghitung jumlah kemungkinan string yang dapat dibentuk dari `word`  
dengan aturan: setiap karakter yang sama yang berurutan dapat dihitung sebagai pilihan tambahan.

## Cara kerja

- `result` mulai dari 1 sebagai jumlah minimal kemungkinan.
- Iterasi setiap karakter di `word`.
- Jika karakter saat ini sama dengan karakter sebelumnya (`behind`),  
  maka `result` ditambah 1 (menandakan pilihan tambahan).
- Update `behind` dengan karakter saat ini.
- Kembalikan `result` sebagai total kemungkinan.

## Contoh

Untuk `word = "aabb"`,  
karakter berulang adalah `a` dan `b`, sehingga `result` bertambah saat menemukan karakter yang sama berturut-turut.

## Inti

Menghitung jumlah kemungkinan berdasarkan kemunculan karakter berulang secara berurutan.

## Code

```cpp []

class Solution {
public:
    int possibleStringCount(string word) 
    {
        int n = word.size();
        if (n == 0) return 0;
        
        int result = 1;
        char behind = '\0';
        for (char c : word) 
        {
            if (c == behind)
                result++;
            behind = c;
        }

        return result;
    }
};

```
