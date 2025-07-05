# Penjelasan Fungsi `findMedianSortedArrays` - Leetcode `4`

Fungsi ini bertujuan untuk mencari median dari dua array terurut (nums1 dan nums2) dengan cara menggabungkan elemen-elemen dari kedua array hingga mencapai posisi median, kemudian menghitung median berdasarkan jumlah total elemen.

## Cara kerja

Fungsi melakukan proses merge secara bertahap dengan mengambil elemen-elemen terkecil dari kedua array secara berurutan hingga mencapai posisi tengah gabungan kedua array.

- Pertama, fungsi menentukan posisi tengah (half) dari gabungan kedua array.
- Kemudian, menggunakan dua indeks (i1 untuk nums1 dan i2 untuk nums2), fungsi mengambil elemen terkecil dari kedua array secara berulang dan menambahkannya ke nums1 (memodifikasi nums1 sebagai tempat penyimpanan hasil merge).
- Setelah proses penggabungan sampai posisi tengah selesai, fungsi menghitung median berdasarkan jumlah total elemen ganjil atau genap.

## Contoh

Misalkan:

``` powershell
nums1 = {1, 3, 5}
nums2 = {2, 4, 6}
```

- Total elemen = 6, posisi tengah (half) = 4.
- Proses merge mengambil elemen terkecil secara berurutan: 1 (dari nums1), 2 (dari nums2), 3 (dari nums1), 4 (dari nums2).
- Setelah 4 elemen tergabung, median dihitung sebagai rata-rata elemen ke-3 dan ke-4 dari gabungan, yaitu (3 + 4) / 2 = 3.5.

## Inti

- Menggunakan dua pointer (i1 dan i2) untuk melakukan merge dua array terurut sampai posisi tengah gabungan.
- Memodifikasi nums1 dengan menambahkan elemen hasil merge.
- Menghitung median berdasarkan jumlah total elemen ganjil atau genap.

## Complexity

### Time Complexity = `O(m+n)`

Karena proses merge dilakukan hingga posisi tengah gabungan yang bisa mencapai setengah dari total elemen, waktu yang dibutuhkan adalah linear terhadap jumlah elemen kedua array.

### Space Complexity = `O(1)` (dengan asumsi modifikasi nums1 diperbolehkan)

Fungsi menggunakan ruang tambahan minimal karena hasil merge disimpan di nums1 itu sendiri, tanpa membuat struktur data baru. Namun, jika nums1 tidak boleh dimodifikasi, maka ruang tambahan akan menjadi `O(m + n)`.

## Code

```cpp []
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double solution;
    int half  = (nums1.size() + nums2.size()) / 2 + 1,
        max   = nums1.size() + nums2.size(),
        maxi1 = nums1.size() - 1, maxi2 = nums2.size() - 1,
        i1    = 0,                i2    = 0;

    for (int i = 0; i < half; i++) {
        bool canTakeFromNums1 = (i1 <= maxi1);
        bool canTakeFromNums2 = (i2 <= maxi2);

        if (canTakeFromNums1 && (!canTakeFromNums2 || nums1[i1] <= nums2[i2])) {
            nums1.push_back(nums1[i1]);
            i1++;
        } else if (canTakeFromNums2) {
            nums1.push_back(nums2[i2]);
            i2++;
        }
    }

    solution = (max % 2 == 0)
                    ? (double)((double)nums1[nums1.size() - 1] +
                        (double)nums1[nums1.size() - 2]) /
                        2
                    : (double)nums1[nums1.size() - 1];
    return solution;
}
```
