#include <bits/stdc++.h>
using namespace std;

/* clang-format off */
/*------------------*/
/* #define DEBUG_NO_COLOR */
#define DEBUG_LINE_WIDTH    90
#define DEBUG_MAX_VALUE_LEN 4'096
#ifndef ONLINE_JUDGE
#define debug(...) ::Debugger (__FILE__, __LINE__, #__VA_ARGS__, __VA_ARGS__)
#define debugln(...) ::DebuggerHorizontal (__FILE__, __LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugln(...)
#endif
#define input(...) ::InputReader::read(__VA_ARGS__)
#define output(...) ::OutputWriter::write(__VA_ARGS__)
#define outputln(...) ::OutputWriter::writeln(__VA_ARGS__)
#define rep(i, n)   for(int i = 0; i < (n); ++i)
#define rep1(i, n)  for(int i = 1; i <= (n); ++i)
#define rev(i, n)   for(int i = (n) - 1; i >= 0; --i)
#define all(v)      v.begin(), v.end()
#define each(it, v) for(auto& it : v)
#define sz(v)       ((int)(v).size())
namespace {
#if defined(DEBUG_NO_COLOR)
namespace color {constexpr string_view _rs{""},_r{""},_g{""},_y{""},_b{""},_m{""},_c{""},_gr{""};}
#else
namespace color {constexpr string_view _rs{"\033[0m"},_r{"\033[31m"},_g{"\033[32m"},_y{"\033[33m"},_b{"\033[34m"},_m{"\033[35m"},_c{"\033[36m"},_gr{"\033[90m"};}
#endif
template <typename T> constexpr string_view type_name() {
#if defined(__clang__) || defined(__GNUC__)
constexpr string_view function = __PRETTY_FUNCTION__;
#if defined(__clang__)
constexpr string_view prefix{"[T = "},suffix{"]"};
#else
constexpr string_view prefix{"with T = "},suffix{"; "};
#endif
const auto start{function.find(prefix) + prefix.size()},end{function.find(suffix, start)}; return function.substr(start, end - start);
#elif defined(_MSC_VER)
constexpr string_view function{__FUNCSIG__},prefix{"type_name<"},suffix{">(void)"}; const auto start{function.find(prefix) + prefix.size()},end{function.find(suffix, start)}; return function.substr(start, end - start);
#else
return "unknown_type";
#endif
} template <typename T> void _render (stringstream&, const T&); template <typename T> concept is_iterable = requires (T t) {t.begin();t.end();} && !is_same_v<T, string>; void _render (stringstream& ss, const char* t) {ss << '"' << t << '"';} void _render (stringstream& ss, const string& t) {_render (ss, t.c_str());} void _render (stringstream& ss, char t) {ss << '\'' << t << '\'';} void _render (stringstream& ss, bool t) {ss << (t ? "true" : "false");} template <typename T> void _render (stringstream& ss, T* p) {if (p) {ss << p << " -> ";_render (ss, *p);} else ss << "nullptr";} template <typename T> void _render (stringstream& ss, const unique_ptr<T>& p) {_render (ss, p.get());} template <typename T> void _render (stringstream& ss, const shared_ptr<T>& p) {_render (ss, p.get());} template <typename T, typename U> void _render (stringstream& ss, const pair<T, U>& p) {ss << "{"; _render (ss, p.first); ss << ","; _render (ss, p.second); ss << "}";} template <typename... T> void _render (stringstream& ss, const tuple<T...>& t) {ss << "{";apply ([&](const auto&... args) {bool first = true;((ss << (first ? "" : ","),_render (ss, args),first = false),...);},t);ss << "}";} template <is_iterable T> void _render (stringstream& ss, const T& container) {ss << "{"; bool first = true; for (const auto& element : container) { if(!first) ss << ","; _render (ss, element); first = false;} ss << "}";} template <typename T> void _render (stringstream& ss, const T& value) {if constexpr (is_enum_v<T>) ss << static_cast<underlying_type_t<T>> (value); else ss << value;}  struct Debugger { public:  template <typename... Args> Debugger (const char* file, int line, const char* names, Args&&... args) { string_view file_name = string_view (file).substr (string_view (file).find_last_of ("/\\") + 1); string_view names_sv = names;  auto print_the_vars = [&](auto&&... vars_tuple_elements) { if constexpr (sizeof...(vars_tuple_elements) > 0) { print_vars(1, names_sv, forward<decltype(vars_tuple_elements)>(vars_tuple_elements)...); } }; if constexpr (sizeof...(Args) > 0) {  using FirstArg = decay_t<tuple_element_t<0, tuple<Args...>>>; if constexpr (is_same_v<FirstArg, const char*>) { auto args_tuple = forward_as_tuple(args...); string_view title = get<0>(args_tuple); cerr << color::_gr << "+-[ " << color::_b << title << color::_gr << " ] @ " << color::_c << file_name << color::_gr << ":" << color::_c << line << "\n";  size_t comma_pos = names_sv.find(','); names_sv = (comma_pos != string_view::npos) ? names_sv.substr(comma_pos + 1) : "";  apply([&](auto&&, auto&&... rest) { print_the_vars(forward<decltype(rest)>(rest)...);}, args_tuple); } else {  cerr << color::_gr << "+-[ " << color::_b << "DEBUG" << color::_gr << " ] @ " << color::_c << file_name << color::_gr << ":" << color::_c << line << "\n"; print_vars(1, names_sv, forward<Args>(args)...); } } else {  cerr << color::_gr << "+-[ " << color::_b << "DEBUG" << color::_gr << " ] @ " << color::_c << file_name << color::_gr << ":" << color::_c << line << "\n"; } cerr << color::_gr << "+-" << string (DEBUG_LINE_WIDTH > 2 ? DEBUG_LINE_WIDTH - 2 : 0, '-') << color::_rs << endl; } private: string_view get_name (string_view& names) {size_t pos{names.find(',')}; auto name{names.substr (0, pos)}; names = (pos == string_view::npos) ? "" : names.substr (pos + 1); name.remove_prefix (min (name.find_first_not_of (" \t\n\r"), name.size())); return name;} template <typename T> void print_details (const T& v) {using D = decay_t<T>; cerr << color::_gr << "[sizeof: " << sizeof (v) << "B"; if constexpr (is_integral_v<D>) cerr << ", integral"; if constexpr (is_floating_point_v<D>) cerr << ", float"; if constexpr (is_pointer_v<D> || requires { v.get(); }) cerr << ", pointer"; if constexpr (is_enum_v<D>) cerr << ", enum"; if constexpr (is_class_v<D> && ! is_same_v<D, string>) cerr << ", class"; if constexpr (is_signed_v<D>) cerr << ", signed"; if constexpr (requires { v.size(); }) cerr << ", size: " << v.size(); if constexpr (requires { v.capacity(); }) cerr << ", capacity: " << v.capacity(); if constexpr (requires { v.use_count(); }) cerr << ", use_count: " << v.use_count(); cerr << "]"; } void print_wrapped (const string& text) {const size_t prefix_len{9}, wrap_prefix_len{9}; size_t available_width{DEBUG_LINE_WIDTH > prefix_len ? DEBUG_LINE_WIDTH - prefix_len : 0}; if (text.length() <= available_width) { cerr << text; return; } cerr << text.substr (0, available_width); size_t current_pos = available_width; while (current_pos < text.length()) {cerr << "\n" << color::_gr << "|    | " << color::_rs; available_width = DEBUG_LINE_WIDTH > wrap_prefix_len ? DEBUG_LINE_WIDTH - wrap_prefix_len : 0; size_t len_to_print = min (available_width, text.length() - current_pos); cerr << text.substr (current_pos, len_to_print); current_pos += len_to_print;} } template <typename T> void print_single (int count, string_view name, T&& v) { cerr << color::_gr << "| " << color::_c << setw (2) << count << color::_gr << " | " << color::_y << name << color::_gr << " : " << color::_m << type_name<decay_t<T>>() << color::_rs << "\n"; cerr << color::_gr << "|    | " << color::_rs; print_details (forward<T> (v)); cerr << "\n"; cerr << color::_gr << "|    | " << color::_rs; stringstream value_ss; _render (value_ss, forward<T> (v)); string value_str = value_ss.str(); if (value_str.length() > DEBUG_MAX_VALUE_LEN) {value_str = value_str.substr (0, DEBUG_MAX_VALUE_LEN) + "...}";} print_wrapped (value_str); cerr << "\n";}  void print_vars(int, string_view&) {} template <typename T, typename... Args> void print_vars (int count, string_view& names, T&& v, Args&&... args) { print_single (count, get_name (names), forward<T> (v)); if constexpr (sizeof...(Args) > 0) { cerr << color::_gr << "|\n"; print_vars (count + 1, names, forward<Args> (args)...);}} };  struct DebuggerHorizontal { public:  template <typename... Args> DebuggerHorizontal (const char* file, int line, const char* names, Args&&... args) { string_view file_name = string_view (file).substr (string_view (file).find_last_of ("/\\") + 1); string_view names_sv = names;  auto print_vars_h = [&](auto&&... vars) { bool first = true; auto print_one = [&](const auto& v) { if (!first) { cerr << color::_gr << ", " << color::_rs; } cerr << color::_y << get_name(names_sv) << color::_gr << ": " << color::_rs; stringstream value_ss; _render(value_ss, v); cerr << value_ss.str(); first = false; }; (print_one(vars), ...); }; if constexpr (sizeof...(Args) > 0) { using FirstArg = decay_t<tuple_element_t<0, tuple<Args...>>>; if constexpr (is_same_v<FirstArg, const char*>) { auto args_tuple = forward_as_tuple(args...); string_view title = get<0>(args_tuple); cerr << color::_gr << "[ " << color::_b << title << color::_gr << " ] @ " << color::_c << file_name << color::_gr << ":" << color::_c << line << color::_gr << " | " << color::_rs; size_t comma_pos = names_sv.find(','); names_sv = (comma_pos != string_view::npos) ? names_sv.substr(comma_pos + 1) : ""; apply([&](auto&&, auto&&... rest) { print_vars_h(forward<decltype(rest)>(rest)...); }, args_tuple); } else { cerr << color::_gr << "[ " << color::_b << "DEBUG" << color::_gr << " ] @ " << color::_c << file_name << color::_gr << ":" << color::_c << line << color::_gr << " | " << color::_rs; print_vars_h(forward<Args>(args)...); } } else { cerr << color::_gr << "[ " << color::_b << "DEBUG" << color::_gr << " ] @ " << color::_c << file_name << color::_gr << ":" << color::_c << line << color::_gr << " | " << color::_rs; } cerr << color::_rs << endl; } private:  string_view get_name (string_view& names) { size_t pos{names.find(',')}; auto name{names.substr (0, pos)}; names = (pos == string_view::npos) ? "" : names.substr (pos + 1); name.remove_prefix (min (name.find_first_not_of (" \t\n\r"), name.size())); return name; } };
struct InputReader {  template <typename... Args> static void read(Args&... args) { (read_one(args), ...); }private: template <typename T> static void read_one(T& arg) { if constexpr(is_iterable<T>) { for(auto& element : arg) read_one(element); } else if constexpr(requires { get<0>(arg); }) { apply([](auto&... elems) { read(elems...); }, arg); } else { cin >> arg; } }};} /* namespace */
struct OutputWriter { template<typename... Args> static void writeln(const Args&... args) { bool first = true; auto print = [&](const auto& arg) { if (!first) cout << " "; first = false; print_item_h(arg); }; (print(args), ...); cout << "\n"; } template<typename... Args> static void write(const Args&... args) { (print_item_v(args), ...); }private: template<typename T> static void print_item_h(const T& arg) { if constexpr (is_iterable<T>) { bool first = true; for (const auto& e : arg) { if (!first) cout << " "; first = false; print_item_h(e); } } else if constexpr (requires { get<0>(arg); }) { apply([](const auto&... elems){ bool first = true; auto print = [&](const auto& e){ if (!first) cout << " "; first = false; print_item_h(e); }; (print(elems), ...); }, arg); } else { cout << arg; } } template<typename T> static void print_item_v(const T& arg) { if constexpr (is_iterable<T>) { for (const auto& e : arg) { print_item_v(e); } } else if constexpr (requires { get<0>(arg); }) { apply([](const auto&... elems){ (print_item_v(elems), ...); }, arg); } else { cout << arg << "\n"; } }};
/*-----------------*/
/* clang-format on */

