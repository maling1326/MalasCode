# 📝 Penjelasan Fungsi `wordPattern` - Leetcode `290. Word Pattern`

Fungsi `wordPattern` digunakan untuk mengecek apakah string `s` mengikuti pola yang diberikan oleh string `pattern`, dengan aturan setiap karakter di `pattern` harus berkorespondensi satu-satu dengan kata unik di `s` (bijeksi).

## ❓ Soal

Diberikan string `pattern` dan string `s`, cek apakah `s` mengikuti pola `pattern` dengan aturan setiap karakter di `pattern` hanya bisa dipetakan ke satu kata unik di `s` dan sebaliknya.

[Link Soal](https://leetcode.com/problems/word-pattern/description/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini membangun dua mapping: dari karakter ke kata dan dari kata ke karakter. Setiap kata di `s` dicek apakah sudah pernah dipetakan ke karakter tertentu, dan sebaliknya, untuk memastikan tidak ada dua karakter yang memetakan ke kata yang sama atau sebaliknya.

## 💡 Inti

Inti dari kode ini adalah menjaga konsistensi pemetaan dua arah antara karakter di `pattern` dan kata di `s` menggunakan dua buah `unordered_map`.

## ⚙️ Cara kerja

1. Inisialisasi dua map: `pat` (char ke string) dan `str` (string ke char).
2. Iterasi karakter demi karakter pada string `s` untuk memisahkan kata berdasarkan spasi.
3. Untuk setiap kata yang ditemukan:
   - Jika karakter di `pattern` belum pernah dipetakan dan kata juga belum pernah dipetakan, buat pemetaan baru.
   - Jika sudah pernah dipetakan, cek apakah pemetaan konsisten. Jika tidak, return `false`.
   - Lanjut ke karakter berikutnya di `pattern`.
4. Setelah semua kata diproses, cek apakah jumlah kata sama dengan panjang `pattern` dan tidak ada sisa kata di `s`.
5. Jika semua konsisten, return `true`.

## 📦 Contoh

- Input: `pattern = "abba"`, `s = "dog cat cat dog"`
  - 'a' → "dog", 'b' → "cat", mapping konsisten, output: `true`
- Input: `pattern = "abba"`, `s = "dog cat cat fish"`
  - 'a' → "dog", 'b' → "cat", mapping gagal di kata terakhir, output: `false`
- Input: `pattern = "aaaa"`, `s = "dog cat cat dog"`
  - 'a' → "dog", mapping gagal di kata kedua, output: `false`

## 📊 Complexity

### ⏱️ Time Complexity = `O(N)`

`N` adalah panjang string `s`, karena setiap karakter hanya diproses sekali.

### 🗂️ Space Complexity = `O(M)`

`M` adalah jumlah kata unik di `s` dan karakter unik di `pattern`, digunakan untuk menyimpan mapping.

## 💻 Code

```cpp []
class Solution {
public:
    bool wordPattern(string patt, string s) {
        unordered_map<char, string>  pat {};
        unordered_map<string, char>  str {};
        int j = 0;
        
        rep(i, s.size()) {
            if (isspace(s[i])) {
                string substr = s.substr(0, i); 
                s.erase(s.begin(), s.begin() + i + 1);
                i = -1;
                
                if (pat[patt[j]].empty() and !str[substr]) {
                    pat[patt[j]] = substr;
                    str[substr] = patt[j];
                }

                else if (pat[patt[j]] != substr and str[substr] != patt[j])
                    return false;
                
                ++j;
            }
            else if (i + 1 == s.size()) {
                if (pat[patt[j]].empty() and !str[s]) {
                    pat[patt[j]] = s;
                    str[s] = patt[j];
                    
                }
                else if (pat[patt[j]] != s and str[s] != patt[j]) 
                    return false;
                s.erase();
                
                ++j;
            }
        }
        
        if (!s.empty() or j != patt.size())
            return false;

        return true;
    }
};
```
