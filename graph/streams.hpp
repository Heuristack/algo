template <typename vertex>
auto operator << (ostream & s, node<vertex> const & n) -> ostream &
{
    return s << "(" << n.v << ")";
}

template <typename vertex, typename ... weight>
auto operator << (ostream & s, edge<vertex,weight...> const & e) -> ostream &
{
    string w; if constexpr (sizeof...(weight)) { w = ":" + to_string(e.w); }
    return s << "(" << e.s << "," << e.t << w << ")";
}

template <typename node, typename edge, template<typename> typename set, template<typename,typename> typename map>
auto operator << (ostream & s, graph<node,edge,set,map> const & g) -> ostream &
{
    for_each(g,
        [&s](auto const & n){ s << n << ":"; },
        [&s](auto const & e){ s << e; },
        [&s](auto const & n){ s << "\n"; }
    );
    return s;
}

