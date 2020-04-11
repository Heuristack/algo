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
#include "containers.hpp"
#include "graph.hpp"
#include "streams.hpp"
#include "search.hpp"
#include "initializers.hpp"

int main()
{
    auto g = graph<node<string>,edge<string,int>>::make_graph<undirected>(clrs2301);
    auto n = node<string>("A");
    auto v = [](auto const & n){ cout << n; };
    DFS(g,n,v); cout << endl;
    search<strategies::container<strategies::DFS>::type>(g,n,v); cout << endl;
    search<strategies::container<strategies::BFS>::type>(g,n,v); cout << endl;
}

