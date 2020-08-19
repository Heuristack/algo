#include "boost/program_options.hpp"
#include "graph.h"
#include <fstream>

using namespace boost::program_options;
using namespace std;

int main(int argc, char const ** argv)
{
    options_description description("graph_search options");
    variables_map variables;

    description.add_options()
    ("help", "print available options")
    ("input-file", value<string>(), "graph data file to search")
    ("source-node", value<string>()->default_value("200"), "search starts from here")
    ("target-node", value<string>(), "target looking for")
    ("search-strategy", value<string>(), "algorithm used in the searching");

    store(parse_command_line(argc,argv,description),variables);
    if (variables.count("help")) {
        cout << description << endl;
        return 1;
    }

    string input_file = variables["input-file"].as<string>();
    if (input_file.empty()) {
        return 1;
    }
    ifstream input_stream(input_file);

    string source_node = variables["source-node"].as<string>();

    auto g = graph<node<string>,edge<string,double>>::make_graph<undirected>(input_stream);
    auto n = node<string>(source_node);
    auto v = [](auto const & n){ cout << n; };
    DFS(g,n,v); cout << endl;
    search<strategies::container<strategies::DFS>::type>(g,n,v); cout << endl;
    search<strategies::container<strategies::BFS>::type>(g,n,v); cout << endl;
}

