#include <iostream>
using namespace std;

bool kontrol(int x, int y, int m, int n)
{
    return (x >= 0 && x < m && 
            y >= 0 && y < n);
}

double probabilityBul(int m, int n, int x, 
                       int y, int N)
{
    if (!kontrol(x, y, m, n))
        return 0.0;
 
    if (N == 0)
        return 1.0;
 
    double prob = 0.0;
 
    prob += probabilityBul(m, n, x - 1, 
                            y, N - 1) * 0.25;

    prob += probabilityBul(m, n, x, 
                            y + 1, N - 1) * 0.25;

    prob += probabilityBul(m, n, x + 1,
                            y, N - 1) * 0.25;
 
    prob += probabilityBul(m, n, x, 
                            y - 1, N - 1) * 0.25;
 
    return prob;
}