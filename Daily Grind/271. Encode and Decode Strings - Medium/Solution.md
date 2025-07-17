# Penjelasan Fungsi `encode` dan `decode` - Leetcode 271

Fungsi `encode` digunakan untuk menggabungkan beberapa string menjadi satu string dengan menambahkan delimiter khusus ("0xE") di akhir setiap string. Fungsi `decode` digunakan untuk memisahkan kembali string gabungan tersebut menjadi vector string sesuai delimiter.

## Cara kerja

Pada fungsi `encode`, setiap string pada vector akan digabungkan dan diakhiri dengan "0xE" sebagai penanda akhir string. Pada fungsi `decode`, string gabungan akan di-scan dan dipotong setiap kali ditemukan "0xE", lalu hasil potongan dimasukkan ke vector.

## Contoh

Contoh:

- Input: ["hello", "world"]
- Setelah encode: "hello0xEworld0xE"
- Setelah decode: ["hello", "world"]

## Inti

Inti kode: Menyisipkan delimiter unik untuk menggabungkan dan memisahkan string agar dapat di-encode dan decode dengan mudah.

## Complexity

### Time Complexity = `O(n)`

Encode dan decode melakukan iterasi pada seluruh karakter string, sehingga kompleksitas waktu adalah `O(n)`, dengan n adalah total panjang semua string.

### Space Complexity = `O(n)`

Membutuhkan ruang sebesar total panjang string gabungan dan vector hasil decode, sehingga kompleksitas ruang `O(n)`.

## Code

```cpp []
class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (string s : strs)
            ans += s + "0xE";
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int awal = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(i, 3) == "0xE") {
                ans.push_back(s.substr(awal, i - awal));
                awal = i + 3;
            }
        }
        return ans;
    }
};
```
