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

## Complexity

### Time Complexity = `O(n)`

- Ada satu loop yang jalan dari awal sampai akhir string word, jadi iterasi sebanyak n kali (n = panjang string).
- Di setiap iterasi cuma cek apakah karakter sekarang sama dengan karakter sebelumnya, lalu tambah result kalau sama — operasi ini cepat banget, O(1).
- Jadi total waktu yang dibutuhkan adalah `O(n)`, artinya waktu berjalan sebanding dengan panjang string.

### Space Complexity = `O(1)` (konstan)

- Fungsi cuma pakai beberapa variabel sederhana (int result, char behind), yang ukurannya tetap dan gak tergantung panjang string.
- Tidak ada struktur data tambahan yang dibuat selama proses.
- Jadi penggunaan memori adalah `O(1)` alias konstan.

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
