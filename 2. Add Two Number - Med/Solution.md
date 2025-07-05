# Add Two Numbers - Leetcode `2`

Jadi, kode ini buat nambahin dua angka yang disimpen di linked list. Nah, tiap node di linked list itu nyimpen satu digit angka, dan angka-angkanya itu dibalik, jadi digit satuan ada di node pertama.

## Struktur Fungsi

`ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)`

- Fungsi ini menerima dua parameter, yaitu pointer ke node pertama dari dua linked list l1 dan l2.

- Fungsi mengembalikan pointer ke node pertama dari linked list hasil penjumlahan.

## How it works

1. Bikin pointer head

   Ini buat nyimpen node pertama dari hasil penjumlahan nanti.

2. Cek dulu, kalo dua-duanya kosong

    Kalau __l1__ sama __l2__ gak ada isinya, ya langsung balik nullptr aja, soalnya gak ada yang dijumlahin.

3. Hitung jumlah digit sekarang

    Ambil nilai dari __l1__ dan __l2__ kalo ada, kalo gak ada dianggap 0. Terus dijumlahin.

4. Bikin node baru buat nyimpen digit hasil __penjumlahan__

    Tapi cuma digit satuannya aja, jadi hasil penjumlahan __mod 10__.

5. Geser ke node berikutnya di __l1__ dan __l2__ kalo ada

    Supaya nanti bisa lanjut nambahin digit berikutnya.

6. Cek kalo ada carry (angka puluhan)

    Kalo hasil penjumlahan lebih dari 9, berarti ada _carry_ 1 yang harus ditambahin ke digit berikutnya.

    - Kalo __l1__ masih ada, tambahin 1 ke nilai __l1__.

    - Kalo gak, tapi __l2__ ada, tambahin 1 ke nilai __l2__.

    - Kalo gak ada keduanya, bikin node baru dengan nilai 1, terus sambungin ke hasil.

7. Panggil fungsi ini lagi buat node berikutnya

    Jadi ini rekursif, terus nambahin digit berikutnya sampe semua digit dari __l1__ dan __l2__ habis.

8. Balikin pointer ke node hasil

    Jadi hasilnya linked list yang isinya jumlah kedua angka tadi.

Intinya, kode ini nambahin dua angka yang disimpen di linked list digit per digit, sambil ngurus carry-nya juga. Cara kerjanya rekursif, jadi gampang banget buat nambahin digit selanjutnya.

## Complexity

### Time Complexity = `O(max(m,n))`

- Fungsi ini rekursif dan setiap kali panggil memproses satu node dari kedua linked list.
- Karena setiap langkah maju ke node berikutnya, dan jumlah node yang diproses paling banyak adalah panjang linked list yang lebih panjang dari l1 dan l2.
- Jadi, waktu yang dibutuhkan sekitar `O(max(m, n))`, di mana m dan n adalah panjang linked list l1 dan l2.
- Operasi di setiap langkah cuma penjumlahan dan pembuatan node baru, yang waktunya konstan.

### Space Complexity = `O(max(m,n))`

- Karena fungsi ini rekursif, setiap panggilan fungsi akan masuk ke stack rekursi.
- Dalam kasus terburuk, kedalaman rekursi sama dengan jumlah node yang diproses, yaitu sekitar O(max(m, n)).
- Selain itu, fungsi juga membuat linked list baru dengan jumlah node yang sama, jadi memori untuk node baru juga O(max(m, n)).
- Jadi total penggunaan memori adalah `O(max(m, n))` untuk linked list baru + O(max(m, n)) untuk stack rekursi.

## Code

```cpp []
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = nullptr;  // Pointer buat nyimpen head dari hasil linked list

        if (!l1 && !l2)            // Basis rekursi: kalo dua-duanya kosong, selesai
            return nullptr;

        // Hitung jumlah digit sekarang (ambil nilai node l1 dan l2, kalo gak ada dianggap 0)
        int sums = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0);
        
        // Buat node baru dengan digit satuan hasil penjumlahan
        ListNode* newnode = new ListNode(sums % 10);
        head = newnode;

        // Geser ke node berikutnya di l1 dan l2 kalo ada
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;

        // Tangani carry (kalo ada digit puluhan)
        if (sums / 10 != 0)
        {
            // Tambahin 1 ke node berikutnya di l1 atau l2, kalo gak ada buat node baru
            if (l1)
                l1->val += 1;
            else if (l2)
                l2->val += 1;
            else 
            {
                ListNode* tempnode = new ListNode(1);
                head->next = tempnode;
            }    
        }
        
        // Rekursif panggil fungsi buat proses node berikutnya
        if (l1 || l2)
        {
            head->next = addTwoNumbers(l1, l2);
        }
        return head;  // Balikin head hasil linked list penjumlahan
    }
};
```
