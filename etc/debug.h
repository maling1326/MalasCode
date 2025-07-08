#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <tuple>
#include <concepts>
#include <type_traits>
#include <string_view>
#include <iomanip>
#include <memory>
#include <sstream>

/* --- Configuration Macros --- */
/* #define DEBUG_NO_COLOR */
#define DEBUG_LINE_WIDTH                                                       \
    90 /* Max characters per line for wrapping long values. */
#define DEBUG_MAX_VALUE_LEN                                                    \
    4'096 /* Max total characters for a value before it's truncated. */

/* --- Main Debug Macro --- */
#ifndef ONLINE_JUDGE
    #define debug(...)                                                         \
        debug_internal::Debugger (__FILE__, __LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...)
#endif

/* --- Internal Implementation --- */
namespace debug_internal {

#if defined(DEBUG_NO_COLOR)
    namespace color {
        constexpr std::string_view reset = "", red = "", green = "",
                                   yellow = "", blue = "", magenta = "",
                                   cyan = "", gray = "";
    }
#else
    namespace color {
        constexpr std::string_view reset = "\033[0m", red = "\033[31m",
                                   green = "\033[32m", yellow = "\033[33m",
                                   blue = "\033[34m", magenta = "\033[35m",
                                   cyan = "\033[36m", gray = "\033[90m";
    }
#endif

    /* --- Type Name Demangling --- */
    template <typename T>
    constexpr std::string_view type_name() {
#if defined(__clang__) || defined(__GNUC__)
        constexpr std::string_view function = __PRETTY_FUNCTION__;
    #if defined(__clang__)
        constexpr std::string_view prefix = "[T = ";
        constexpr std::string_view suffix = "]";
    #else
        constexpr std::string_view prefix = "with T = ";
        constexpr std::string_view suffix = "; ";
    #endif
        const auto start = function.find (prefix) + prefix.size();
        const auto end   = function.find (suffix, start);
        return function.substr (start, end - start);
#elif defined(_MSC_VER)
        constexpr std::string_view function = __FUNCSIG__;
        constexpr std::string_view prefix   = "type_name<";
        constexpr std::string_view suffix   = ">(void)";
        const auto start = function.find (prefix) + prefix.size();
        const auto end   = function.find (suffix, start);
        return function.substr (start, end - start);
#else
        return "unknown_type";
#endif
    }

    /* --- Value Rendering Engine --- */
    /* Note: These functions render a value to a stringstream instead of printing directly. */
    template <typename T>
    void render_value (std::stringstream&, const T&);
    template <typename T>
    concept is_iterable = requires (T t) {
                              t.begin();
                              t.end();
                          } && ! std::is_same_v<T, std::string>;

    void render_value (std::stringstream& ss, const char* t) {
        ss << '"' << t << '"';
    }

    void render_value (std::stringstream& ss, const std::string& t) {
        render_value (ss, t.c_str());
    }

    void render_value (std::stringstream& ss, char t) {
        ss << '\'' << t << '\'';
    }

    void render_value (std::stringstream& ss, bool t) {
        ss << (t ? "true" : "false");
    }

    template <typename T>
    void render_value (std::stringstream& ss, T* p) {
        if (p) {
            ss << p << " -> ";
            render_value (ss, *p);
        } else {
            ss << "nullptr";
        }
    }

    template <typename T>
    void render_value (std::stringstream& ss, const std::unique_ptr<T>& p) {
        render_value (ss, p.get());
    }

    template <typename T>
    void render_value (std::stringstream& ss, const std::shared_ptr<T>& p) {
        render_value (ss, p.get());
    }

    template <typename T, typename U>
    void render_value (std::stringstream& ss, const std::pair<T, U>& p) {
        ss << "{";
        render_value (ss, p.first);
        ss << ",";
        render_value (ss, p.second);
        ss << "}";
    }

    template <typename... T>
    void render_value (std::stringstream& ss, const std::tuple<T...>& t) {
        ss << "{";
        std::apply (
          [ & ] (const auto&... args) {
              bool first = true;
              ((ss << (first ? "" : ","),
                render_value (ss, args),
                first = false),
               ...);
          },
          t);
        ss << "}";
    }

    template <is_iterable T>
    void render_value (std::stringstream& ss, const T& container) {
        ss << "{";
        bool first = true;
        for (const auto& element : container) {
            if (! first)
                ss << ",";
            render_value (ss, element);
            first = false;
        }
        ss << "}";
    }

    template <typename T>
    void render_value (std::stringstream& ss, const T& value) {
        if constexpr (std::is_enum_v<T>)
            ss << static_cast<std::underlying_type_t<T>> (value);
        else
            ss << value;
    }

