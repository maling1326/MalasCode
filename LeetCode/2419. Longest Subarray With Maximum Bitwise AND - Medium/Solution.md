# 📝 Penjelasan Fungsi `Longest Subarray With Maximum Bitwise AND` - Leetcode 2419

Fungsi ini digunakan untuk mencari panjang subarray terpanjang yang seluruh elemennya bernilai sama dengan nilai maksimum pada array, terkait operasi bitwise AND maksimum.

## ❓ Soal

[Link Soal](https://leetcode.com/problems/3sum/description/)  
Inti soal: Diberikan array integer, cari semua triplet unik yang jumlahnya nol. Setiap triplet harus terdiri dari tiga indeks berbeda dan tidak boleh ada duplikasi triplet.

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

Kode ini tidak langsung mencari triplet jumlah nol, namun mencari subarray terpanjang yang seluruh elemennya sama dengan nilai maksimum array. Ini relevan jika ingin mencari pola kemunculan nilai maksimum secara berurutan.

## 💡 Inti

Inti kode:  

- Cari nilai maksimum pada array.
- Hitung berapa kali berturut-turut nilai maksimum muncul.
- Simpan panjang urutan terpanjang.

## ⚙️ Cara kerja

Step-by-step:

1. Cari nilai maksimum array (`mxs`).
2. Inisialisasi dua variabel: `counts` (menghitung kemunculan berturut-turut) dan `top` (menyimpan hasil maksimum).
3. Iterasi setiap elemen array:
   - Jika elemen sama dengan nilai maksimum, tambah `counts`.
   - Jika tidak, bandingkan `counts` dengan `top`, simpan nilai terbesar ke `top`, lalu reset `counts` ke 0.
4. Setelah iterasi, kembalikan nilai maksimum antara `top` dan `counts` (untuk mengantisipasi jika urutan terpanjang ada di akhir array).

## 📦 Contoh

- Input: [1,3,3,2,3,3,3]
  - Nilai maksimum: 3
  - Urutan terpanjang 3 berturut-turut: 3 (pada indeks 4,5,6)
  - Output: 3

- Input: [2,2,2]
  - Nilai maksimum: 2
  - Urutan terpanjang: 3
  - Output: 3

- Input: [1,2,3,4]
  - Nilai maksimum: 4
  - Urutan terpanjang: 1
  - Output: 1

## 📊 Complexity

### ⏱️ Big-O Time Complexity = `O(n)`

Satu kali iterasi seluruh elemen array.

### 🗂️ Big-O Space Complexity = `O(1)`

Menggunakan variabel penghitung saja, tanpa struktur data tambahan.

## 💻 Code

```cpp []
class Solution {
public: 
    int longestSubarray(vector<int>& nums) {
        scope("Function");
        debug(nums);
        auto mx = max_element(all(nums));
        int mxs = *mx,
            counts{0},
            top{0};
        rep(i, nums.size()) {
            debug(i, top, counts, mxs, nums[i]);
            if (nums[i] != mxs) {
                top = max(top, counts);
                counts = 0;
                continue;
            }
            counts++;
        }
        return max(top, counts);
    }
};
```