/*    Text Formatting    */
/*-----------------------*/
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

#define BOLD      "\033[1m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[6m"

#define RESET   "\033[0m"

#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";
/*-----------------------*/
/*    Text Formatting    */

/*  Default Function  */
/*--------------------*/
class Stopwatch {
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> start_time;
    bool running = false;

public:
    // Mulai stopwatch
    void start() {
        start_time = clock::now();
        running = true;
    }

    // Hentikan stopwatch dan kembalikan durasi dalam milidetik
    int stop() {
        if (!running) {std::cout << "Total Runtime : " << GREEN << 0; RESETL NewLine} // Jika belum start, kembalikan 0
        auto end_time = clock::now();
        running = false;
        // Hitung durasi dalam milidetik
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        return duration.count();
    }
};

// void PrintArr (string text, int arr[], int max) {
//     cout << text << " : [";
//     for (int i = 0; i < max; i++)
//         cout << GREEN << arr[i] << RESET << ",";
//     cout << "]";
// }

template <typename T>
// void print2DVector (string text, vector<vector<T>> vec) {
//     cout << text << " : [";
//     for (int i = 0; i < vec.size(); i++) {
//         cout << "[";
//         for (auto D1 : vec[i])
//             cout << GREEN << D1 << RESET << ",";
//         cout << "]";
//         if (i != vec.size() - 1)
//             cout << ",";
//     }
//     cout << "]";
// }

