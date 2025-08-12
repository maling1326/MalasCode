<!-- filepath: l:\Coding\LeetCode\Daily Grind\31. Next Permutation - Solution.md -->
# 📝 Penjelasan Fungsi `nextPermutation` - Leetcode `31. Next Permutation`

Fungsi `nextPermutation` digunakan untuk mengubah urutan array integer `nums` menjadi urutan selanjutnya secara leksikografis. Jika sudah urutan terbesar, maka diubah menjadi urutan terkecil.

## ❓ Soal

Diberikan array integer `nums`, ubah urutannya menjadi urutan leksikografis berikutnya. Jika tidak ada urutan yang lebih besar, ubah menjadi urutan terkecil (ascending).

[Link Soal](https://leetcode.com/problems/next-permutation/description/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Fungsi ini langsung memanggil fungsi `next_permutation` dari STL yang otomatis mengubah urutan array ke urutan selanjutnya sesuai aturan soal.

## 💡 Inti

Inti dari kode ini adalah memanfaatkan fungsi bawaan C++ (`next_permutation`) untuk mendapatkan urutan array berikutnya secara efisien dan in-place.

## ⚙️ Cara kerja

1. Fungsi menerima array `nums` sebagai parameter.
2. Fungsi `next_permutation(all(nums))` dipanggil untuk mengubah urutan array ke urutan selanjutnya.
3. Jika sudah urutan terbesar, array diubah menjadi urutan terkecil.
4. Semua perubahan dilakukan langsung pada array `nums` (in-place).

## 📦 Contoh

- Input: `[1,2,3]`
  - Step: Urutan berikutnya adalah `[1,3,2]`.
- Input: `[3,2,1]`
  - Step: Sudah urutan terbesar, diubah jadi `[1,2,3]`.
- Input: `[1,1,5]`
  - Step: Urutan berikutnya adalah `[1,5,1]`.

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Fungsi `next_permutation` melakukan operasi linear terhadap panjang array.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan memori tambahan, semua perubahan dilakukan langsung pada array.

## 💻 Code

```cpp []
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(all(nums));
    }
};
```
