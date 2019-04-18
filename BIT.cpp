#include <bits/stdc++.h>
using namespace std;

// careful using int in this code... you may need long long
// 1 based indexing 
// check the value of mx

const static int mx=200010;
int BIT[mx];

void update(int pos,int val)
{
	for(;pos<=mx;pos+=pos&(-pos))BIT[pos]+=val;
}
int query(int pos)
{
	int sum=0;
	for(;pos>0;pos-=pos&(-pos))sum+=BIT[pos];
	return sum;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}