# Penjelasan Fungsi `findLucky` - Leetcode `1394`

Fungsi `findLucky` bertujuan untuk mencari angka "lucky" terbesar dalam sebuah array, yaitu angka yang jumlah kemunculannya sama dengan nilainya sendiri. Jika tidak ada angka yang memenuhi kondisi tersebut, fungsi mengembalikan -1.

## Cara kerja

1. Membuat array `nums` berukuran 501 untuk menghitung frekuensi kemunculan setiap angka (asumsi angka dalam array `arr` berada di rentang 1 sampai 500).
2. Melakukan iterasi pada array input `arr` dan menambah hitungan pada indeks yang sesuai di `nums`.
3. Melakukan iterasi mundur dari angka 500 ke 1 untuk mencari angka terbesar yang frekuensinya sama dengan nilainya.
4. Jika ditemukan, angka tersebut langsung dikembalikan.
5. Jika tidak ada yang memenuhi, fungsi mengembalikan -1.

## Contoh

Input: `[2, 2, 3, 4]`

- Hitung frekuensi:  
  - 2 muncul 2 kali  
  - 3 muncul 1 kali  
  - 4 muncul 1 kali  
- Cek dari angka terbesar ke terkecil:  
  - 4 muncul 1 kali (tidak sama dengan 4)  
  - 3 muncul 1 kali (tidak sama dengan 3)  
  - 2 muncul 2 kali (sama dengan 2) → return 2

Output: `2`

## Inti

Fungsi ini menggunakan sebuah array frekuensi untuk menghitung berapa kali setiap angka muncul dalam input. Setelah menghitung frekuensi, fungsi melakukan pengecekan mulai dari angka terbesar ke angka terkecil, mencari angka yang jumlah kemunculannya sama dengan nilai angka tersebut. Begitu ditemukan, angka tersebut langsung dikembalikan sebagai hasil. Jika tidak ada angka yang memenuhi kondisi tersebut, fungsi mengembalikan -1 sebagai tanda tidak ada angka "lucky".

## Complexity

### Time Complexity = `O(n + k)`

- `n` adalah ukuran array input `arr` untuk menghitung frekuensi.  
- `k` adalah batas maksimum nilai angka (dalam kasus ini 500) untuk pencarian angka lucky.  
- Karena `k` adalah konstanta, kompleksitas ini mendekati `O(n)`.

### Space Complexity = `O(k)`

- Menggunakan array `nums` berukuran tetap 501 untuk menyimpan frekuensi, sehingga kompleksitas ruang adalah `O(k)`, dengan `k` = 501 (konstan).

## Code

```cpp []
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int nums[501] = {0};  // Array untuk menghitung frekuensi angka (1 sampai 500)

        for (int n : arr) 
            nums[n]++;       // Hitung kemunculan setiap angka dalam arr

        for (int i = 500; i > 0; i--) {
            if (nums[i] == i) // Cek apakah frekuensi sama dengan angka itu sendiri
                return i;     // Kembalikan angka terbesar yang memenuhi kondisi
        }

        return -1;            // Jika tidak ada angka yang memenuhi, kembalikan -1
    }
};
```
