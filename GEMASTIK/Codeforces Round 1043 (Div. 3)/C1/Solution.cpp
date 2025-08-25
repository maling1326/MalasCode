#include <bits/stdc++.h>
using namespace std;

/* clang-format on */
/*------------------*/
#pragma alias
using vi                  = vector<int>;
using vvi                 = vector<vi>;
using vs                  = vector<string>;
using vvs                 = vector<vs>;
using vc                  = vector<char>;
using vvc                 = vector<vc>;
using ll                  = long long;
using ld                  = long double;
constexpr long long   MOD = 1e9 + 7;
constexpr long double PI  = 3.14159265358979323846264338327950288L;

#pragma macro
#define rep(i, n)     for(int i = 0; i < (n); ++i)
#define rep1(i, n)    for(int i = 1; i <= (n); ++i)
#define rev(i, n)     for(int i = (n) - 1; i >= 0; --i)
#define rev1(i, n)    for(int i = (n); i > 0; --i)
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define each(it, v)   for(auto& it : v)
#define isOdd(x)      ((x) % 2)
#define sz(v)         ((int)(v).size())
#define add(a, b)     (((a) % MOD + (b) % MOD) % MOD)
#define sub(a, b)     (((a) % MOD - (b) % MOD + MOD) % MOD)
#define mul(a, b)     (((a) % MOD * (b) % MOD) % MOD)
#define inv(n)        power(n, MOD - 2)
#define ceilDiv(a, b) (((a) + (b) - 1) / (b))
#define pqmax         priority_queue<int>
#define pqmin         priority_queue<int, vector<int>, greater<int>>
#define mtx(m, n)     ((n == 1) ? "\n[" : "["), delim((m), " ]\n[ "), "]"

#pragma setup
static const auto __PROGRAM_START_TIME = chrono::steady_clock::now();
static const auto __SET_IO             = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

#pragma dbg
#ifdef LOCAL_DBG
    #define Redirect(data) Redirector redirector_##__LINE__(data)
    #define scope(...)     ::Tracer scope_tracer_##__LINE__(__VA_ARGS__)
    #define debug(...)     ::Dbg(#__VA_ARGS__, __VA_ARGS__)
#else
    #define Redirect(...)
    #define debug(...)
    #define scope(...)
#endif
#define input(...)    ::Reader::read(__VA_ARGS__)
#define output(...)   ::Writer::write(__VA_ARGS__)
#define outputln(...) ::Writer::writeln(__VA_ARGS__)
#define delim(c, d)   DelimitedContainer(c, d)

