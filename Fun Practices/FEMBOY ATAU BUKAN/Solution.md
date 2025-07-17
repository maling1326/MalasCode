# 📝 Penjelasan Fungsi `Boy or Girl`

Fungsi ini digunakan untuk menentukan gender user berdasarkan jumlah karakter unik pada username.

## ❓ Soal

Inti soal: Diberikan sebuah string username, jika jumlah karakter uniknya ganjil maka user dianggap laki-laki, jika genap maka perempuan. Output: "CHAT WITH HER!" jika perempuan, "IGNORE HIM!" jika laki-laki.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode menghitung jumlah karakter unik pada username. Jika hasilnya ganjil, output "IGNORE HIM!". Jika genap, output "CHAT WITH HER!" sesuai aturan pada soal.

## 💡 Inti

Inti kode: Hitung karakter unik pada string, cek ganjil/genap, lalu print output sesuai aturan.

## ⚙️ Cara kerja

Bayangkan username sebagai kumpulan huruf. Kode menghitung berapa huruf berbeda yang muncul, lalu menentukan gender berdasarkan ganjil/genap jumlahnya.

## 📦 Contoh

- Input: Carlotta Montelli
- Proses: Karakter unik = 10 (genap)
- Output: CHAT WITH HER!

- Input: Cantarella
- Proses: Karakter unik = 7 (ganjil)
- Output: IGNORE HIM!

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Melakukan iterasi pada seluruh karakter string untuk menghitung karakter unik.

### 🗂️ Space Complexity = `O(1)`

Menggunakan array berukuran tetap (26 huruf alfabet).

## 💻 Code

```cpp []
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESETL  std::cout << "\033[0m";
int main() {
    int chara[26] {0}, 
        unique    {0};
    string word;
    cout << "Masukkan Nama : " << CYAN;
    getline(cin, word); RESETL
    for (char c : word) {
        c = tolower(c);
        if (chara[c - 'a'] == 0) unique++;
        chara[c - 'a']++;
    }
    if (unique % 2 == 1) 
        outputln (RED,   "IGNORE HIM!");
    else 
        outputln (GREEN, "CHAT WITH HER! <3");    
    RESETL
    return 0;
}
```
