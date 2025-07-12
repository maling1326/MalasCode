# Penjelasan Fungsi `FindSumPairs` - Leetcode `1865`

AI

Kelas FindSumPairs ini dirancang untuk menyimpan dua vector angka dan mendukung dua operasi utama:

- Menambahkan nilai ke elemen tertentu dalam vector kedua (add)
- Menghitung berapa banyak pasangan (x, y) dengan x dari vector pertama dan y dari vector kedua yang jumlahnya sama dengan target tertentu (count).

## Cara kerja

- Pada konstruktor, kelas menyimpan salinan vector `_nums1` dan `_nums2`.
- Kemudian dibuat dua frequency map (freq1 dan freq2) yang menyimpan berapa kali setiap angka muncul di masing-masing vector.
- Fungsi add(index, val) memperbarui nilai elemen `_nums2[index]` dengan menambahkan val dan juga memperbarui freq2 agar selalu akurat.
- Fungsi `count(tot)` menghitung jumlah pasangan (num1, num2) dengan num1 + num2 == tot menggunakan frequency map untuk menghindari iterasi penuh yang mahal.

## Contoh

_nums1 = {`1`, `2`, `2`}
_nums2 = {`3`, `4`}

- freq1 = {1:1, 2:2}
- freq2 = {3:1, 4:1}

Jika kita panggil count(5), maka:

- Pasangan yang jumlahnya 5 adalah (1,4) dan (2,3).
- Frekuensi pasangan (1,4) adalah `freq1 * freq2` = `1 * 1` = `1`
- Frekuensi pasangan (2,3) adalah `freq1 * freq2` = `2 * 1` = `2`
- Total pasangan = `1 + 2` = 3

Jika kita panggil `add(0, 1)`, maka _nums2 berubah dari 3 menjadi 4, dan freq2 diperbarui menjadi {3:0, 4:2} (3 dihapus karena frekuensinya 0).
Setelah itu, `count(5)` akan menghitung ulang dengan kondisi baru.

## Inti

- Frequency map memungkinkan penghitungan jumlah pasangan dengan efisien tanpa iterasi penuh.
- Saat `count(tot)` dipanggil, iterasi dilakukan pada map yang lebih kecil untuk mengurangi jumlah iterasi.
- Perkalian frekuensi `count1 * freq2[complement]` adalah untuk menghitung semua kombinasi pasangan yang mungkin dari nilai yang sama.

## Complexity

### Time Complexity = `O(M)`

- M adalah ukuran dari frequency map yang lebih kecil antara freq1 dan freq2.
- Update add dan lookup count keduanya bekerja dalam waktu rata-rata O(1) untuk operasi hash map.
- Menghindari iterasi O(N) penuh pada vector _nums2 saat count.

### Space Complexity = `O(N + M)`

- Menyimpan salinan vector `_nums1` dan `_nums2`.
- Menyimpan dua frequency map yang ukurannya maksimal sama dengan jumlah elemen unik di masing-masing vector.

## Code

```cpp []
class FindSumPairs {
    vector<int> _nums1;
    vector<int> _nums2;
    unordered_map<int, int> freq1;  // Frekuensi kemunculan angka di _nums1
    unordered_map<int, int> freq2;  // Frekuensi kemunculan angka di _nums2

public:
    FindSumPairs(const vector<int>& nums1, const vector<int>& nums2)
        : _nums1(nums1), _nums2(nums2)
    {
        freq1.reserve(nums1.size());  // Reservasi memori untuk efisiensi
        freq2.reserve(nums2.size());

        // Hitung frekuensi setiap angka di nums1
        for (const auto& num : nums1)
            freq1[num]++;

        // Hitung frekuensi setiap angka di nums2
        for (const auto& num : nums2)
            freq2[num]++;
    }

    void add(int index, int val) {
        int oldVal = _nums2[index];
        int newVal = oldVal + val;

        // Kurangi frekuensi nilai lama, hapus jika sudah nol
        freq2[oldVal]--;
        if (freq2[oldVal] == 0)
            freq2.erase(oldVal);

        // Tambah frekuensi nilai baru
        freq2[newVal]++;
        _nums2[index] = newVal;  // Update nilai di vector _nums2
    }

    int count(int tot) {
        int occ = 0;

        // Iterasi pada map yang lebih kecil untuk efisiensi
        if (freq1.size() < freq2.size()) {
            // Untuk setiap angka di freq1, cari pasangan yang melengkapi total
            for (const auto& [num1, count1] : freq1) {
                int complement = tot - num1;
                if (freq2.count(complement))  // Cek apakah pasangan ada di freq2
                    occ += count1 * freq2[complement];  // Hitung semua pasangan
            }
        } else {
            // Jika freq2 lebih kecil, iterasi di freq2 dan cari pasangan di freq1
            for (const auto& [num2, count2] : freq2) {
                int complement = tot - num2;
                if (freq1.count(complement))
                    occ += count2 * freq1[complement];
            }
        }

        return occ;  // Total pasangan yang jumlahnya tot
    }
};
```
