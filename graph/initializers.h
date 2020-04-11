#include "graph.h"

static initializer_list<edge<string,int>> clrs2301 = {
    {"A","B", 4}, {"A","H", 8},
    {"B","H",11}, {"B","C", 8},
    {"H","I", 7}, {"H","G", 1},
    {"I","C", 2}, {"I","G", 6},
    {"C","D", 7}, {"C","F", 4},
    {"G","F", 2},
    {"D","F",14}, {"D","E", 9},
    {"E","F",10},
};

static initializer_list<edge<int>> manual0509 = {
    {1,6}, {1,2}, {1,5},
    {2,5}, {2,3},
    {5,4},
    {3,4},
};

static initializer_list<variant<node<int>,edge<int>>> varis = {
    variant<node<int>,edge<int>>{in_place_index_t<1>{},1,2},
    edge<int>{2,3},
    {4},
//  {5,6}
};

