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

constexpr int BUFFER_SIZE = 16;
#define SCOPE_NONE

#pragma region section
    /* @alias     */ namespace {
        namespace num = numbers;
        namespace R   = ranges;
        namespace V   = views;
        using ll      = long long;
        using ld      = long double;
        using vi      = vector<int>;
        using vvi     = vector<vi>;
        using vll     = vector<ll>;
        using vb      = vector<bool>;
        using pii     = pair<int, int>;
        using vpii    = vector<pii>;

        template <typename T, typename C = less<T>>
        using pq = priority_queue<T, vector<T>, C>;

        [[nodiscard]]
        auto iota(int end) {
            return V::iota(0, end);
        }
        [[nodiscard]]
        auto iota(int start, int end) {
            return V::iota(start, end);
        }

        [[nodiscard]]
        auto riota(int end) {
            return V::iota(0, end) | views::reverse;
        }
        [[nodiscard]]
        auto riota(int start, int end) {
            return V::iota(start, end) | views::reverse;
        }

        [[nodiscard]]
        auto enumerate(auto& range) {
            return V::iota(0u, range.size()) | V::transform([&range](size_t i) {
                       return std::make_pair(i, range[i]);
                   });
        }

        [[nodiscard]]
        auto sliding_window(auto& range, size_t k) {
            return V::iota(0u, ssize(range) - k + 1)
                   | V::transform([&range, k](size_t i) {
                         return span(range.data() + i, k);
                     });
        }

        [[nodiscard]]
        auto adjacent_pairs(auto& range) {
            return V::iota(0u, ssize(range) - 1)
                   | V::transform([&range](size_t i) {
                         return make_pair(range[i], range[i + 1]);
                     });
        }

        [[nodiscard]]
        auto grid_indices(int rows, int cols) {
            return V::iota(0, rows * cols) | V::transform([cols](int i) {
                       return make_pair(i / cols, i % cols);
                   });
        }

        [[nodiscard]]
        auto primes() {
            auto is_prime = [](int n) {
                if(n <= 1)
                    return false;
                for(int i = 2; i * i <= n; ++i)
                    if(n % i == 0) [[unlikely]]
                        return false;
                return true;
            };
            return V::iota(2) | V::filter(is_prime);
        }

    } /* namespace */

    /* @setup     */ namespace {
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#pragma GCC optimize("O3,unroll-loops")
        [[maybe_unused]]
        static const auto __PROGRAM_START_TIME
          = chrono::steady_clock::now();
        [[maybe_unused]]
        static const auto __SET_IO
          = [] {
                ios_base::sync_with_stdio(false);
                cin.tie(NULL);
                return 0;
            }();
    } /* namespace */

    /* @dbg        */ namespace {
#ifdef LOCAL_DBG
    #define Redirect(data) Redirector redirector_##__LINE__(data)
    #define scope(...)     ::Tracer scope_tracer_##__LINE__(__VA_ARGS__)
    #define debug(...)     ::Dbg(#__VA_ARGS__, __VA_ARGS__)
#else
    #define Redirect(...)
    #define debug(...)
    #define scope(...)
#endif
        namespace color {
            constexpr string_view O0m {"\033[0m"}, O31m {"\033[31m"},
              O32m {"\033[32m"}, O33m {"\033[33m"}, O34m {"\033[34m"},
              O35m {"\033[35m"}, O36m {"\033[36m"}, O90m {"\033[90m"};
        }

        inline int DEBUG_INDENT_LEVEL = 0;

        void indentation() {
            for(int i = 0; i < DEBUG_INDENT_LEVEL; ++i)
                cerr << "  ";
        }

        template <typename T>
        constexpr string_view type_name() {
            constexpr string_view prefix = "with T = ", suffix = "; ";
            return "unknown_type";
        }

        template <typename T>
        void Render(stringstream&, const T&);
        template <typename T>
        concept is_iterable = requires(T t) {
                                  t.begin();
                                  t.end();
                              } && ! is_same_v<T, string>;

        template <typename T>
        concept is_2d_iterable
          = is_iterable<T> && is_iterable<typename T::value_type>;

        string get_indent_string() {
            return string(DEBUG_INDENT_LEVEL * 2, ' ');
        }

        void Render(stringstream& ss, const char* t) {
            ss << '"' << t << '"';
        }

        void Render(stringstream& ss, const string& t) {
            Render(ss, t.c_str());
        }

        void Render(stringstream& ss, char t) {
            ss << '\'' << t << '\'';
        }

        void Render(stringstream& ss, bool t) {
            ss << (t ? "true" : "false");
        }

        template <typename T>
        void Render(stringstream& ss, T* p) {
            if(p) {
                ss << p << " -> ";
                Render(ss, *p);
            } else {
                ss << "nullptr";
            }
        }

        template <typename T>
        void Render(stringstream& ss, const unique_ptr<T>& p) {
            Render(ss, p.get());
        }

        template <typename T>
        void Render(stringstream& ss, const shared_ptr<T>& p) {
            Render(ss, p.get());
        }

        template <typename T, typename U>
        void Render(stringstream& ss, const pair<T, U>& p) {
            ss << "{";
            Render(ss, p.first);
            ss << ",";
            Render(ss, p.second);
            ss << "}";
        }

        template <typename... T>
        void Render(stringstream& ss, const tuple<T...>& t) {
            ss << "{";
            apply(
              [&](const auto&... args) {
                  bool first = true;
                  ((ss << (first ? "" : ","), Render(ss, args), first = false),
                   ...);
              },
              t);
            ss << "}";
        }

        template <is_iterable T>
        void Render(stringstream& ss, const T& container) {
            ss << "{";
            bool first = true;
            for(const auto& element : container) {
                if(! first)
                    ss << ",";
                Render(ss, element);
                first = false;
            }
            ss << "}";
        }

        template <typename T>
        void Render(stringstream& ss, const T& value) {
            if constexpr(is_enum_v<T>)
                ss << static_cast<underlying_type_t<T>>(value);
            else
                ss << value;
        }

        void Render(stringstream& ss, const is_2d_iterable auto& matrix) {
            string base_indent = get_indent_string();
            ss << "[" << matrix.size() << "x"
               << (matrix.empty() ? 0 : matrix.begin()->size()) << "]\n";
            bool first_row = true;
            for(const auto& row : matrix) {
                if(! first_row)
                    ss << "\n";
                ss << base_indent << "  ";
                bool first_col = true;
                for(const auto& cell : row) {
                    if(! first_col)
                        ss << " ";
                    stringstream cell_ss;
                    Render(cell_ss, cell);
                    string cell_str = cell_ss.str();
                    if(cell_str.length() >= 2 && cell_str.front() == '\''
                       && cell_str.back() == '\'') {
                        ss << cell_str.substr(1, cell_str.length() - 2);
                    } else {
                        ss << cell_str;
                    }
                    first_col = false;
                }
                first_row = false;
            }
            ss << "\n" << base_indent;
        }

        struct Dbg {
            private:
                static string_view get_name(string_view& names) {
                    int    balance   = 0;
                    size_t split_pos = string_view::npos;
                    for(size_t i = 0; i < names.length(); ++i) {
                        char c = names[i];
                        if(c == '(' || c == '{' || c == '<') {
                            balance++;
                        } else if(c == ')' || c == '}' || c == '>') {
                            balance--;
                        } else if(c == ',' && balance == 0) {
                            split_pos = i;
                            break;
                        }
                    }
                    auto name = names.substr(0, split_pos);
                    names     = (split_pos == string_view::npos)
                                  ? ""
                                  : names.substr(split_pos + 1);
                    name.remove_prefix(
                      min(name.find_first_not_of(" \t\n\r"), name.size()));
                    return name;
                }

                template <typename... Vars>
                void print_vars(string_view& names_sv, Vars&&... vars) {
                    bool first     = true;
                    auto print_one = [&](const auto& v) {
                        if(! first)
                            cerr << color::O90m << ", " << color::O0m;
                        cerr << color::O33m << get_name(names_sv) << color::O90m
                             << ": " << color::O0m;
                        stringstream value_ss;
                        Render(value_ss, v);
                        cerr << value_ss.str();
                        first = false;
                    };
                    (print_one(vars), ...);
                }

            public:
                template <typename... Args>
                Dbg(const char* names, Args&&... args) {
                    indentation();
                    string_view names_sv   = names;
                    auto        args_tuple = forward_as_tuple(args...);

                    if constexpr(sizeof...(Args) > 0) {
                        using FirstArg
                          = decay_t<tuple_element_t<0, tuple<Args...>>>;
                        if constexpr(is_same_v<FirstArg, const char*>) {
                            string_view title = get<0>(args_tuple);
                            cerr << color::O90m << "[ " << color::O34m << title
                                 << color::O90m << " ] " << color::O0m;

                            if constexpr(sizeof...(Args) > 1) {
                                size_t comma_pos = names_sv.find(',');
                                names_sv = (comma_pos != string_view::npos)
                                             ? names_sv.substr(comma_pos + 1)
                                             : "";
                                apply(
                                  [&](auto&&, auto&&... rest) {
                                      print_vars(names_sv, rest...);
                                  },
                                  args_tuple);
                            }
                        } else {
                            cerr << color::O90m << "[ " << color::O34m
                                 << "DEBUG" << color::O90m << " ] "
                                 << color::O0m;
                            print_vars(names_sv, args...);
                        }
                    } else {
                        cerr << color::O90m << "[ " << color::O34m << "DEBUG"
                             << color::O90m << " ]" << color::O0m;
                    }

                    cerr << '\n';
                }
        };

        struct Tracer {
                string_view                      name;
                chrono::steady_clock::time_point start_time;

                Tracer(string_view n)
                    : name(n)
                    , start_time(chrono::steady_clock::now()) {
                    indentation();

#ifndef SCOPE_NONE
                    cerr << color::O90m << "[ > " << color::O35m << name
                         << color::O90m << " ]" << color::O0m << '\n';
                    DEBUG_INDENT_LEVEL++;
#endif // !SCOPE_NONE
                }

                ~Tracer() {
                    DEBUG_INDENT_LEVEL--;

#if not defined(SCOPE_MINIMAL)
    #if not defined(SCOPE_NONE)
                    auto end_time = chrono::steady_clock::now();
                    auto duration = chrono::duration_cast<chrono::milliseconds>(
                      end_time - start_time);

                    indentation();
                    cerr << fixed;
                    cerr << color::O90m << "[ < " << color::O35m << name
                         << color::O90m << " ] @ " << color::O32m
                         << duration.count() << "ms taken" << color::O0m
                         << '\n';
    #endif /* not defined (SCOPE_NONE) */
#endif     /* not defined (SCOPE_MINIMAL) */
                }
        };
        struct Redirector {
                const char* filename = "_local_input.txt";

                Redirector(string data) {
                    ofstream out(filename);
                    replace(data.begin(), data.end(), '#', '\n');
                    out << data;
                    out.close();
                    freopen(filename, "r", stdin);
                }

                ~Redirector() {
                    fclose(stdin);
                    remove(filename);
                }
        };
    } /* namespace */

    /* @io        */ namespace {
#define input         Reader::instance()
#define output(...)   ::Writer::write(__VA_ARGS__)
#define outputln(...) ::Writer::writeln(__VA_ARGS__)
#define delim(c, d)   DelimitedContainer(c, d)

        template <typename Container>
        struct DelimitedContainer {
                const Container& container;
                const char*      delimiter;
        };

        template <typename Test, template <typename...> class Ref>
        struct is_specialization : false_type {};
        template <template <typename...> class Ref, typename... Args>
        struct is_specialization<Ref<Args...>, Ref> : true_type {};

        struct Reader {
            public:
                static Reader& instance() {
                    static Reader reader_instance;
                    return reader_instance;
                }

                template <typename... Args>
                void operator()(Args&... args) {
                    (read_one(args), ...);
                }

                template <typename T>
                [[nodiscard]]
                T get() {
                    return read_value<T>();
                }

                [[nodiscard]]
                string getline() {
                    string line;
                    int    c = getchar();
                    if(c == '\n')
                        c = getchar();
                    while(c != '\n' && c != EOF) {
                        line += (char)c;
                        c = getchar();
                    }
                    if(c == EOF && line.empty() && feof(stdin)) [[unlikely]] {
                        throw runtime_error(
                          "Reader::getline: Unexpected EOF or empty line.");
                    }
                    return line;
                }

                [[nodiscard]]
                vvi get_graph(bool is_1_indexed  = false,
                              bool is_undirected = true) {
                    int n = get<int>();
                    int m = get<int>();
                    vvi adj(is_1_indexed ? n + 1 : n);
                    for(int i = 0; i < m; ++i) {
                        int u = get<int>();
                        int v = get<int>();
                        adj[u].push_back(v);
                        if(is_undirected)
                            adj[v].push_back(u);
                    }
                    return adj;
                }

            private:
                Reader() = default;

                static int skip_space() {
                    int c;
                    while((c = getchar()) != EOF && isspace(c))
                        ;
                    return c;
                }

                template <typename T>
                static void read_one(T& arg) {
                    if constexpr(is_iterable<T> && ! is_same_v<T, string>)
                        for(auto& element : arg)
                            read_one(element);
                    else
                        arg = read_value<T>();
                }

                template <typename T>
                static T read_value() {
                    if constexpr(is_same_v<T, char>) {
                        int c = skip_space();
                        if(c == EOF) [[unlikely]] {
                            throw runtime_error(
                              "Reader::read_value<char>: Unexpected EOF.");
                        }
                        return (char)c;
                    } else if constexpr(is_integral_v<T>
                                        && ! is_same_v<T, char>) {
                        T    val      = 0;
                        bool negative = false;
                        int  c        = skip_space();
                        if(c == EOF) [[unlikely]] {
                            throw runtime_error(
                              "Reader::read_value<integral>: Unexpected EOF.");
                        }
                        if(c == '-') [[unlikely]] {
                            negative = true;
                            c        = getchar();
                        }
                        while(c >= '0' && c <= '9') {
                            val = val * 10 + (c - '0');
                            c   = getchar();
                        }
                        return negative ? -val : val;
                    } else if constexpr(is_same_v<T, string>) {
                        string str;
                        int    c = skip_space();
                        if(c == EOF) [[unlikely]] {
                            throw runtime_error(
                              "Reader::read_value<string>: Unexpected EOF.");
                        }
                        while(c != EOF && ! isspace(c)) {
                            str += (char)c;
                            c = getchar();
                        }
                        return str;
                    } else if constexpr(is_specialization<T, pair>::value) {
                        auto first  = read_value<typename T::first_type>();
                        auto second = read_value<typename T::second_type>();
                        return {first, second};
                    } else if constexpr(is_specialization<T, vector>::value) {
                        using InnerType = typename T::value_type;
                        int size        = read_value<int>();
                        T   vec(size);
                        for(auto& element : vec)
                            element = read_value<InnerType>();
                        return vec;
                    }
                    return T {};
                }
        };

        struct Writer {
            public:
                template <typename... Args>
                static void write(const Args&... args) {
                    bool first  = true;
                    auto writer = [&](const auto& arg) {
                        if(! first)
                            write_char(' ');
                        print_h(arg);
                        first = false;
                    };
                    (writer(args), ...);
                }

                template <typename... Args>
                static void writeln(const Args&... args) {
                    write(args...);
                    write_char('\n');
                }

            private:
                inline static char buffer[1 << BUFFER_SIZE];
                inline static int  pos = 0;

                struct Flusher {
                        ~Flusher() {
                            flush();
                        }
                };
                inline static Flusher flusher;

                static void flush() {
                    if(pos > 0) {
                        fwrite(buffer, 1, pos, stdout);
                        pos = 0;
                    }
                }

                static void write_char(char c) {
                    if(pos == sizeof(buffer)) [[unlikely]]
                        flush();
                    buffer[pos++] = c;
                }

                static void write_str(const char* v) {
                    for(int i = 0; v[i] != '\0'; ++i)
                        write_char(v[i]);
                }

                template <typename T>
                static void print_h(const T& arg) {
                    if constexpr(is_specialization<T,
                                                   DelimitedContainer>::value) {
                        bool first = true;
                        for(const auto& element : arg.container) {
                            if(! first)
                                print_h(arg.delimiter);
                            print_h(element);
                            first = false;
                        }
                    } else if constexpr(is_same_v<T, string>) {
                        write_str(arg.c_str());
                    } else if constexpr(is_convertible_v<T, const char*>) {
                        write_str(arg);
                    } else if constexpr(is_same_v<T, char>) {
                        write_char(arg);
                    } else if constexpr(is_iterable<T>) {
                        bool first = true;
                        for(const auto& e : arg) {
                            if(not first)
                                write_char(' ');
                            print_h(e);
                            first = false;
                        }
                    } else if constexpr(requires { get<0>(arg); }) {
                        apply(
                          [](const auto&... elems) {
                              bool first     = true;
                              auto print_tup = [&](const auto& e) {
                                  if(! first)
                                      write_char(' ');
                                  print_h(e);
                                  first = false;
                              };
                              (print_tup(elems), ...);
                          },
                          arg);
                    } else {
                        auto v = to_string(arg);
                        write_str(v.c_str());
                    }
                }
        };
    } /* namespace */

    /* @macro     */ namespace {
#define all(v)  std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define pb push_back
#define eb      emplace_back
#define mp      make_pair

        constexpr ll MOD = 1e9 + 7;

        [[nodiscard]]
        inline constexpr bool isOdd(ll x) {
            return (x % 2);
        }
        [[nodiscard]]
        inline constexpr ll add(ll a, ll b, ll m = MOD) {
            return ((a % m + b % m) % m + m) % m;
        }
        [[nodiscard]]
        inline constexpr ll sub(ll a, ll b, ll m = MOD) {
            return ((a % m - b % m) % m + m) % m;
        }
        [[nodiscard]]
        inline constexpr ll mul(ll a, ll b, ll m = MOD) {
            return ((a % m) * (b % m)) % m;
        }
        template <typename T>
        [[nodiscard]]
        inline constexpr T ceilDiv(T a, T b) {
            return (a + b - 1) / b;
        }

        [[nodiscard]] /* Binary Exponentiation */
        inline constexpr ll binpow(ll base, ll exp, ll m = MOD) {
            ll res = 1;
            base %= m;
            while(exp > 0) {
                if(exp % 2 == 1)
                    res = mul(res, base, m);
                base = mul(base, base, m);
                exp /= 2;
            }
            return res;
        }

        [[nodiscard]] /* NOTE: m should be prime */
        inline constexpr ll modInverse(ll n, ll m = MOD) {
            return binpow(n, m - 2, m);
        }

        struct Chash {
                static uint64_t splitmix64(uint64_t x) {
                    x += 0x9e3779b97f4a7c15;
                    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
                    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
                    return x ^ (x >> 31);
                }

                size_t operator()(uint64_t x) const {
                    static const uint64_t FRAND
                      = chrono::steady_clock::now().time_since_epoch().count();
                    return splitmix64(x + FRAND);
                }
        };

        template <typename T, typename Y, typename C = Chash>
        using umap = unordered_map<T, Y, C>;

#define Multitest(...)                                                         \
    if(int TC; input(TC), true)                                                \
        if(input(__VA_ARGS__); true)                                           \
            while(TC--)
#define Solution                                                               \
    int main()
    } /* namespace */
#pragma endregion section

string solve(string y) {
    int lucky[] = {4, 7, 47, 74, 44, 77, 477, 447, 474, 444, 744, 774, 747, 777};
    int iy = stoi(y);
    if (any_of(all(lucky), [&](int n){
        return iy % n == 0;
    }))
        return "YES";
    return "NO";
}

Solution {
    Redirect("247");
    auto y = input.getline();
    output(solve(y));
    return 0;
}
