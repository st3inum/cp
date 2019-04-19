#include <bits/stdc++.h>
using namespace std;

// find such g for which g^k(mod p) has an order of phi(g), for k , (gcd(g,p)==1)

// this code only works with prime number (p) . to work with all number write code
// to calculate phi(p)
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

int main(int argc, char const *argv[])
{
	cout<<generator(197)<<endl;
	return 0;
}