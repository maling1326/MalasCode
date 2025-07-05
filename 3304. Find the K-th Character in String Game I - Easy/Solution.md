# Penjelasan Fungsi `kthCharacter` - Leetcode `3304`

Fungsi `kthCharacter` ini menghasilkan karakter ke-`k` dari sebuah string yang dibangun secara bertahap.  
String awalnya adalah "a", lalu setiap iterasi menambahkan karakter baru yang merupakan hasil menaikkan nilai ASCII dari karakter-karakter sebelumnya secara berulang.  
Tetapi dalam kelipatan pangkat dua, acuan akan kembali dari indeks 1 sampai angka sebelum memulai iterasi tersebut, sehingga pola penambahan karakter diulang dari awal secara berkala.

## Cara kerja

- Mulai dengan string `text = "a"`.
- Gunakan variabel `n` untuk melacak indeks karakter yang sedang diproses.
- Selama panjang string `text` kurang dari `k`, lakukan:
  - Jika `n` masih kurang dari batas `max` (panjang string sebelum penambahan terakhir), tambahkan karakter baru dengan menaikkan nilai ASCII dari `text[n]` sebanyak 1.
  - Naikkan `n` untuk proses karakter berikutnya.
  - Jika `n` sudah mencapai `max`, reset `n` ke 0 dan update `max` ke panjang string saat ini.
- Setelah panjang string mencapai atau melebihi `k`, ambil karakter ke-`k` (indeks `k-1`) dan kembalikan.

## Contoh

Example 1:

Input: `k = 5`

Output: `'b'`

Explanation:

- Awalnya, `word = "a"`.
- Operasi penambahan karakter dilakukan secara berulang:
  1. Generate karakter baru dari `word[0] = 'a'` → `'b'`, jadi `word = "ab"`.
  2. Generate karakter baru dari `word[0..1] = "ab"` → `'b'` dan `'c'`, jadi `word = "abbc"`.
  3. Generate karakter baru dari `word[0] = 'a'` (karena reset `n` ke 0) → `'b'`, jadi `word = "abbcb"`.
- Proses berhenti karena panjang `word` sudah sama dengan `k = 5`.
- Karakter ke-5 adalah `'b'`.

## Inti

- Bangun string dengan menambahkan karakter hasil menaikkan nilai ASCII dari karakter sebelumnya secara berulang.
- Lakukan sampai panjang string mencapai `k`.
- Ambil karakter ke-`k` dari string tersebut.

## Complexity

### Time Complexity = `O(k)`

Karena setiap iterasi menambahkan karakter ke string sampai panjangnya mencapai k, waktu yang dibutuhkan sekitar `O(k)`.

### Space Complexity = `O(k)`

Karena string text tumbuh sampai panjang k, memori yang dipakai juga `O(k)`.

## Code

```cpp []
class Solution {
public:
    char kthCharacter(int k) {
        string text = "a";            
        int n = 0, max = text.size();

        while (text.size() < k){
            if (n < max) {
                text.push_back((text[n] + 1));
                n++;
                continue;
            }

            n = 0;
            max = text.size();
        }
        
        return text[k - 1];
    }
};
```
