// fasterIO , int128

#include <bits/stdc++.h>
using namespace std;

// faster IO with int128 support

//int128 supported site
//codemarshal.org
//uva
//at coder
//toph.co
// ...




//int128 unsupported site
//codeforce
// ...



//feature supported
//EOF
//scan without extra space
//__gcd

typedef	unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
typedef unsigned __int128 ulll;

int scan() {return 0;}
template<class T, typename... Args>
int scan(T *n, Args... args) {
	bool negative = false;
	register int c;
	*n = 0;
	c = getchar_unlocked();
	while (!(c >= '0' && c <= '9') && c != -1 && c != '-')c = getchar_unlocked();
	if (c == -1)return scan(args...);
	if (c == '-')
	{
		negative = true;
		c = getchar_unlocked();
	}
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		* n = (*n) * 10 + c - 48;
	if (negative)
		*n = -1 * (*n);
	return 1 + scan(args...);
}
template <class T>
void printrec(T n)
{
	if (n == 0) {
		return;
	}
	if (n < 0)
	{
		putchar_unlocked('-');
		n *= -1;
	}
	printrec(n / 10);
	putchar_unlocked(n % 10 + 0x30);
}
void print() {return ;}
template<class T, typename... Args>
void print(T n, Args... args)
{
	if (n == 0)putchar_unlocked('0');
	else printrec(n);
	putchar_unlocked('\n');
	// putchar_unlocked(' ');
	print(args...);
	return;
}
template <class T>
T abs(T n)
{
	if (n < 0)n *= -1;
	return n;
}
int main(int argc, char const *argv[])
{

	ulll a = ((ulll)1 << 127) - 1;
	/*while (scan(&a))
	{
		print(a);
	}
	*/
	/*
	ulll a,b;
	scan(a);
	scan(b);
	ulll c=__gcd(a,b);
	print(c);
	*/


	ull b,c;
	scan(&a,&b,&c);
	print(a,b,c);
	return 0;
}
