namespace strategies
{
    enum class dfs;
    enum class bfs;

    template <typename strategy, typename node>
    struct container
    {
        using type = adapter<typename conditional<is_same<strategy,strategies::dfs>::value,stack<node>,queue<node>>::type>;
    };
}

template <typename strategy, typename graph, typename visitor>
auto search(graph const & g, typename graph::node_type const & n, visitor const & c) -> void
{
    using base = typename graph::node_type;
    using node = mixin<base, parent<base>, length<int>, status, access<>>;

    typename access<>::time_type time = 0;
    searchable<map<base,node>> close;
    close[n] = node(n);

    typename strategies::container<strategy,base>::type open;
    open.put(n);
    while (!open.empty()) {
        auto & u = close[open.get()];
        u.s = status::expanding;
        u.enter = time++;
        for (auto const & e : const_cast<graph&>(g)[u]) {
            if (auto v = base(e.t); !close.contains(v)) {
                close[v] = node(v,u.v,u.l+1,{},{});
                open.put(v);
            }
        }
        invoke(c,u);
        u.leave = time++;
        u.s = status::processed;
    }
}