/* clang-format off */
#pragma dbg origin
namespace {
namespace color { constexpr string_view O0m {"\033[0m"}, O31m {"\033[31m"}, O32m {"\033[32m"}, O33m {"\033[33m"}, O34m {"\033[34m"}, O35m {"\033[35m"}, O36m {"\033[36m"}, O90m {"\033[90m"}; }
inline int DEBUG_INDENT_LEVEL = 0; void print_indent() { for(int i = 0; i < DEBUG_INDENT_LEVEL; ++i) cerr << " "; } template <typename T> constexpr string_view type_name() { constexpr string_view prefix = "with T = ", suffix = "; "; return "unknown_type"; } template <typename T> void Render(stringstream&, const T&); template <typename T> concept is_iterable = requires(T t) { t.begin(); t.end(); } && ! is_same_v<T, string>; template <typename T> concept is_2d_iterable = is_iterable<T> && is_iterable<typename T::value_type>; string get_indent_string() { return string(DEBUG_INDENT_LEVEL * 2, ' '); } void Render(stringstream& ss, const char* t) { ss << '"' << t << '"'; } void Render(stringstream& ss, const string& t) { Render(ss, t.c_str()); } void Render(stringstream& ss, char t) { ss << '\'' << t << '\''; } void Render(stringstream& ss, bool t) { ss << (t ? "true" : "false"); } template <typename T> void Render(stringstream& ss, T* p) { if(p) { ss << p << " -> "; Render(ss, *p); } else { ss << "nullptr"; } } template <typename T> void Render(stringstream& ss, const unique_ptr<T>& p) { Render(ss, p.get()); } template <typename T> void Render(stringstream& ss, const shared_ptr<T>& p) { Render(ss, p.get()); } template <typename T, typename U> void Render(stringstream& ss, const pair<T, U>& p) { ss << "{"; Render(ss, p.first); ss << ","; Render(ss, p.second); ss << "}"; } template <typename... T> void Render(stringstream& ss, const tuple<T...>& t) { ss << "{"; apply( [&](const auto&... args) { bool first = true; ((ss << (first ? "" : ","), Render(ss, args), first = false), ...); }, t); ss << "}"; } template <is_iterable T> void Render(stringstream& ss, const T& container) { ss << "{"; bool first = true; for(const auto& element : container) { if(! first) ss << ","; Render(ss, element); first = false; } ss << "}"; } template <typename T> void Render(stringstream& ss, const T& value) { if constexpr(is_enum_v<T>) ss << static_cast<underlying_type_t<T>>(value); else ss << value; } void Render(stringstream& ss, const is_2d_iterable auto& matrix) { string base_indent = get_indent_string(); ss << "[" << matrix.size() << "x" << (matrix.empty() ? 0 : matrix.begin()->size()) << "]\n"; bool first_row = true; for(const auto& row : matrix) { if(! first_row) ss << "\n"; ss << base_indent << " "; bool first_col = true; for(const auto& cell : row) { if(! first_col) ss << " "; stringstream cell_ss; Render(cell_ss, cell); string cell_str = cell_ss.str(); if(cell_str.length() >= 2 && cell_str.front() == '\'' && cell_str.back() == '\'') { ss << cell_str.substr(1, cell_str.length() - 2); } else { ss << cell_str; } first_col = false; } first_row = false; } ss << "\n" << base_indent; }
struct Dbg { private: static string_view get_name(string_view& names) { int balance = 0; size_t split_pos = string_view::npos; for(size_t i = 0; i < names.length(); ++i) { char c = names[i]; if(c == '(' || c == '{' || c == '<') { balance++; } else if(c == ')' || c == '}' || c == '>') { balance--; } else if(c == ',' && balance == 0) { split_pos = i; break; } } auto name = names.substr(0, split_pos); names = (split_pos == string_view::npos) ? "" : names.substr(split_pos + 1); name.remove_prefix( min(name.find_first_not_of(" \t\n\r"), name.size())); return name; } template <typename... Vars> void print_vars(string_view& names_sv, Vars&&... vars) { bool first = true; auto print_one = [&](const auto& v) { if(! first) cerr << color::O90m << ", " << color::O0m; cerr << color::O33m << get_name(names_sv) << color::O90m << ": " << color::O0m; stringstream value_ss; Render(value_ss, v); cerr << value_ss.str(); first = false; }; (print_one(vars), ...); } public: template <typename... Args> Dbg(const char* names, Args&&... args) { print_indent(); string_view names_sv = names; auto args_tuple = forward_as_tuple(args...); if constexpr(sizeof...(Args) > 0) { using FirstArg = decay_t<tuple_element_t<0, tuple<Args...>>>; if constexpr(is_same_v<FirstArg, const char*>) { string_view title = get<0>(args_tuple); cerr << color::O90m << "[ " << color::O34m << title << color::O90m << " ] " << color::O0m; if constexpr(sizeof...(Args) > 1) { size_t comma_pos = names_sv.find(','); names_sv = (comma_pos != string_view::npos) ? names_sv.substr(comma_pos + 1) : ""; apply( [&](auto&&, auto&&... rest) { print_vars(names_sv, rest...); }, args_tuple); } } else { cerr << color::O90m << "[ " << color::O34m << "DEBUG" << color::O90m << " ] " << color::O0m; print_vars(names_sv, args...); } } else { cerr << color::O90m << "[ " << color::O34m << "DEBUG" << color::O90m << " ]" << color::O0m; } cerr << '\n'; } };

struct Tracer { string_view name; chrono::steady_clock::time_point start_time; Tracer(string_view n) : name(n) , start_time(chrono::steady_clock::now()) { print_indent(); cerr << color::O90m << "[ > " << color::O35m << name << color::O90m << " ]" << color::O0m << '\n'; DEBUG_INDENT_LEVEL++; } ~Tracer() { DEBUG_INDENT_LEVEL--; auto end_time = chrono::steady_clock::now(); auto duration = chrono::duration_cast<chrono::milliseconds>( end_time - start_time); print_indent(); cerr << fixed; cerr << color::O90m << "[ < " << color::O35m << name << color::O90m << " ] @ " << color::O32m << duration.count() << "ms taken" << color::O0m << '\n'; } }; template <typename Container> struct DelimitedContainer { const Container& container; const char* delimiter; };
struct Reader { template <typename... Args> static void read(Args&... args) { (read_one(args), ...); } private: template <typename T> static void read_one(T& arg) { if constexpr(is_same_v<T, char>) { char c = getchar(); while(isspace(c)) c = getchar(); arg = c; } else if constexpr(is_integral_v<T> && ! is_same_v<T, char>) { arg = 0; char c = getchar(); bool negative = false; while(c < '0' || c > '9') { if(c == '-') negative = true; c = getchar(); } while(c >= '0' && c <= '9') { arg = arg * 10 + (c - '0'); c = getchar(); } if(negative) arg = -arg; } else if constexpr(is_same_v<T, string>) { arg.clear(); int c = getchar(); while(isspace(c) && c != '\n' && c != '\r') c = getchar(); if(c == EOF) return; while(c != '\n' && c != '\r' && c != EOF) {  arg += (char)c; c = getchar(); } }else if constexpr(is_iterable<T>) { for(auto& element : arg) read_one(element);} } };
struct Redirector { const char* filename = "_local_input.txt"; Redirector(string data) { ofstream out(filename); replace(data.begin(), data.end(), '#', '\n'); out << data; out.close(); freopen(filename, "r", stdin); } ~Redirector() { fclose(stdin); remove(filename); } };
template <typename Test, template <typename...> class Ref> struct is_specialization : false_type {}; template <template <typename...> class Ref, typename... Args> struct is_specialization<Ref<Args...>, Ref> : true_type {};
struct Writer { public: template <typename... Args> static void write(const Args&... args) { bool first = true; auto writer = [&](const auto& arg) { if(! first) write_char(' '); print_h(arg); first = false; }; (writer(args), ...); } template <typename... Args> static void writeln(const Args&... args) { write(args...); write_char('\n'); } private: inline static char buffer[1 << 20]; inline static int pos = 0; struct Flusher { ~Flusher() { flush(); } }; inline static Flusher flusher; static void flush() { if(pos > 0) { fwrite(buffer, 1, pos, stdout); pos = 0; } } static void write_char(char c) { if(pos == sizeof(buffer)) flush(); buffer[pos++] = c; } static void write_str(const char* s) { for(int i = 0; s[i] != '\0'; ++i) write_char(s[i]); } template <typename T> static void print_h(const T& arg) { if constexpr(is_specialization<T, DelimitedContainer>::value) { bool first = true; for(const auto& element : arg.container) { if(! first) print_h(arg.delimiter); print_h(element); first = false; } } else if constexpr(is_same_v<T, string>) { write_str(arg.c_str()); } else if constexpr(is_convertible_v<T, const char*>) { write_str(arg); } else if constexpr(is_same_v<T, char>) { write_char(arg); } else if constexpr(is_iterable<T>) { bool first = true; for(const auto& e : arg) { if(not first) write_char(' '); print_h(e); first = false; } } else if constexpr(requires { get<0>(arg); }) { apply( [](const auto&... elems) { bool first = true; auto print_tup = [&](const auto& e) { if(! first) write_char(' '); print_h(e); first = false; }; (print_tup(elems), ...); }, arg); } else { auto s = to_string(arg); write_str(s.c_str()); } } }; }
/*-----------------*/
/* clang-format on */

