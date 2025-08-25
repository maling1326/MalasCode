# 📝 Penjelasan Fungsi `maxArea` - Leetcode `11. Container With Most Water`

Fungsi `maxArea` digunakan untuk mencari dua garis pada array `height` yang jika digabungkan dengan sumbu-x membentuk wadah dengan kapasitas air maksimum.

## ❓ Soal

Diberikan array integer `height`, cari dua garis yang membentuk wadah dengan sumbu-x sehingga area air yang bisa ditampung maksimal.

[Link Soal](https://leetcode.com/problems/container-with-most-water/description/)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini menggunakan dua pointer (kiri dan kanan) untuk mencari kombinasi dua garis yang menghasilkan area maksimum, dengan selalu menggeser pointer yang lebih pendek.

## 💡 Inti

Inti dari kode ini adalah memaksimalkan area dengan mencoba semua pasangan garis dari ujung ke ujung, namun secara efisien dengan dua pointer.

## ⚙️ Cara kerja

1. Inisialisasi dua pointer: `l` di kiri dan `r` di kanan array.
2. Selama `l` belum bertemu `r`:
   - Hitung area: `(r - l) * min(height[l], height[r])`.
   - Update nilai maksimum area (`m`) jika area saat ini lebih besar.
   - Geser pointer yang tinggi garisnya lebih kecil (agar peluang area lebih besar).
3. Setelah pointer bertemu, return nilai maksimum area (`m`).

## 📦 Contoh

- Input: `height = [1,8,6,2,5,4,8,3,7]`
  - Area maksimal didapat antara indeks 1 dan 8: `(8 - 1) * min(8,7) = 7 * 7 = 49`
- Input: `height = [1,1]`
  - Hanya ada dua garis, area = 1

## 📊 Complexity

### ⏱️ Time Complexity = `O(n)`

Hanya satu kali iterasi dari kedua ujung array.

### 🗂️ Space Complexity = `O(1)`

Tidak menggunakan memori tambahan, hanya variabel penghitung.

## 💻 Code

```cpp []
class Solution {
public:
    int maxArea(vector<int>& h) {
        int m{0};
        
        for (int l = 0, r = ssize(h) - 1; l != r;) {
            m = max(m, (r - l) * (min(h[r], h[l])));
            (h[r] < h[l]) ? r-- : l++;
        }

        return m;
    }
};
```
