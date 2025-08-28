# 📝 Penjelasan Fungsi `sortMatrix` - Leetcode `3446. Sort Matrix by Diagonals`

Fungsi `sortMatrix` digunakan untuk mengurutkan diagonal pada matriks persegi `grid` sesuai aturan: diagonal di segitiga kiri bawah (termasuk diagonal utama) diurutkan menurun, sedangkan diagonal di segitiga kanan atas diurutkan menaik.

## ❓ Soal

Diberikan matriks persegi `grid`, urutkan diagonal di segitiga kiri bawah (termasuk diagonal utama) secara menurun, dan diagonal di segitiga kanan atas secara menaik.

[Link Soal](https://leetcode.com/problems/sort-matrix-by-diagonals/description/?envType=daily-question&envId=2025-08-28)

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini memproses setiap diagonal satu per satu, mengumpulkan elemen diagonal ke dalam array sementara, lalu mengurutkannya sesuai aturan (menurun atau menaik), dan menuliskannya kembali ke posisi diagonal semula.

## 💡 Inti

Inti dari kode ini adalah mengakses setiap diagonal secara terpisah, mengurutkan isinya sesuai posisi diagonal (bawah kiri: menurun, atas kanan: menaik), lalu menuliskannya kembali ke grid.

## ⚙️ Cara kerja

1. Loop dari 1 hingga `n + n - 2` (untuk semua diagonal kecuali diagonal utama yang sudah termasuk).
2. Untuk setiap diagonal:
   - Jika diagonal di bawah atau di diagonal utama (indeks < n):
     - Ambil elemen diagonal dari kiri bawah ke kanan atas.
     - Urutkan secara menurun.
     - Tulis kembali ke grid pada posisi diagonal.
   - Jika diagonal di atas diagonal utama (indeks >= n):
     - Ambil elemen diagonal dari kanan atas ke kiri bawah.
     - Urutkan secara menaik.
     - Tulis kembali ke grid pada posisi diagonal.
3. Setelah semua diagonal diproses, return grid hasil.

## 📦 Contoh

- Input: `[[1,7,3],[9,8,2],[4,5,6]]`
  - Diagonal utama dan bawah: `[1,8,6]` → `[8,6,1]`
  - Diagonal atas: `[7,2]` → `[2,7]`
  - Output: `[[8,2,3],[9,6,7],[4,5,1]]`

- Input: `[[0,1],[1,2]]`
  - Diagonal utama dan bawah: `[0,2]` → `[2,0]`
  - Output: `[[2,1],[1,0]]`

## 📊 Complexity

### ⏱️ Time Complexity = `O((m + n) * min(m, n) log min(m, n))`

- Loop luar dijalankan sekitar (jumlah diagonal) kali, yang kira-kira `O(m + n - 2)`, di mana m dan n adalah dimensi grid.
- Untuk setiap diagonal, kode mengumpulkan elemen ke dalam vektor sementara, mengurutkannya, dan kemudian menulis kembali.
- Panjang setiap diagonal bervariasi, tetapi dalam kasus terburuk, sebuah diagonal dapat mengandung hingga min(m, n) elemen.
- Menyortir setiap diagonal memakan waktu `O(k log k)`, di mana k adalah panjang diagonal tersebut.
- Dengan menjumlahkan semua diagonal, biaya penyortiran total kira-kira `O((m + n) * min(m, n) log min(m, n))`, karena setiap elemen merupakan bagian dari tepat satu diagonal.

### 🗂️ Space Complexity = `O(min(m, n))`

- Vektor sementara `sort_nums` menyimpan elemen-elemen diagonal, yang ukurannya paling banyak `min(m, n)`.
- Oleh karena itu, ruang tambahan yang digunakan adalah `O(min(m, n))`.

## 💻 Code

```cpp []
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for (int i = 1; i < ssize(grid) + ssize(grid[0]) - 2; ++i) {
            vector<int> sort_nums;
            int x = 0, y = 0, xx = 0, yy = 0;
            if (i < size(grid)) {
                xx = x = size(grid) - i - 1;

                for (; xx < size(grid); ++xx, ++yy)
                    sort_nums.push_back(grid[xx][yy]);

                sort(sort_nums.begin(), sort_nums.end(), greater<int>());

                for (; y < size(sort_nums); ++x, ++y)
                    grid[x][y] = sort_nums[y];
            } else {
                yy = y = i - size(grid) + 1;

                for (; yy < size(grid); ++xx, ++yy)
                    sort_nums.push_back(grid[xx][yy]);

                sort(sort_nums.begin(), sort_nums.end());

                for (; x < size(sort_nums); ++x, ++y)
                    grid[x][y] = sort_nums[x];
            }
        }
        return grid;
    }
};
```
