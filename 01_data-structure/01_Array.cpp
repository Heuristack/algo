#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

namespace nonstd {

template<typename I, typename F>
auto partition(I b, I e, F p) -> I
{
    auto n = b;
    for (auto i = b; i != e; i++) {
        if (p(*i)) {
            iter_swap(n++, i);
        }
    }
    return n;
}

} //::nonstd

int main()
{
    vector<int> v = {6,7,8,1,2,3};
    nonstd::partition(begin(v), end(v), [](auto const & e){ return e < 5; });
    for (auto const & e : v) { cout << e << endl; }
}
