#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <initializer_list>
#include <variant>

using namespace std;

#include "node.hpp"
#include "edge.hpp"
#include "traits.hpp"
#include "decorators.hpp"
#include "containers.hpp"
#include "adapters.hpp"
#include "graph.hpp"
#include "algorithms.hpp"
#include "streams.hpp"
#include "properties.hpp"
#include "search.hpp"
#include "recursion.hpp"
#include "initializers.hpp"

int main()
{
    auto g = graph<node<string>,edge<string,int>>::make_graph<undirected>(clrs2301);
    auto n = node<string>("A");
    auto v = [](auto const & n){ cout << n; };
    dfs(g,n,v); cout << endl;
    search<strategies::dfs>(g,n,v); cout << endl;
    search<strategies::bfs>(g,n,v); cout << endl;
}

