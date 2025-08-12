# Penjelasan Fungsi `longestCommonPrefix` - Leetcode `14`

Fungsi longestCommonPrefix digunakan untuk mencari prefix terpanjang yang sama dari semua string dalam sebuah vector.

## Cara kerja

- Fungsi mengambil string pertama sebagai acuan.
- Iterasi setiap karakter dari string pertama.
- Untuk setiap karakter, cek apakah karakter tersebut sama pada posisi yang sama di semua string lain.
- Jika ditemukan karakter yang berbeda atau posisi melebihi panjang string lain, fungsi langsung mengembalikan prefix hingga posisi tersebut.
- Jika semua karakter cocok hingga akhir string pertama, fungsi mengembalikan string pertama sebagai prefix terpanjang.

## Contoh

- Input: ["`flower`", "`flow`", "`flight`"]
- Proses:
  - Cek karakter ke-0: '`f`' sama di semua string.
  - Cek karakter ke-1: '`l`' sama di semua string.
  - Cek karakter ke-2: '`o`' pada "`flower`" dan "`flow`", tapi '`i`' pada "`flight`" berbeda.
- Output: "`fl`"

## Inti

- Bandingkan karakter per karakter pada semua string berdasarkan string pertama.____
- Hentikan saat ketidaksesuaian ditemukan dan kembalikan substring prefix.

## Complexity

### Time Complexity = `O(n + m)`

n adalah jumlah string, m adalah panjang string pertama (atau prefix terpanjang). Karena setiap karakter dari string pertama dicek terhadap semua string lain.

### Space Complexity = `O(m)`

Menggunakan ruang untuk menyimpan substring prefix terpanjang, maksimal sepanjang string pertama.

## Code

```cpp []
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Loop setiap karakter pada string pertama
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];  // Ambil karakter ke-i dari string pertama
            
            // Cek karakter ke-i pada semua string lain
            for (int j = 0; j < strs.size(); j++) {
                // Jika indeks i melebihi panjang string ke-j atau karakter berbeda
                if (i >= strs[j].size() || strs[j][i] != c)
                    // Kembalikan prefix sampai sebelum karakter ke-i
                    return strs[0].substr(0, i);
            }
        }
        
        // Jika semua karakter cocok sampai akhir string pertama, kembalikan string pertama
        return strs[0];
    }
};
```
