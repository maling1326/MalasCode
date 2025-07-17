# Penjelasan Fungsi `Minimal Hari Makan Lumpia` - GEMASTIK 2024

Fungsi ini digunakan untuk menghitung hari minimal yang dibutuhkan Astik untuk menghabiskan semua lumpia dengan aturan prioritas dan kombinasi makan setiap harinya.

## Soal

Astik punya lumpia daging (A), ayam (B), udang (C), ikan (D). Setiap hari makan maksimal 3 lumpia, daging dan ayam tidak boleh bareng, udang dan ikan juga tidak boleh bareng, dan harus dihabiskan sesuai urutan prioritas. Hitung hari minimal untuk menghabiskan semua lumpia.

## Penjelasan fungsi berdasarkan Soal yang diberikan

Kode membagi kasus berdasarkan sisa lumpia tiap jenis. Prioritas diatur sesuai urutan pada soal. Setiap jenis lumpia dihabiskan dulu sebelum lanjut ke prioritas berikutnya. Penghitungan hari dilakukan dengan membagi jumlah lumpia tiap jenis dengan 3 (maksimal makan per hari), dan menggabungkan hasilnya sesuai aturan kombinasi makan.

## Inti

Inti kode: Hitung hari untuk setiap jenis lumpia dengan membagi jumlahnya dengan 3, lalu gabungkan sesuai aturan prioritas dan kombinasi makan.

## Cara kerja

Bayangkan Astik makan lumpia seperti antrean. Setiap hari, dia ambil maksimal 3 lumpia, tapi harus mengikuti aturan: daging dan ayam tidak boleh bareng, udang dan ikan juga tidak boleh bareng, dan urutan makan harus sesuai prioritas. Kode menghitung berapa hari untuk menghabiskan tiap jenis lumpia, lalu menjumlahkan sesuai aturan.

## Contoh

Contoh:

- Input: 4 3 2 1
- Proses: Habiskan daging dulu (2 hari), lalu ayam (1 hari), lalu udang (1 hari), lalu ikan (1 hari)
- Output: 5

## Complexity

### Time Complexity = `O(1)`

Hanya melakukan operasi aritmatika sederhana tanpa iterasi, sehingga kompleksitas waktu konstan.

### Space Complexity = `O(1)`

Tidak menggunakan struktur data tambahan, hanya variabel sederhana.

## Code

```cpp []
int main() {
    long long A, B, C, D, days = 0;
    std::cin >> A >> B >> C >> D;

    if (B == 0 &&  C == 0) days = (A + D + 2) / 3;
    else if       (B == 0) days = ((A + C + 2) / 3) + (D + 2) / 3;
    else if       (C == 0) days = ((B + D + 2) / 3) + (A + 2) / 3;
    else                   days = ((B + C + 2) / 3) + (A + 2) / 3 + (D + 2) / 3;

    std::cout << days;
    return 0;
}
```
