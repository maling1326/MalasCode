/*
* ░       ░░░        ░░        ░░░      ░░░  ░░░░  ░░        ░░   ░░░  ░
* ▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒   ▒▒   ▒▒▒▒▒  ▒▒▒▒▒    ▒▒  ▒
* ▓  ▓▓▓▓  ▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓  ▓▓  ▓▓▓▓  ▓▓        ▓▓▓▓▓  ▓▓▓▓▓  ▓  ▓  ▓
* █  ████  █████  █████  ████  ██        ██  █  █  █████  █████  ██    █
* █       ███        ███      ███  ████  ██  ████  ██        ██  ███   █

* ░       ░░░  ░░░░  ░░  ░░░░  ░░░      ░░░  ░░░░  ░
* ▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒▒  ▒▒  ▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒
* ▓       ▓▓▓  ▓▓▓▓  ▓▓▓▓    ▓▓▓▓  ▓▓▓▓  ▓▓        ▓
* █  ████  ██  ████  █████  █████        x██  ████  █
* █       ████      ██████  █████  ████  ██  ████  █
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int BUFFER_SIZE = 16;
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
}

Solution {
    unordered_map<string,string> tables = {{"AA", "BB"}, {"AB", "CA"}, {"AC", "BC"}, {"AD", "DC"},
                                           {"BA", "DA"}, {"BB", "AA"}, {"BC", "BD"}, {"BD", "AB"},
                                           {"CA", "AD"}, {"CB", "CD"}, {"CC", "CB"}, {"CD", "BA"},
                                           {"DA", "DD"}, {"DB", "CC"}, {"DC", "DB"}, {"DD", "AC"},};

    unordered_map<string,string> tables2 = {{"BB", "AA"}, {"CA", "AB"}, {"BC", "AC"}, {"DC", "AD"},
                                           {"DA", "BA"}, {"AA", "BB"}, {"BD", "BC"}, {"AB", "BD"},
                                           {"AD", "CA"}, {"CD", "CB"}, {"CB", "CC"}, {"BA", "CD"},
                                           {"DD", "DA"}, {"CC", "DB"}, {"DB", "DC"}, {"AC", "DD"},};
    string txt;
    cin >> txt;x
    for (int i = 0; i < txt.size(); i += 2) {
        cout << tables2[txt.substr(i, 2)];
    }
    return 0;
}
