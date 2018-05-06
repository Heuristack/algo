#include <iostream>
#include <iomanip>

using namespace std;

struct Master
{
    Master(unsigned breadth, unsigned depth): BN(breadth), DN(depth)
    {}

    auto Explore(unsigned b = 0, unsigned d = 0) -> void
    {
        if (d != D(ID,b,d)) {
            Visit(ID++,b,d);
            for (auto b = 0; b != B(ID,b,d); b++) {
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
        return BN;
    }

    auto D(unsigned i, unsigned b, unsigned d) -> unsigned const
    {
        return DN;
    }

    unsigned ID = 0;
    unsigned BN = 0;
    unsigned DN = 0;
};

int main()
{
    Master(2,4).Explore();
}

