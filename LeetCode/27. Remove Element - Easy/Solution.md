# 📝 Penjelasan Fungsi `Remove Element` - Leetcode 27

Fungsi ini digunakan untuk menghapus semua elemen yang bernilai `val` dari array `nums` dan mengembalikan jumlah elemen yang tersisa.

## ❓ Soal

[Link Soal](https://leetcode.com/problems/remove-element/)  
Inti soal: Diberikan array dan sebuah nilai, hapus semua elemen yang sama dengan nilai tersebut dan kembalikan jumlah elemen yang tersisa.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode menggunakan fungsi `remove` untuk memindahkan semua elemen yang bukan `val` ke depan, lalu `erase` untuk menghapus sisa elemen yang bernilai `val` dari array.

## 💡 Inti

Inti kode:  

- Hapus semua elemen yang sama dengan `val` menggunakan `remove` dan `erase`.
- Kembalikan ukuran array setelah penghapusan.

## ⚙️ Cara kerja

Step-by-step:

1. Panggil `remove(all(nums), val)` untuk memindahkan semua elemen yang bukan `val` ke depan array.
2. Gunakan `erase` untuk menghapus elemen yang tersisa (yang bernilai `val`) dari array.
3. Kembalikan ukuran array (`nums.size()`) sebagai hasil.

## 📦 Contoh

- Input: nums = [3,2,2,3], val = 3  
  Proses: Hapus semua 3 → [2,2]  
  Output: 2

- Input: nums = [0,1,2,2,3,0,4,2], val = 2  
  Proses: Hapus semua 2 → [0,1,3,0,4]  
  Output: 5

## 📊 Complexity

### ⏱️ Big-O Time Complexity = `O(n)`

Iterasi satu kali untuk seluruh elemen array.

### 🗂️ Big-O Space Complexity = `O(1)`

Penghapusan dilakukan in-place tanpa alokasi array baru.

## 💻 Code

```cpp []
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        scope("Function");
        nums.erase(remove(all(nums), val), nums.end());
        return nums.size();
    }
}
```
