#include <bits/stdc++.h>
using namespace std;


// a^x=b (mod m) ; return x
// if we want to print all possible soluion we have to use map<int,vector<int>> and change the 2nd step also
// NB: see the unordered map and map
int solve(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * a) % m;

    unordered_map<int, int> vals;
    for (int p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * an) % m;
    }

    for (int q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}