    /* --- Main Debugger Class --- */
    struct Debugger {
            template <typename... Args>
            Debugger (
              const char* file, int line, const char* names, Args&&... args) {
                std::string_view file_name = std::string_view (file).substr (
                  std::string_view (file).find_last_of ("/\\") + 1);
                std::cerr << color::gray << "+-[ " << color::blue << "DEBUG"
                          << color::gray << " ] @ " << color::cyan << file_name
                          << color::gray << ":" << color::cyan << line << "\n";
                std::string_view names_sv = names;
                print_vars (1, names_sv, std::forward<Args> (args)...);
                std::cerr
                  << color::gray << "+-"
                  << std::string (
                       DEBUG_LINE_WIDTH > 2 ? DEBUG_LINE_WIDTH - 2 : 0, '-')
                  << color::reset << std::endl;
            }

        private:
            std::string_view get_name (std::string_view& names) {
                size_t pos  = names.find (',');
                auto   name = names.substr (0, pos);
                names =
                  (pos == std::string_view::npos) ? "" : names.substr (pos + 1);
                name.remove_prefix (
                  std::min (name.find_first_not_of (" \t\n\r"), name.size()));
                return name;
            }

            template <typename T>
            void print_details (const T& v) {
                using D = std::decay_t<T>;
                std::cerr << color::gray << "[sizeof: " << sizeof (v) << "B";
                if constexpr (std::is_integral_v<D>)
                    std::cerr << ", integral";
                if constexpr (std::is_floating_point_v<D>)
                    std::cerr << ", float";
                if constexpr (std::is_pointer_v<D> || requires { v.get(); })
                    std::cerr << ", pointer";
                if constexpr (std::is_enum_v<D>)
                    std::cerr << ", enum";
                if constexpr (
                  std::is_class_v<D> && ! std::is_same_v<D, std::string>) {
                    std::cerr << ", class";
                }
                if constexpr (std::is_signed_v<D>)
                    std::cerr << ", signed";
                if constexpr (requires { v.size(); })
                    std::cerr << ", size: " << v.size();
                if constexpr (requires { v.capacity(); })
                    std::cerr << ", capacity: " << v.capacity();
                if constexpr (requires { v.use_count(); })
                    std::cerr << ", use_count: " << v.use_count();
                std::cerr << "]";
            }

            void print_wrapped (const std::string& text) {
                const size_t prefix_len =
                  9; /* Visual length of "|    |   = " */
                const size_t wrap_prefix_len =
                  9; /* Visual length of "|    |   " (with alignment space) */

                size_t available_width = DEBUG_LINE_WIDTH > prefix_len
                                           ? DEBUG_LINE_WIDTH - prefix_len
                                           : 0;
                if (text.length() <= available_width) {
                    std::cerr << text;
                    return;
                }

                std::cerr << text.substr (0, available_width);
                size_t current_pos = available_width;

                while (current_pos < text.length()) {
                    std::cerr << "\n"
                              << color::gray << "|    |   " << color::reset;
                    available_width = DEBUG_LINE_WIDTH > wrap_prefix_len
                                        ? DEBUG_LINE_WIDTH - wrap_prefix_len
                                        : 0;
                    size_t len_to_print =
                      std::min (available_width, text.length() - current_pos);
                    std::cerr << text.substr (current_pos, len_to_print);
                    current_pos += len_to_print;
                }
            }

            template <typename T>
            void print_single (int count, std::string_view name, T&& v) {
                /* Line 1: Variable info (number, name, type) */
                std::cerr << color::gray << "| " << color::cyan << std::setw (2)
                          << count << color::gray << " | " << color::yellow
                          << name << color::gray << " : " << color::magenta
                          << type_name<std::decay_t<T>>() << color::reset
                          << "\n";

                /* Line 2: Detailed Information */
                std::cerr << color::gray << "|    | " << color::reset;
                print_details (std::forward<T> (v));
                std::cerr << "\n";

                /* Line 3: Value (with wrapping) */
                std::cerr << color::gray << "|    |   " << color::reset << "";
                std::stringstream value_ss;
                render_value (value_ss, std::forward<T> (v));
                std::string value_str = value_ss.str();

                if (value_str.length() > DEBUG_MAX_VALUE_LEN) {
                    value_str =
                      value_str.substr (0, DEBUG_MAX_VALUE_LEN) + "...}";
                }
                print_wrapped (value_str);
                std::cerr << "\n";
            }

            template <typename T, typename... Args>
            void print_vars (
              int count, std::string_view& names, T&& v, Args&&... args) {
                print_single (count, get_name (names), std::forward<T> (v));
                if constexpr (sizeof...(Args) > 0) {
                    std::cerr << color::gray << "|\n"; /* Separator line */
                    print_vars (count + 1, names, std::forward<Args> (args)...);
                }
            }
    };
} /* namespace debug_internal */