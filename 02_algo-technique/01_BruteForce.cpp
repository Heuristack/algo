#include <iostream>
#include <iomanip>

using namespace std;

struct Execution
{
    Execution(unsigned int N): number(N) {}

    virtual unsigned int Factorial(unsigned int) = 0;
    virtual unsigned int Fabonacci(unsigned int) = 0;

    void Run()
    {
        cout << "Factorial(" << number << ") = " << Factorial(number) << "\n";
        cout << "Fabonacci(" << number << ") = " << Fabonacci(number) << "\n";
    }

    unsigned int number = 0;
};

struct Iteration : Execution
{
    Iteration(unsigned int N): Execution(N) {};

    auto Factorial(unsigned int N) -> unsigned int override
    {
        auto F = 1;
        for (auto I = 1; I <= N; I++) {
            F *= I;
        }
        return F;
    }

    auto Fabonacci(unsigned int N) -> unsigned int override
    {
        auto D = 0, E = 1, F = 0;
        for (auto I = 2; I <= N; I++) {
            F = E + D; D = E; E = F;
        }
        return F;
    }
};

struct Recursion : Execution
{
    Recursion(unsigned int N): Execution(N) {}

    auto Factorial(unsigned int N) -> unsigned int override
    {
        if (N == 0) return 1;
        else return Factorial(N - 1) * N;
    }

    auto Fabonacci(unsigned int N) -> unsigned int override
    {
        if (N <= 1) return N;
        else return Fabonacci(N - 2) + Fabonacci(N - 1);
    }

};

int main()
{
    Recursion(10).Run();
    Iteration(10).Run();
}

