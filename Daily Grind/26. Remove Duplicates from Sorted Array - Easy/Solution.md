# Penjelasan Fungsi `removeDuplicates` - Leetcode `26`

Fungsi ini menghapus elemen duplikat dari vector terurut sehingga hanya menyisakan elemen unik.

## Cara kerja

Fungsi melakukan iterasi pada vector, membandingkan elemen saat ini dengan elemen sebelumnya.  
Jika berbeda, elemen tersebut dianggap unik dan dipindahkan ke posisi setelah elemen unik terakhir.  
Setelah selesai, elemen sisanya dihapus.

## Contoh

Contoh input:
nums = 1,

Penjelasan singkat step:

- Mulai dengan unique = 1 (elemen pertama pasti unik)

- Iterasi dari indeks 1:

  - nums `1` == nums `0` (1 == 1), skip
  - nums `2` != nums `1` (2 != 1), unique++, simpan 2 di posisi unique
  - nums `3` != nums `2` (3 != 2), unique++, simpan 3
  - nums `4` == nums `3` (3 == 3), skip
  - nums `5` != nums `4` (4 != 3), unique++, simpan 4

- Hapus elemen setelah posisi unique

Output : nums = [`1`, `2`, `3`, `4`]

## Inti

- Iterasi cek elemen duplikat berurutan
- Simpan elemen unik di posisi depan
- Hapus sisa elemen setelah elemen unik terakhir

## Complexity

### Time Complexity = `O(n)`

- Ada satu loop yang jalan dari indeks 1 sampai akhir vector, jadi iterasi sebanyak n-1 kali (n = ukuran nums).
- Di dalam loop cuma ada operasi perbandingan dan assignment yang cepat (O(1)).
- Setelah loop selesai, ada operasi erase untuk menghapus elemen sisanya.
- Fungsi erase di vector dari posisi tertentu sampai akhir juga berjalan dalam waktu O(k), di mana k adalah jumlah elemen yang dihapus.
- Total waktu kira-kira `O(n)` karena loop dan erase sama-sama linear terhadap ukuran vector.

### Space Complexity = `O(1)`

- Fungsi ini mengubah vector nums secara in-place, jadi gak pakai struktur data tambahan yang ukurannya tergantung n.
- Variabel unique dan beberapa variabel lain cuma pakai memori konstan.
- Jadi penggunaan memori adalah `O(1)` alias konstan.

## Code

```cpp []
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique{1};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i])
                continue;
            unique++;
            nums[unique - 1] = nums[i];
        }
        nums.erase(nums.begin() + unique, nums.end());
        return unique;
    }
};
```