// vvi stringTo2Dvvi (const std::string& text) {
//     vvi ans;
//     int i = -1; // row index
//     int begin = 0;

//     for (int k = 1; k < (int)text.size(); ++k) {
//         if (text[k] == '[') {
//             ans.push_back(vi()); // start new row
//             ++i;
//             begin = k + 1;
//         }
//         else if (text[k] == ',' || text[k] == ']') {
//             if (begin < k) { // something to convert
//                 std::string numStr = text.substr(begin, k - begin);
//                 // Trim spaces from numStr
//                 int start = 0;
//                 int end = (int)numStr.size() - 1;
//                 while (start <= end && numStr[start] == ' ') ++start;
//                 while (end >= start && numStr[end] == ' ') --end;
//                 if (start <= end) {
//                     int num = std::stoi(numStr.substr(start, end - start + 1));
//                     ans[i].push_back(num);
//                 }
//             }
//             begin = k + 1;
//         }
//     }
//     return ans;
// }

// vvs stringTo2Dvvs (const std::string& text) {
//     vvs ans;
//     int i = -1; // row index
//     int begin = 0;

//     for (int k = 1; k < (int)text.size() - 1; ++k) {
//         if (text[k] == '[') {
//             ans.push_back(vs()); // start new row
//             ++i;
//             begin = k + 1;
//         }
//         else if (text[k] == ',' || text[k] == ']') {
//             std::string substr = text.substr(begin, k - begin);
//             // trim spaces
//             int start = 0, end = (int)substr.size() - 1;
//             while (start <= end && substr[start] == ' ') ++start;
//             while (end >= start && substr[end] == ' ') --end;
//             if (start <= end) {
//                 ans[i].push_back(substr.substr(start, end - start + 1));
//             }
//             begin = k + 1;
//         }
//     }
//     return ans;
// }

