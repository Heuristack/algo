#include <iostream>
#include <iomanip>

using namespace std;

struct Master
{
    Master(unsigned breadth, unsigned depth): breadth(breadth), depth(depth) {}

    auto Explore(unsigned b = 0, unsigned d = 0) -> void
    {
        if (d != D(i,b,d)) {
            Visit(i++,b,d);
            for (auto b = 0; b != B(i,b,d); b++) {
                Explore(b,d+1);
            }
        }
    }

    auto Visit(unsigned i, unsigned b, unsigned d) -> void
    {
        cout << "(" << d << "," << b << "): " << setw(2) << setfill('0') << i << endl;
    }

    auto B(unsigned i, unsigned b, unsigned d) -> unsigned const
    {
        return breadth;
    }

    auto D(unsigned i, unsigned b, unsigned d) -> unsigned const
    {
        return depth;
    }

    unsigned breadth;
    unsigned depth;
    unsigned i = 0;
};

int main()
{
    Master(2,4).Explore();
}

