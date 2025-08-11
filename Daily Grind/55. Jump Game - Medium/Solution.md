# 📝 Penjelasan Fungsi `canJump` - Leetcode `55. Jump Game`

Fungsi `canJump` digunakan untuk menentukan apakah kita bisa mencapai indeks terakhir dari array `nums`, di mana setiap elemen menunjukkan maksimal langkah yang bisa diambil dari posisi tersebut.

## ❓ Soal

Diberikan array integer `nums`, setiap elemen menunjukkan maksimal langkah yang bisa diambil dari posisi itu. Mulai dari indeks pertama, tentukan apakah bisa mencapai indeks terakhir.

[Link Soal](https://leetcode.com/problems/jump-game/description/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Fungsi ini mengecek dari belakang ke depan, apakah setiap posisi bisa mencapai indeks terakhir. Jika bisa, posisi tersebut dianggap sebagai "goal" baru, dan proses diulang hingga indeks pertama.

## 💡 Inti

Inti dari kode ini adalah mencari posisi paling kiri yang bisa mencapai akhir array, dan mengecek apakah posisi awal bisa mencapai posisi tersebut.

## ⚙️ Cara kerja

1. Inisialisasi dua variabel `i` dan `j` pada indeks terakhir array.
2. Iterasi dari belakang ke depan (`i` dari `nums.size() - 1` ke `0`).
3. Pada setiap iterasi, cek apakah dari posisi `i` bisa mencapai posisi `j` (`i + nums[i] >= j`).
4. Jika bisa, update `j` ke `i` (goal baru).
5. Jika `j` sudah di posisi 0, return `true` (berarti bisa sampai akhir dari awal).
6. Jika loop selesai dan `j` tidak di 0, return `false`.

## 📦 Contoh

- Input: `[2,3,1,1,4]`
  - Step: goal di 4, bisa dicapai dari 1, lalu dari 0, return `true`.
- Input: `[3,2,1,0,4]`
  - Step: goal di 4, tidak bisa dicapai dari 0, return `false`.

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Iterasi satu kali dari belakang ke depan.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan struktur data tambahan.

## 💻 Code

```cpp []
class Solution {
public:
    bool canJump(vector<int>& nums) {
       for(int i = nums.size() - 1, j = i; i >= 0; --i) {
            if ((i + nums[i]) - j >= 0)
                j = i;
            if (j == 0) return true;
        }
        return false;
    }
};
```
