/*
* ░       ░░░        ░░        ░░░      ░░░  ░░░░  ░░        ░░   ░░░  ░
* ▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒   ▒▒   ▒▒▒▒▒  ▒▒▒▒▒    ▒▒  ▒
* ▓  ▓▓▓▓  ▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓  ▓▓▓▓  ▓▓        ▓▓▓▓▓  ▓▓▓▓▓  ▓  ▓  ▓
* █  ████  █████  █████  ████  ██        ██  █  █  █████  █████  ██    █
* █       ███        ███      ███  ████  ██  ████  ██        ██  ███   █

* ░       ░░░  ░░░░  ░░  ░░░░  ░░░      ░░░  ░░░░  ░
* ▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒▒  ▒▒  ▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒
* ▓       ▓▓▓  ▓▓▓▓  ▓▓▓▓    ▓▓▓▓  ▓▓▓▓  ▓▓        ▓
* █  ████  ██  ████  █████  █████        ██  ████  █
* █       ████      ██████  █████  ████  ██  ████  █
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int BUFFER_SIZE = 12;
    /* @alias     */ namespace {

        using ll      = long long;
        using ld      = long double;
        using vi      = vector<int>;
        using vvi     = vector<vi>;
        using vll     = vector<ll>;
        using vb      = vector<bool>;
        using pii     = pair<int, int>;
        using vpii    = vector<pii>;
        
    } /* namespace */

    /* @setup     */ namespace {
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#pragma GCC optimize("O3,unroll-loops")
        static const auto __SET_IO
          = [] {
                ios_base::sync_with_stdio(false);
                cin.tie(NULL);
                return 0;
            }();
    } /* namespace */

    /* @macro     */ namespace {
#define all(v)  v.begin(), v.end()
#define pb push_back
#define eb      emplace_back
#define mp      make_pair
#define Solution                                                               \
    int main()
    } /* namespace */

void solve(vi y) {
    if (y.size() == 1)
        cout << y[0];

    sort(all(y));
    string res = "";
    int lf = y[0], rg = y[0];
    for (int i = 1; i < y.size(); ++i) {
        if (y[i] == y[i-1]){
            continue;
        }
        
        if (y[i] == y[i-1] + 1){    
            rg = y[i];
        }

        else if (lf == rg){
            res += to_string(lf) + ',';
            rg = y[i];
            lf = rg;

        }
        else {
            res += to_string(lf) + '-' + to_string(rg) + ',';
            rg = y[i];
            lf = rg;
        }
    }
    if (lf == rg){
            res += to_string(lf);
    }
    else {
            res += to_string(lf) + '-' + to_string(rg);
    }

    cout << res;
}


Solution {
    vector vec = {1,2,3};
    int sk20 = ssize(vec);
    int siz = (cin >> siz, siz);
    vi v(siz);
    for (int i = 0; i < v.size(); ++i) {
        int pp = (cin >> pp, pp);
        v[i] = pp;
    }
    
    solve(v);
    return 0;
}
