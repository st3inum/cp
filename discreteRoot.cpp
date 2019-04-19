#include <bits/stdc++.h>
using namespace std;

// x^k=a(mod n)
// given k,a,n , find x
// g^y=x(mod n) then (g^y)^k=a(mod n) => (g^k)^y=a(mod n)
int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

long long powmod(long long a, long long b, long long p) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

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
// this is for single solution
int discreteRoot(int k,int a,int n)
{
	int g=generator(n);
	int y=solve(powmod(g,k,n),a,n);
	return powmod(g,y,n);

	// Print all possible answers
    int delta = (n-1) / gcd(k, n-1);
    vector<int> ans;
    for (int cur = y % delta; cur < n-1; cur += delta)
        ans.push_back(powmod(g, cur, n));
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int answer : ans)
        printf("%d ", answer);
}
int main(int argc, char const *argv[])
{
	discreteRoot(9,4,11);
	return 0;
}