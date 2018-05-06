#include <iostream>
#include <string>
#include <functional>
#include <unordered_set>

using namespace std;

struct T
{
    string k;
    string v;
    bool operator == (T const & that) const { return k == that.k && v == that.v; }
};

struct H
{
    size_t operator() (T const & o) const
    {
        size_t v = 0;
        v ^= hash<string>{}(o.k);
        v ^= hash<string>{}(o.v);
        return v;
    }
};

int main()
{
    unordered_set<T,H> s;
    s.emplace(T{"Hello", "Beijing"});
    s.emplace(T{"Bye", "Beijing"});
    s.emplace(T{"Hello", "HongKong"});
    cout << (s.find(T{"Hello", "Shanghai"}) == s.end()) << endl;
    cout << (s.find(T{"Bye", "Beijing"}) == s.end()) << endl;
}

