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


template <class T>
int scan(T &n)
{
	bool negative = false;
	register int c;
	n = 0;
	c = getchar();
	while (!(c >= '0' && c <= '9') && c != -1 && c != '-')c = getchar();
	if (c == -1)return 0;
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	for (; c >= '0' && c <= '9'; c = getchar())
		n = n * 10 + c - 48;
	if (negative)
		n *= -1;
	return 1;
}
template <class T>
void printrec(T n)
{
	if (n == 0) {
		return;
	}
	if (n < 0)
	{
		putchar('-');
		n *= -1;
	}
	printrec(n / 10);
	putchar_unlocked(n % 10 + 0x30);
}
template <class T>
void print(T n)
{
	if (n == 0)
	{
		putchar_unlocked('0');
		return;
	}
	else
	{
		printrec(n);
	}
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
	while (scan(a))
	{
		print(a);
		printf("\n");
	}

	/*
	ulll a,b;
	scan(a);
	scan(b);
	ulll c=__gcd(a,b);
	print(c);
	*/
	return 0;
}