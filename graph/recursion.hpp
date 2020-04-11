template <typename graph, typename visitor>
auto dfs(graph const & g, typename graph::node_type const & u, visitor const & c) -> void
{
    static searchable<set<mixin<typename graph::node_type,properties::parent<typename graph::node_type>>>> close;
    if (!g.contains(u)) return;
    close.insert(u);
    invoke(c,u);
    for (auto const & e : const_cast<graph&>(g)[u]) {
        if (auto v = node(e.t); !close.contains(v)) {
            dfs(g,v,c);
        }
    }
}

