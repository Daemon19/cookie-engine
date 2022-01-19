#include "utils.h"
#include <random>

namespace cookie
{
    static std::random_device random_device;
    static std::mt19937 random_engine{random_device()};

    int Randint(int start, int end)
    {
        std::uniform_int_distribution<> dist(start, end);
        return dist(random_engine);
    }

    int Randint(int end)
    {
        return Randint(0, end);
    }

    double Randdouble(double start, double end)
    {
        std::uniform_real_distribution<> dist(start, end);
        return dist(random_engine);
    }

    double Randdouble(double end)
    {
        return Randdouble(0.0, end);
    }
}