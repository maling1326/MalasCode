# Penjelasan Fungsi `lengthOfLongestSubstring` - Leetcode `3`

Fungsi ini bertujuan untuk mencari panjang substring terpanjang dari sebuah string s yang tidak mengandung karakter yang sama (tidak ada karakter yang berulang).

## Cara kerja

Fungsi menggunakan pendekatan sliding window dengan membangun substring ans yang selalu berisi karakter unik.

- Iterasi setiap karakter dalam string s.
- Cek apakah karakter saat ini sudah ada di substring ans.
- Jika ada, hapus semua karakter dari awal substring sampai karakter yang sama tersebut agar substring tetap unik.
- Tambahkan karakter saat ini ke substring ans.
- Update panjang maksimum substring unik yang ditemukan (high).
- Setelah iterasi selesai, nilai high adalah panjang substring unik terpanjang.

## Contoh

Misal input: "abcabcbb"

- Iterasi karakter 'a', ans = "a", high = 1.
- Karakter 'b', ans = "ab", high = 2.
- Karakter 'c', ans = "abc", high = 3.
- Karakter 'a' ditemukan lagi, hapus sampai 'a' sebelumnya → ans = "bc", lalu tambah 'a' → ans = "bca".
- Lanjutkan proses serupa hingga akhir string.
- Hasil akhir high = 3 karena substring terpanjang tanpa karakter berulang adalah "abc".

## Inti

- Menyimpan substring unik sementara di ans.
- Menghapus bagian awal substring saat karakter duplikat ditemukan.
- Memperbarui panjang maksimum substring unik.

## Complexity

### Time Complexity = `O(n²)`

Pada kasus terburuk, operasi find dan erase pada string ans dapat memakan waktu linear terhadap panjang substring, sehingga totalnya bisa mencapai `O(n²)` untuk string berukuran n.

### Space Complexity = `O()`

Penyimpanan substring sementara ans bisa sebesar panjang string input pada kasus terburuk (semua karakter unik).

## Code

```cpp []
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string ans = "";
        int high = 0;

        for (int i = 0; i < s.size(); i++) {
            size_t pos = ans.find(s[i]);       // Cari karakter s[i] di substring ans
            if (pos != string::npos) {
                ans.erase(0, pos + 1);         // Hapus karakter dari awal sampai karakter duplikat
            }
            ans.push_back(s[i]);               // Tambahkan karakter baru ke substring
            if (ans.size() >= high)            // Update panjang maksimum jika perlu
                high = ans.size();
        }

        return high;
    }
};
```
