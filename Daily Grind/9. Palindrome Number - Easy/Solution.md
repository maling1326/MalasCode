# Penjelasan Fungsi `isPalindrome` - Leetcode `9`

Fungsi isPalindrome digunakan untuk memeriksa apakah sebuah bilangan bulat adalah palindrome, yaitu angka yang jika dibaca dari depan maupun belakang tetap sama.

## Cara kerja

- Angka diubah menjadi string.
- Karakter pada string dibandingkan dari depan dan belakang secara berpasangan hingga ke tengah.
- Jika ditemukan pasangan karakter yang tidak sama, fungsi langsung mengembalikan false.
- Jika semua pasangan karakter sama, fungsi mengembalikan true.

## Contoh

- Input: 121
  - Konversi ke string: "121"
  - Bandingkan '1' (depan) dengan '1' (belakang): sama
  - Bandingkan '2' (tengah): selesai
  - Output: true

- Input: 123
  - Konversi ke string: "123"
  - Bandingkan '1' (depan) dengan '3' (belakang): beda
  - Output: false

## Inti

- Konversi integer ke string.
- Cek karakter dari ujung ke tengah, jika beda return false.
- Jika lolos semua pengecekan, return true.

## Complexity

### Time Complexity = `O(n)`

n adalah jumlah digit pada angka. Setiap digit hanya dicek sekali dari depan dan belakang.

### Space Complexity = `O(n)`

Membutuhkan memori tambahan untuk menyimpan string hasil konversi dari integer, sebesar jumlah digit angka.

## Code

```cpp []
class Solution {
public:
    bool isPalindrome(int x) {
        string nums = std::to_string(x);  // Konversi angka ke string
        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() - i - 1])  // Bandingkan karakter depan & belakang
                return false;  // Bukan palindrome
        }
        return true;  // Palindrome
    }
};
```
