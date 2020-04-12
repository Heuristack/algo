#include "initializers.h"
#include "graph.h"

int main()
{
    auto g = graph<node<string>,edge<string,double>>::make_graph<undirected>(cin);
    auto n = node<string>("200");
    auto v = [](auto const & n){ cout << n; };
    DFS(g,n,v); cout << endl;
    search<strategies::container<strategies::DFS>::type>(g,n,v); cout << endl;
    search<strategies::container<strategies::BFS>::type>(g,n,v); cout << endl;
}