// vector<int> stringToIntegerVector(string text) {
//     int begin = 0;
//     vector<int> result;
//     for (int i = 0; i < text.size(); i++) {
//         if (text[i] == ',' || text[i] == ' ') {
//             if (i > begin) {  // avoid empty substrings
//                 result.push_back(stoi(text.substr(begin, i - begin)));
//             }
//             begin = i + 1;  // move begin to the character after the delimiter
//         }
//         if (i == text.size() - 1) {
//             if (i >= begin) {
//                 result.push_back(stoi(text.substr(begin, i - begin + 1)));
//             }
//         }
//     }
//     return result;
// }

// vector<string> stringToStringVector(string text) {
//     int begin = 0;
//     vector<string> result;
//     for (int i = 0; i < text.size(); i++) {
//         if (text[i] == ',' || text[i] == ' ') {
//             if (i > begin) {  // avoid empty substrings
//                 result.push_back(text.substr(begin, i - begin));
//             }
//             begin = i + 1;  // move begin to the character after the delimiter
//         }
//         if (i == text.size() - 1) {
//             if (i >= begin) {
//                 result.push_back(text.substr(begin, i - begin + 1));
//             }
//         }
//     }
//     return result;
// }
/*--------------------*/
/*  Default Function  */
class Solution {
public:
    // Paste Function here
};

int main() {
    // Stopwatch sw;
    Solution solution;
    
    // sw.start();
    // int time = sw.stop();

    return 0;
}

/*
#######################################
|        Usefull tips or Memo         |
=======================================
how to check array size?
-> int size = sizeoff(arr) / sizeof(arr[0]);
how to set seed for rand? how to srand()? how to srand based by time?
-> srand(time(0));
how to output random number?
-> rand() % N;
how to use 2D vector array?
-> vector<vector<int>>
=======================================
|        End of Tips or Memo          |
#######################################
*/