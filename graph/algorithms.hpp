template <typename graph, template <typename> typename visitor>
auto for_each(graph const & g, visitor<typename graph::node_type> bn, visitor<typename graph::edge_type> ce, visitor<typename graph::node_type> an)  // note : this doesn't work - make it work!
{
    for (auto const & [n,v] : g) {
        invoke(bn,n);
        for (auto const & e : v) {
            invoke(ce,e);
        }
        invoke(an,n);
    }
}

template <typename graph, typename bnvistor, typename evistor, typename anvister>
auto for_each(graph const & g, bnvistor bn, evistor ce, anvister an)
{
    for (auto const & [n,v] : g) {
        invoke(bn,n);
        for (auto const & e : v) {
            invoke(ce,e);
        }
        invoke(an,n);
    }
}


