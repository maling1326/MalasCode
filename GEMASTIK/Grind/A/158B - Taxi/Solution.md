# 📝 Penjelasan Fungsi `Taxi` - Codeforces 158B

Fungsi ini digunakan untuk menghitung jumlah minimum taksi yang dibutuhkan untuk mengangkut semua anak sesuai aturan grup.

## ❓ Soal

[Link Soal](https://codeforces.com/problemset/problem/158/B)
Inti soal: Diberikan n grup anak, tiap grup berisi 1-4 orang. Setiap taksi muat maksimal 4 orang dan satu grup harus tetap bersama. Hitung jumlah minimum taksi yang dibutuhkan.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode menghitung jumlah grup berdasarkan ukuran, lalu menggabungkan grup agar muat dalam satu taksi sebanyak mungkin sesuai aturan.

## 💡 Inti

Inti kode: Gabungkan grup 3 dan 1, grup 2 berpasangan, grup 4 langsung masuk taksi, sisa grup 1 dimasukkan sesuai kapasitas.

## ⚙️ Cara kerja

Bayangkan taksi sebagai kotak berisi maksimal 4 anak. Gabungkan grup agar kotak terisi penuh, mulai dari grup besar, lalu gabungkan sisa grup kecil.

## 📦 Contoh

- Input: n = 5, grup = [1, 2, 4, 3, 3]
- Proses: Grup 4 → 1 taksi, grup 3 + 1 → 1 taksi, grup 3 → 1 taksi, grup 2 → 1 taksi
- Output: 4

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Iterasi satu kali untuk menghitung dan menggabungkan grup.

### 🗂️ Space Complexity = `O(1)`

Menggunakan variabel penghitung, tidak ada struktur data tambahan.

## 💻 Code

```cpp []
int HowMuchTaxi (int n) {
    int s, a = 0, b = 0, c = 0, d = 0;

    for (int i = 0; i < (n); ++i) {
        input (s);
        switch (s) { case 1: a++; break;
                    case 2: b++; break;
                    case 3: c++; break;
                    case 4: d++; break; }
    }

    // Grup 4 orang di masukin Taxi
    s = d;

    // Grup 3 orang dan 1 Orangs
    s += c;
    a -= std::min(c, a);

    // Grup 2 Orang dimasukan
    s += b / 2;
    b %= 2;

    if (b) { // Jika ada sisa dari grup 2, maka digabung dengan grup 1
        s++;
        a -= std::min(2, a);
    }

    // Grup 1 dimasukkan semua
    s += (a + 3) / 4;

    outputln (s);

    return s;
}
```
