#ifndef DEBUG_PRINT_HPP
#define DEBUG_PRINT_HPP

#define INCLUDED(n) ((defined _GLIBCXX_##n) || (defined _LIBCPP_##n))
#include <atcoder/modint>
namespace debug_print {
  std::ostream& os = std::cerr;

  template <class Tp> auto has_cbegin(int)     -> decltype(std::cbegin(std::declval<Tp>()), std::true_type {});
  template <class Tp> auto has_cbegin(...)     -> std::false_type;
  template <class Tp> auto has_value_type(int) -> decltype(std::declval<typename Tp::value_type>(), std::true_type {});
  template <class Tp> auto has_value_type(...) -> std::false_type;

  template <class Tp>[[maybe_unused]] constexpr bool is_iterable_container_v = decltype(has_cbegin<Tp>(int {}))::value;
  template <class Tp>[[maybe_unused]] constexpr bool is_container_v          = decltype(has_value_type<Tp>(int {}))::value
                                                                               || is_iterable_container_v<Tp>;

  template <>        [[maybe_unused]] constexpr bool is_iterable_container_v<std::string_view> = false;
  template <>        [[maybe_unused]] constexpr bool is_container_v<std::string_view>          = false;

  template <>        [[maybe_unused]] constexpr bool is_iterable_container_v<std::string>      = false;
  template <>        [[maybe_unused]] constexpr bool is_container_v<std::string>               = false;


  template <class Tp, class... Ts> struct first_element { using type = Tp; };
  template <class... Ts> using first_t = typename first_element<Ts...>::type;

  template <class Tp, std::enable_if_t<!decltype(has_value_type<Tp>(int {}))::value, std::nullptr_t> = nullptr>
    auto check_elem(int) -> decltype(*std::cbegin(std::declval<Tp>()));
  template <class Tp, std::enable_if_t<decltype(has_value_type<Tp>(int {}))::value, std::nullptr_t> = nullptr>
    auto check_elem(int) -> typename Tp::value_type;
  template <class Tp>
    auto check_elem(...) -> void;

  template <class Tp> using elem_t = decltype(check_elem<Tp>(int {}));

  template <class Tp> [[maybe_unused]] constexpr bool is_multidim_container_v = is_container_v<Tp>
                                                                                && is_container_v<elem_t<Tp>>;

  template <class Tp> std::enable_if_t<!is_container_v<Tp>> out(const Tp&);
  void out(const char&);
  void out(const char*);
  void out(const std::string_view&);


  void out(const std::string&);



  void out(const __int128&);
  void out(const unsigned __int128&);


  template <class Tp1, class Tp2> void out(const std::pair<Tp1, Tp2>&);


  template <class... Ts> void out(const std::tuple<Ts...>&);



  template <class... Ts> void out(std::stack<Ts...>);



  template <class... Ts> void out(std::queue<Ts...>);
  template <class... Ts> void out(std::priority_queue<Ts...>);


  template <class C> std::enable_if_t<is_iterable_container_v<C>> out(const C&);

  template <class Tp> std::enable_if_t<!is_container_v<Tp>> out(const Tp& arg) {
    os << arg;
  }

  void out(const char& arg) {
    os << '\'' << arg << '\'';
  }

  void out(const char* arg) {
    os << '\"' << arg << '\"';
  }

  void out(const std::string_view& arg) {
    os << '\"' << arg << '\"';
  }


  void out(const std::string& arg) {
    os << '\"' << arg << '\"';
  }

  void out(const atcoder::modint& arg) {
    os << arg.val();
  }

  void out(const atcoder::modint998244353& arg) {
    os << arg.val();
  }

  void out(const atcoder::modint1000000007& arg) {
    os << arg.val();
  }

  void out(const __int128& arg) {
    int sign = (arg < 0) ? (-1) : 1;
    if (sign == -1)
      os << '-';
    __int128 base = sign;
    while (sign * arg >= sign * base * 10)
      base *= 10;
    while (base) {
      os << static_cast<char>('0' + (arg / base % 10));
      base /= 10;
    }
  }

  void out(const unsigned __int128& arg) {
    unsigned __int128 base = 1;
    while (arg >= base * 10)
      base *= 10;
    while (base) {
      os << static_cast<char>('0' + (arg / base % 10));
      base /= 10;
    }
  }


  template <class Tp1, class Tp2> void out(const std::pair<Tp1, Tp2>& arg) {
    os << '(';
    out(arg.first);
    os << ", ";
    out(arg.second);
    os << ')';
  }


