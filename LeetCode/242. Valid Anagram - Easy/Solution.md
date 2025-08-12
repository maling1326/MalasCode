# Penjelasan Fungsi `isAnagram` - Leetcode 242

Fungsi `isAnagram` digunakan untuk menentukan apakah dua string merupakan anagram, yaitu memiliki karakter yang sama dengan jumlah yang sama, hanya urutannya yang berbeda.

## Cara kerja

Fungsi membandingkan panjang kedua string terlebih dahulu. Jika tidak sama, langsung return false. Kemudian, fungsi menghitung frekuensi setiap huruf pada string pertama dan menguranginya dengan frekuensi huruf pada string kedua. Jika ada huruf yang jumlahnya kurang dari nol, berarti string kedua memiliki huruf lebih banyak dari string pertama, sehingga bukan anagram.

## Contoh

Contoh:

- Input: s = "anagram", t = "nagaram"
- Proses: Hitung frekuensi huruf, semua sama
- Output: true

- Input: s = "rat", t = "car"
- Proses: Huruf 'c' tidak ada di s
- Output: false

## Inti

Inti kode: Menggunakan array untuk menghitung dan membandingkan frekuensi huruf dari kedua string.

## Complexity

### Time Complexity = `O(n)`

Karena hanya melakukan satu kali iterasi pada kedua string, kompleksitas waktu adalah O(n), dengan n adalah panjang string.

### Space Complexity = `O(1)`

Menggunakan array berukuran tetap (26 huruf alfabet), sehingga kompleksitas ruang adalah konstan O(1).

## Code

```cpp []
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int letter[26] = {0};

        for (char c : s) 
            letter[c - 'a']++;

        for (char c : t) {
            letter[c - 'a']--;
            if (letter[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
```