/*
#######################################
||        Usefull tips or Memo         |
=======================================
/ ---            MEMO             --- \
How to make function for printing default array?
-> cparr
How to call function for printing default array?
-> parr
How to make function for printing 2D Vector?
-> cpvec2D
How to call function for printing 2D Vector?
-> pvec2D
How to make function for change data type from string to vector string?
-> strtostr
How to make function for change data type from string to vector number?
-> strtonum
How to make function for change data type from string to 2D vector?
-> strto2dnum
How to Debug Boolean Function in Solutions ?
-> stestbool
How to Call Boolean Function in Main ?
-> testbool

/ ---       List Acronyms        --- \
ll = long long
vi = vector<int>

/ ---       List Acronyms        --- \
how to check array size?
-> int size = sizeoff(arr) / sizeof(arr[0]);
how to set seed for rand? how to srand()? how to srand based by time?
-> srand(time(0));
how to output random number?
-> rand() % N;
how to use 2D vector array?
-> vector<vector<int>>
=======================================
||        End of Tips or Memo          |
#######################################
*/

#include <iostream>
#include <vector>
#include <cmath>

// Pre-compute powers of 3 to avoid using std::pow and floating-point issues
// Maximum x for n=10^9 is around 19, so 25 is safe.
std::vector<long long> powers_of_3(25);

void precompute_powers() {
    powers_of_3[0] = 1;
    for (int i = 1; i < 25; ++i) {
        powers_of_3[i] = powers_of_3[i - 1] * 3;
    }
}

void solve() {
    long long n;
    std::cin >> n;

    long long total_cost = 0;
    long long x = 0; // Represents the power, 3^x

    while (n > 0) {
        // Get the last digit in the base-3 representation of n
        int digit = n % 3;

        if (digit > 0) {
            long long cost_per_deal;
            // Calculate the cost for a single deal of size 3^x
            if (x == 0) {
                // Formula: 3^(0+1) + 0 * 3^(-1) = 3
                cost_per_deal = 3;
            } else {
                // Formula: 3^(x+1) + x * 3^(x-1)
                cost_per_deal = powers_of_3[x + 1] + x * powers_of_3[x - 1];
            }
            // Add the cost for 'digit' number of such deals
            total_cost += (long long)digit * cost_per_deal;
            debug(total_cost, digit, cost_per_deal, x, n);
        }

        // Move to the next digit
        n /= 3;
        x++;
    }
    std::cout << total_cost << std::endl;
}

int main() {
    Redirect(R"(7#1#3#8#2#10#20#260010000)");
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute_powers();

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}