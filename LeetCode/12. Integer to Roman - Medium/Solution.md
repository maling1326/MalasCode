# 📝 Penjelasan Fungsi `Integer to Roman` - Leetcode 12

Fungsi ini digunakan untuk mengubah bilangan bulat menjadi angka Romawi sesuai aturan penulisan angka Romawi.

## ❓ Soal

[Link Soal](https://leetcode.com/problems/integer-to-roman/description/?envType=problem-list-v2&envId=math)
Inti soal: Diberikan bilangan bulat, ubah menjadi angka Romawi dengan aturan penulisan dan kombinasi simbol yang benar.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode membagi angka menjadi satuan ribuan, ratusan, puluhan, dan satuan. Setiap bagian dikonversi ke simbol Romawi sesuai aturan, termasuk penulisan khusus untuk angka 4, 9, 40, 90, 400, dan 900.

## 💡 Inti

Inti kode: Bagi angka ke digit, konversi tiap digit ke simbol Romawi sesuai aturan, gabungkan hasilnya.

## ⚙️ Cara kerja

Bayangkan angka sebagai kumpulan digit. Setiap digit diubah ke simbol Romawi sesuai aturan, lalu digabungkan dari digit terbesar ke terkecil.

## 📦 Contoh

- Input: 58
- Proses: 50 → L, 8 → VIII → LVIII
- Output: LVIII

- Input: 1994
- Proses: 1000 → M, 900 → CM, 90 → XC, 4 → IV → MCMXCIV
- Output: MCMXCIV

## 📊 Complexity

### ⏱️ Time Complexity = `O(1)`

Operasi konversi dilakukan pada digit tetap (maksimal 4 digit).

### 🗂️ Space Complexity = `O(1)`

Menggunakan variabel dan string hasil dengan panjang terbatas.

## 💻 Code

```cpp []
string intToRoman(int num) {
    string ans {""};
    int M =  num / 1000,
        C = (num / 100) % 10,
        X = (num / 10)  % 10,
        I = num % 10;
    if (M != 0) {                      // 1234
        for (int i = M; i > 0; --i)    // ^
            ans.push_back('M');
    }

    if (C != 0) {                           // 1234
        if      (C == 9) ans.append("CM");  //  ^
        else if (C == 4) ans.append("CD");
        else if (C >= 5) {
            ans.push_back('D');
            for (int i = C; i > 5; --i)
                ans.push_back('C');
        }
        else {
            for (int i = C; i > 0; --i)
                ans.push_back('C');
        }
    }

    if (X != 0) {                           // 1234
        if      (X == 9) ans.append("XC");  //   ^
        else if (X == 4) ans.append("XL");
        else if (X >= 5) {
            ans.push_back('L');
            for (int i = X; i > 5; --i)
                ans.push_back('X');
        }
        else {
            for (int i = X; i > 0; --i)
                ans.push_back('X');
        }
    }

    if (I != 0) {                           // 1234
        if      (I == 9) ans.append("IX");  //    ^
        else if (I == 4) ans.append("IV");
        else if (I >= 5) {
            ans.push_back('V');
            for (int i = I; i > 5; --i)
                ans.push_back('I');
        }
        else {
            for (int i = I; i > 0; --i)
                ans.push_back('I');
        }
    }

    return ans;
}
```