  template <class T, std::size_t... Is> void print_tuple(const T& arg, std::index_sequence<Is...>) {
    static_cast<void>(((os << (Is == 0 ? "" : ", "), out(std::get<Is>(arg))), ...));
  }

  template <class... Ts> void out(const std::tuple<Ts...>& arg) {
    os << '(';
    print_tuple(arg, std::make_index_sequence<sizeof...(Ts)>());
    os << ')';
  }


  template <class... Ts> void out(std::stack<Ts...> arg) {
    if (arg.empty()) {
      os << "<empty stack>";
      return;
    }
    os << "[ ";
    while (!arg.empty()) {
      out(arg.top());
      os << ' ';
      arg.pop();
    }
    os << ']';
  }



  template <class... Ts> void out(std::queue<Ts...> arg) {
    if (arg.empty()) {
      os << "<empty queue>";
      return;
    }
    os << "[ ";
    while (!arg.empty()) {
      out(arg.front());
      os << ' ';
      arg.pop();
    }
    os << ']';
  }
  template <class... Ts> void out(std::priority_queue<Ts...> arg) {
    if (arg.empty()) {
      os << "<empty priority_queue>";
      return;
    }
    os << "[ ";
    while (!arg.empty()) {
      out(arg.top());
      os << ' ';
      arg.pop();
    }
    os << ']';
  }


  template <class Container>
  std::enable_if_t<is_iterable_container_v<Container>> out(const Container& arg) {
    if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {
      os << "<empty container>";
      return;
    }
    os << "[ ";
    std::for_each(std::cbegin(arg), std::cend(arg), [](const elem_t<Container>& elem) {
      out(elem);
      os << ' ';
    });
    os << ']';
  }

  template <class Tp> std::enable_if_t<!is_multidim_container_v<Tp>>
  print(std::string_view name, const Tp& arg) {
    os << name << ": ";
    out(arg);
    if constexpr (is_container_v<Tp>)
      os << '\n';
  }

  template <class Tp> std::enable_if_t<is_multidim_container_v<Tp>>
  print(std::string_view name, const Tp& arg) {
    os << name << ": ";
    if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {
      os << "<empty multidimensional container>\n";
      return;
    }
    std::for_each(std::cbegin(arg), std::cend(arg),
      [&name, is_first_elem = true](const elem_t<Tp>& elem) mutable {
        if (is_first_elem)
          is_first_elem = false;
        else
          for (std::size_t i = 0; i < name.length() + 2; i++)
            os << ' ';
        out(elem);
        os << '\n';
    });
  }

  template <class Tp, class... Ts> void multi_print(std::string_view names, const Tp& arg, const Ts&... args) {
    if constexpr (sizeof...(Ts) == 0) {
      names.remove_suffix(
        std::distance(
          names.crbegin(),
          std::find_if_not(names.crbegin(), names.crend(),
                           [](const char c) { return std::isspace(c); })
        )
      );
      print(names, arg);
      if constexpr (!is_container_v<Tp>)
        os << '\n';
    } else {
      std::size_t comma_pos = 0;

      for (std::size_t i = 0, paren_depth = 0, inside_quote = false; i < names.length(); i++) {
        if (!inside_quote && paren_depth == 0 && i > 0 && names[i - 1] != '\'' && names[i] == ',') {
          comma_pos = i;
          break;
        }
        if (names[i] == '\"' || names[i] == '\'') {
          if (i > 0 && names[i - 1] == '\\') continue;
          inside_quote ^= true;
        }
        if (!inside_quote && names[i] == '(' && (i == 0 || names[i - 1] != '\''))
          paren_depth++;
        if (!inside_quote && names[i] == ')' && (i == 0 || names[i - 1] != '\''))
          paren_depth--;
      }

      const std::size_t first_varname_length = comma_pos - std::distance(
        names.crend() - comma_pos,
        std::find_if_not(
          names.crend() - comma_pos, names.crend(),
          [](const char c) { return std::isspace(c); }
        )
      );
      print(names.substr(0, first_varname_length), arg);

      if constexpr (!is_container_v<Tp>) {
        if constexpr (is_container_v<first_t<Ts...>>)
          os << '\n';
        else
          os << " | ";
      }

      const std::size_t next_varname_begins_at = std::distance(
        names.cbegin(),
        std::find_if_not(
          names.cbegin() + comma_pos + 1, names.cend(),
          [](const char c) { return std::isspace(c); }
        )
      );
      names.remove_prefix(next_varname_begins_at);

      multi_print(names, args...);
    }
  }
}  // namespace debug_print

#undef INCLUDED

#endif  // DEBUG_PRINT_HPP

/* 
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
*/
