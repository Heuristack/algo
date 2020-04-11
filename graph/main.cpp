#include "initializers.h"
#include "graph.h"

int main()
{
    auto g = graph<node<string>,edge<string,int>>::make_graph<undirected>(clrs2301);
    auto n = node<string>("A");
    auto v = [](auto const & n){ cout << n; };
    DFS(g,n,v); cout << endl;
    search<strategies::container<strategies::DFS>::type>(g,n,v); cout << endl;
    search<strategies::container<strategies::BFS>::type>(g,n,v); cout << endl;
}

