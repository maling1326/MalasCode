#include <bits/stdc++.h>
using namespace std;

/* clang-format on */
/*------------------*/
#ifdef LOCAL_DBG
    #define Redirect(data) InputRedirector redirector_##__LINE__(data)
    #define scope(...)                                                         \
        ::ScopeTracer scope_tracer_##__LINE__(__VA_ARGS__, __FILE__, __LINE__)
    #define scopeln(...)                                                       \
        ::ScopeLnTracer scopeln_tracer_##__LINE__(                             \
          __VA_ARGS__, __FILE__, __LINE__)

    #define debugln(...)                                                       \
        ::VarDebugger(__FILE__, __LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
    #define Redirect(...)
    #define debugln(...)
    #define scope(...)
    #define scopeln(...)
#endif
#define input(...)    ::InputReader::read(__VA_ARGS__)
#define inputln(...)  ::InputReader::read_line(__VA_ARGS__)
#define output(...)   ::OutputWriter::write(__VA_ARGS__)
#define outputln(...) ::OutputWriter::writeln(__VA_ARGS__)
#define delim(c, d)   DelimitedContainer(c, d)

using ll         = long long;
using ull        = unsigned ll;
using ld         = long double;
using str        = string;
using strv       = string_view;
using vi         = vector<int>;
using vll        = vector<ll>;
using vvi        = vector<vi>;
using vvll       = vector<vll>;
using pii        = pair<int, int>;
using pll        = pair<ll, ll>;
using vpii       = vector<pii>;
using vpll       = vector<pll>;

constexpr ll MOD = 1e9 + 7;
constexpr ld PI  = 3.14159265358979323846264338327950288L;

#define add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define sub(a, b) (((a) % MOD - (b) % MOD + MOD) % MOD)
#define mul(a, b) (((a) % MOD * (b) % MOD) % MOD)

static const auto __PROGRAM_START_TIME = chrono::steady_clock::now();
static const auto __SET_IO             = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

namespace {

    template <typename Container>
    struct DelimitedContainer {
            const Container& container;
            const char*      delimiter;
    };

    namespace color {
        constexpr strv O0m {"\033[0m"}, O31m {"\033[31m"}, O32m {"\033[32m"},
          O33m {"\033[33m"}, O34m {"\033[34m"}, O35m {"\033[35m"},
          O36m {"\033[36m"}, O90m {"\033[90m"};
    }

    inline int DEBUG_INDENT_LEVEL = 0;

    void print_indent() {
        for(int i = 0; i < DEBUG_INDENT_LEVEL; ++i)
            cerr << "  ";
    }

    template <typename T>
    constexpr strv type_name() {
        constexpr strv prefix {"with T = "}, suffix {"; "};
        return "unknown_type";
    }

    template <typename T>
    void Render(stringstream&, const T&);
    template <typename T>
    concept is_iterable = requires(T t) {
                              t.begin();
                              t.end();
                          } && ! is_same_v<T, str>;

    void Render(stringstream& ss, const char* t) {
        ss << '"' << t << '"';
    }

    void Render(stringstream& ss, const str& t) {
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

    struct TimeLogger {
            TimeLogger(
              strv title, const char* file, int line, bool is_exit = false) {
                auto now     = chrono::steady_clock::now();
                auto elapsed = chrono::duration_cast<chrono::milliseconds>(
                  now - __PROGRAM_START_TIME);
                strv file_name =
                  strv(file).substr(strv(file).find_last_of("/\\") + 1);

                print_indent();
                cerr << fixed;
                cerr << color::O90m << "[ " << (is_exit ? "< " : "> ")
                     << color::O35m << title << color::O90m << " ] @ "
                     << color::O32m << elapsed.count() << "ms" << color::O90m
                     << " @ " << color::O36m << file_name << color::O90m << ":"
                     << color::O36m << line << color::O0m << endl;
            }
    };

    struct VarDebugger {
        private:
            static strv get_name(strv& names) {
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
                names =
                  (split_pos == strv::npos) ? "" : names.substr(split_pos + 1);
                name.remove_prefix(
                  min(name.find_first_not_of(" \t\n\r"), name.size()));
                return name;
            }

            template <typename... Vars>
            void print_vars(strv& names_sv, Vars&&... vars) {
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
            VarDebugger(
              const char* file, int line, const char* names, Args&&... args) {
                print_indent();
                strv file_name =
                  strv(file).substr(strv(file).find_last_of("/\\") + 1);
                strv names_sv   = names;
                auto args_tuple = forward_as_tuple(args...);

                if constexpr(sizeof...(Args) > 0) {
                    using FirstArg =
                      decay_t<tuple_element_t<0, tuple<Args...>>>;
                    if constexpr(is_same_v<FirstArg, const char*>) {
                        strv title = get<0>(args_tuple);
                        cerr << color::O90m << "[ " << color::O34m << title
                             << color::O90m << " ] " << color::O0m;

                        if constexpr(sizeof...(Args) > 1) {
                            size_t comma_pos = names_sv.find(',');
                            names_sv         = (comma_pos != strv::npos)
                                                 ? names_sv.substr(comma_pos + 1)
                                                 : "";
                            apply(
                              [&](auto&&, auto&&... rest) {
                                  print_vars(names_sv, rest...);
                              },
                              args_tuple);
                        }
                    } else {
                        cerr << color::O90m << "[ " << color::O34m << "DEBUG"
                             << color::O90m << " ] " << color::O0m;
                        print_vars(names_sv, args...);
                    }
                } else {
                    cerr << color::O90m << "[ " << color::O34m << "DEBUG"
                         << color::O90m << " ]" << color::O0m;
                }

                cerr << color::O90m << " @ " << color::O36m << file_name
                     << color::O90m << ":" << color::O36m << line << color::O0m
                     << endl;
            }
    };

    struct ScopeTracer {
            strv                             name;
            const char*                      file;
            int                              line;
            chrono::steady_clock::time_point start_time;

            ScopeTracer(strv n, const char* f, int l)
                : name(n)
                , file(f)
                , line(l)
                , start_time(chrono::steady_clock::now()) {
                print_indent();
                strv file_name =
                  strv(file).substr(strv(file).find_last_of("/\\") + 1);
                cerr << color::O90m << "[ > " << color::O35m << name
                     << color::O90m << " ]"
                     << " @ " << color::O36m << file_name << color::O90m << ":"
                     << color::O36m << line << color::O0m << endl;
                DEBUG_INDENT_LEVEL++;
            }

            ~ScopeTracer() {
                DEBUG_INDENT_LEVEL--;
                auto end_time = chrono::steady_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(
                  end_time - start_time);
                strv file_name =
                  strv(file).substr(strv(file).find_last_of("/\\") + 1);

                print_indent();
                cerr << fixed;
                cerr << color::O90m << "[ < " << color::O35m << name
                     << color::O90m << " ] @ " << color::O32m
                     << duration.count() << "ms taken" << color::O90m << " @ "
                     << color::O36m << file_name << color::O90m << ":"
                     << color::O36m << line << color::O0m << endl;
            }
    };

    struct ScopeLnTracer {
            strv                             name;
            const char*                      file;
            int                              line;
            chrono::steady_clock::time_point start_time;

            ScopeLnTracer(strv n, const char* f, int l)
                : name(n)
                , file(f)
                , line(l)
                , start_time(chrono::steady_clock::now()) {
                DEBUG_INDENT_LEVEL++;
            }

            ~ScopeLnTracer() {
                DEBUG_INDENT_LEVEL--;
                auto end_time = chrono::steady_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(
                  end_time - start_time);
                strv file_name =
                  strv(file).substr(strv(file).find_last_of("/\\") + 1);

                print_indent();
                cerr << fixed;
                cerr << color::O90m << "[ < " << color::O35m << name
                     << color::O90m << " ] @ " << color::O32m
                     << duration.count() << "ms taken" << color::O90m << " @ "
                     << color::O36m << file_name << color::O90m << ":"
                     << color::O36m << line << color::O0m << endl;
            }
    };

    struct InputReader {
            template <typename... Args>
            static void read(Args&... args) {
                (read_one(args), ...);
            }

            static void read_line(string& arg) {
                int c = cin.peek();
                if(c == '\n' || c == '\r')
                    getchar();
                getline(cin, arg);
            }

        private:
            template <typename T>
            static void read_one(T& arg) {
                if constexpr(is_integral_v<T>) {
                    arg           = 0;
                    char c        = getchar();
                    bool negative = false;
                    while(c < '0' || c > '9') {
                        if(c == '-')
                            negative = true;
                        c = getchar();
                    }
                    while(c >= '0' && c <= '9') {
                        arg = arg * 10 + (c - '0');
                        c   = getchar();
                    }
                    if(negative)
                        arg = -arg;
                } else if constexpr(is_same_v<T, str>) {
                    arg.clear();
                    char c = getchar();
                    while(isspace(c))
                        c = getchar();
                    while(! isspace(c) && c != EOF) {
                        arg += c;
                        c = getchar();
                    }
                } else if constexpr(is_iterable<T>) {
                    for(auto& element : arg)
                        read_one(element);
                } else {
                    cin >> arg;
                }
            }
    };

    struct InputRedirector {
            InputRedirector(string data) {
                const char* tmp_filename = "_local_input.txt";
                ofstream    out(tmp_filename);
                replace(data.begin(), data.end(), '#', '\n');
                out << data;
                out.close();
                freopen(tmp_filename, "r", stdin);
            }
    };

    template <typename Test, template <typename...> class Ref>
    struct is_specialization : std::false_type {};

    template <template <typename...> class Ref, typename... Args>
    struct is_specialization<Ref<Args...>, Ref> : std::true_type {};

    // MODIFIED: OutputWriter struct is now simpler and more powerful
    struct OutputWriter {
        public:
            // For output(...)
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

            // For outputln(...)
            template <typename... Args>
            static void writeln(const Args&... args) {
                write(args...);   // Call the main write function
                write_char('\n'); // Add the newline
            }

        private:
            inline static char buffer[1 << 20];
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
                if(pos == sizeof(buffer))
                    flush();
                buffer[pos++] = c;
            }

            static void write_str(const char* s) {
                for(int i = 0; s[i] != '\0'; ++i)
                    write_char(s[i]);
            }

            template <typename T>
            static void print_h(const T& arg) {
                if constexpr(is_specialization<T, DelimitedContainer>::value) {
                    bool first = true;
                    for(const auto& element : arg.container) {
                        if(! first)
                            print_h(arg.delimiter);
                        print_h(element);
                        first = false;
                    }
                } else if constexpr(is_same_v<T, str>) {
                    write_str(arg.c_str());
                } else if constexpr(is_convertible_v<T, const char*>) {
                    write_str(arg);
                } else if constexpr(is_same_v<T, char>) {
                    write_char(arg);
                } else if constexpr(is_iterable<T>) {
                    bool first = true;
                    for(const auto& e : arg) {
                        if(! first)
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
                    auto s = to_string(arg);
                    write_str(s.c_str());
                }
            }
    };
} /* namespace */

/*-----------------*/
/* clang-format on */

class Solution {
public:
    ll ubin (ll p, ll l, ll sisi) {
        scope ("ubin");
        ll sum{0};
        debugln (sum);
        sum += (p + sisi - 1) / sisi;
        debugln (sum);
        sum *= (l + sisi - 1) / sisi;
        debugln (sum);
        return sum;
    }
};

int main() {
    scope("Main");
    Solution s;

_m__dbg:
#ifdef LOCAL_DBG
    Redirect(R"(7 2 1)");
#endif

_m__main:
    ll p, l, sisi, sum{0};
    input(p, l, sisi);
    debugln(p, l, sisi);
    outputln(s.ubin(p, l, sisi));
    return 0;
__note__:
    /**/
}

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
