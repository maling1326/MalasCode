# 📝 Penjelasan Fungsi `JUDULDISINI` - Leetcode `SOALKEBERAPA`

<!--Deskripsi atau penjelasan fungsi code -->

## ❓ Soal

<!--link Soal-->
<!-- Menjelaskan soal dengan ringkas, atau intinya saja -->

## 🔗 Penjelasan fungsi berdasarkan Soal yang diberikan

<!-- Penjelasan sangkut paut Code dengan soalnya, misal bagian ini berhubungan dengan soal bagian ini -->

## 💡 Inti

<!-- Inti code nya -->

## ⚙️ Cara kerja

<!-- Menjelaskan bagaimana cara kerjanya code yang aku buat dengan analogi yang mudah dipahami -->

## 📦 Contoh

<!-- contoh input dari code nya, bisa input, penjelasan singkat stepnya, output -->

## 📊 Complexity

### ⏱️ Time Complexity = `O()`

<!-- Penjelasan singkat time complexity -->

### 🗂️ Space Complexity = `O()`

<!-- Penjelasan singkat space complexity -->

## 💻 Code

```cpp []
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res (numRows);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                res[i].emplace_back(1);
                continue;
            }
            res[i].emplace_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
    }
    return res;
}
```
