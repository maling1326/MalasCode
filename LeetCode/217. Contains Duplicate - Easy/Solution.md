# Penjelasan Fungsi `stringToIntegerVector` - Leetcode `217`

Fungsi `stringToIntegerVector` digunakan untuk mengubah string berisi angka yang dipisahkan koma atau spasi menjadi sebuah vector berisi integer.

## Cara kerja

Fungsi ini melakukan iterasi pada setiap karakter dalam string. Jika menemukan karakter pemisah (koma atau spasi), maka substring dari posisi sebelumnya hingga pemisah diubah menjadi integer dan dimasukkan ke dalam vector. Proses ini diulang hingga seluruh string selesai diproses.

## Contoh

Contoh:

- Input: "1, 2, 3"
- Proses: Dipecah menjadi [1, 2, 3]
- Output: `vector<int>` {1, 2, 3}

## Inti

Inti kode: Memecah string berdasarkan delimiter dan mengubah setiap bagian menjadi integer, lalu memasukkannya ke vector.

## Complexity

### Time Complexity = `O(n)`

Melakukan satu kali iterasi pada seluruh karakter string, sehingga kompleksitas waktu adalah O(n), dengan n adalah panjang string.

### Space Complexity = `O(n)`

Membuat vector hasil dengan jumlah elemen sebanyak angka yang ada di string, sehingga kompleksitas ruang adalah O(n).

## Code

```cpp []
vector<int> stringToIntegerVector(string text) {
    int begin = 0;
    vector<int> result;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ',' || text[i] == ' ') {
            if (i > begin) {  // avoid empty substrings
                result.push_back(stoi(text.substr(begin, i - begin)));
            }
            begin = i + 1;  // move begin to the character after the delimiter
        }
        if (i == text.size() - 1) {
            if (i >= begin) {
                result.push_back(stoi(text.substr(begin, i - begin + 1)));
            }
        }
    }

    return result;
}
```
