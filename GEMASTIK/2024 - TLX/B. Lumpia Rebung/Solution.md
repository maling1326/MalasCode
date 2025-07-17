# Penjelasan Fungsi `Potong Lumpia Rebung` - GEMASTIK 2024

Fungsi ini digunakan untuk menghitung panjang setiap bagian lumpia rebung setelah dipotong beberapa kali sesuai urutan dan aturan yang diberikan.

## Soal

Astik punya lumpia rebung sepanjang L cm dan N teman. Lumpia dipotong N kali, setiap kali memotong bagian ke-Bi dari kiri menjadi dua bagian sama panjang. Hitung panjang setiap bagian setelah semua pemotongan.

## Penjelasan fungsi berdasarkan Soal yang diberikan

Kode menerima input jumlah potongan dan urutan bagian yang dipotong. Setiap kali bagian dipotong, hasilnya dimasukkan ke posisi yang sesuai dalam vector, dan bagian yang dipotong dibagi dua. Proses diulang hingga semua potongan selesai, lalu hasil akhir berupa panjang setiap bagian.

## Inti

Inti kode: Simulasi pemotongan lumpia dengan membagi dua bagian yang dipilih, lalu menyimpan hasilnya dalam urutan yang benar.

## Cara kerja

Bayangkan lumpia rebung sebagai satu baris. Setiap kali dipotong, bagian yang dipilih dibelah dua dan satu bagian baru disisipkan di sebelahnya. Proses ini diulang sesuai urutan input, sehingga hasil akhirnya adalah panjang semua bagian dari kiri ke kanan.

## Contoh

Contoh:

- Input: N = 2, L = 8, B = [1, 2]
- Proses: Potong bagian ke-1 (8 → 4,4), lalu potong bagian ke-2 (4 → 2,2), hasil: [4,2,2]
- Output: 4 2 2

## Complexity

### Time Complexity = `O(N)`

Setiap potongan dilakukan satu kali iterasi, sehingga kompleksitas waktu O(N).

### Space Complexity = `O(N)`

Menyimpan hasil potongan dalam vector, sehingga kompleksitas ruang O(N).

## Code

```cpp []
int main() {

    int slices {0};
    vector<long long> result = {0};
    input (slices, result);

    int to[slices];
    for (int i = 0; i < slices; i++) input (to[i]);
    
    for (int i = 0; i < slices; i++) {
        result.insert(result.begin() + to[i], result[to[i] - 1] / 2);
        result[to[i] - 1] /= 2;
    }

    outputln (result);
    return 0;
}
```
