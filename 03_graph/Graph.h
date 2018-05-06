#ifndef GRAPH_H
#define GRAPH_H

#include <istream>
#include <ostream>
#include <iomanip>

using namespace std;

template <typename Vertex, typename Weight>
struct BasicNode
{
    Vertex vertex;
    Weight weight;

    bool operator < (BasicNode<Vertex,Weight> const & that) const { return vertex < that.vertex; }

    friend istream & operator >> (istream & s, BasicNode<Vertex,Weight> & n) { return s >> n.vertex >> n.weight; }
    friend ostream & operator << (ostream & s, BasicNode<Vertex,Weight> & n) { return s << n.vertex << ":" << setw(10) << setfill('0') << fixed << setprecision(6) << n.weight; }
};

template <typename Vertex, typename Weight>
struct BasicEdge
{
    Vertex source;
    Vertex target;
    Weight weight;

    bool operator < (BasicEdge<Vertex,Weight> const & that) const { return target < that.target; }

    friend istream & operator >> (istream & s, BasicEdge<Vertex,Weight> & e) { return s >> e.source >> e.target >> e.weight; }
    friend ostream & operator << (ostream & s, BasicEdge<Vertex,Weight> & e) { return s << e.source << "-" << e.target << ":" << setw(10) << setfill('0') << fixed << setprecision(6) << e.weight; }
};

template <typename Node, typename Edge, template<typename> typename Set, template<typename,typename> typename Map>
struct BasicGraph : Map<Node, Set<Edge>>
{
    friend ostream & operator << (ostream & s, BasicGraph<Node,Edge,Set,Map> & g) { for (auto [v,_] : g) { s << v << ": "; for (auto e : _) { s << e << " "; } s << "\n"; } return s; }
};

template <typename Graph, typename F>
void for_each_node(Graph & g, F f)
{
    for (auto [n,_] : g) {
        f(n);
    }
}

template <typename Graph, typename F>
void for_each_edge(Graph & g, F f)
{
    for (auto [n,_] : g) for (auto e : _) {
        f(e);
    }
}

#endif

