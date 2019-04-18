#include <bits/stdc++.h>
using namespace std;


// check if a==b==0

typedef pair<int, int> pii;
#define x first
#define y second

pii extendedEuclid(int a, int b) { // returns {x, y} | ax + by = gcd(a,b)
	if (b == 0) return pii(1, 0);
	else {
		pii d = extendedEuclid(b, a % b);
		return pii(d.y, d.x - d.y * (a / b));
	}
}

bool diophantine(int a, int b, int c, pii& p) {
	int g = __gcd(abs(a), abs(b));
	if (c % g) {
		return false;
	}
	p = extendedEuclid(a, b);
	p.x *= c / g;
	p.y *= c / g;
	if (a < 0) p.x = -p.x;
	if (b < 0) p.y = -p.y;
	return true;
}
int main(int argc, char const *argv[])
{
	pii x;
	if (diophantine(5, 4, 2, x));
	cout << x.x << ' ' << x.y << endl;
	return 0;
}