# Penjelasan Fungsi `romanToInt` - Leetcode `13`

Fungsi romanToInt mengubah sebuah string yang berisi angka Romawi menjadi nilai integer yang sesuai.

## Cara kerja

- Melakukan iterasi karakter demi karakter pada string input.
- Mengecek pasangan karakter khusus yang merepresentasikan angka seperti `CM`, `CD`, `XC`, dll.
- Jika ditemukan pasangan tersebut, tambahkan nilai khusus dan lompat satu indeks.
- Jika tidak, tambahkan nilai dari karakter tunggal sesuai angka Romawi.
- Teruskan hingga seluruh string diproses.

## Contoh

- Input: "`MCMXCIV`"
- Proses:
  - `M` → 1000
  - `CM` → 900 (lompat indeks)
  - `XC` → 90 (lompat indeks)
  - `IV` → 4 (lompat indeks)
- Output: 1994

## Inti

- Deteksi dan hitung pasangan angka Romawi dengan nilai khusus terlebih dahulu.
- Jika tidak ada pasangan, hitung nilai karakter tunggal.
- Gunakan indeks untuk melewati karakter yang sudah diproses.

## Complexity

### Time Complexity = `O(n)`

Iterasi satu kali sepanjang string dengan n karakter.

### Space Complexity = `O(1)`

Menggunakan variabel tetap tanpa struktur data tambahan yang bergantung pada input.

## Code

```cpp []
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'C' && s[i+1] == 'M')       // CM
                {sum += 900; i++;}
            else if (s[i] == 'C' && s[i+1] == 'D')  // CD
                {sum += 400; i++;}
            else if (s[i] == 'X' && s[i+1] == 'C')  // XC
                {sum += 90; i++;}
            else if (s[i] == 'X' && s[i+1] == 'L')  // XL
                {sum += 40; i++;}
            else if (s[i] == 'I' && s[i+1] == 'X')  // IX
                {sum += 9; i++;}
            else if (s[i] == 'I' && s[i+1] == 'V')  // IV
                {sum += 4; i++;}
            else if (s[i] == 'M')                   // M
                sum += 1000;
            else if (s[i] == 'D')                   // D
                sum += 500;
            else if (s[i] == 'C')                   // C
                sum += 100;
            else if (s[i] == 'L')                   // L
                sum += 50;
            else if (s[i] == 'X')                   // X
                sum += 10;
            else if (s[i] == 'V')                   // V
                sum += 5;
            else if (s[i] == 'I')                   // I
                sum += 1;
        }

        return sum;
    }
};
```
