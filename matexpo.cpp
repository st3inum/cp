#include <bits/stdc++.h>
using namespace std;

template<class T>
class matrix
{
	typedef vector<vector<T>> mat;
public:
	mat I;
	matrix() {}
	matrix(int n) {
		vector<T> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			v[i] = 1;
			I.push_back(v);
			v[i] = 0;
		}
	}
	matrix(int r, int c, T val)
	{
		I.resize(r, vector<T> (c, val));
	}
	matrix(mat v)
	{
		I = v;
	}
	~matrix() {
		I.clear();
	}
	void print()
	{
		for (int i = 0; i < I.size(); i++)
		{
			for (int j = 0; j < I[0].size(); j++)cout << I[i][j] << ' '; cout << endl;
		}
	}

	matrix operator + (matrix const &obj) {
		assert(I.size() == obj.I.size() && I[0].size() == obj.I[0].size());
		matrix temp;
		for (int i = 0; i < I.size(); i++)
		{
			vector<T> v;
			for (int j = 0; j < I[0].size(); j++)
			{
				v.push_back(I[i][j] + obj.I[i][j]);
			}
			temp.I.push_back(v);
		}
		return temp;
	}
	void operator = (const matrix & obj ) {
		I = obj.I;
	}
	matrix operator * (matrix const &obj) {
		assert(I[0].size() == obj.I.size());
		matrix temp(I.size(), obj.I[0].size(), 0);
		for (int i = 0; i < I.size(); i++)
		{
			for (int j = 0; j < obj.I[0].size(); j++)
			{
				for (int k = 0; k < I[0].size(); k++)
				{
					temp.I[i][j] += I[i][k] * obj.I[k][j];
					//temp.I[i][j] %= mod;
				}
			}
		}
		return temp;
	}
	matrix operator * (T const &obj) {
		matrix temp(I.size(), I[0].size(), 0);
		for (int i = 0; i < I.size(); i++)
		{
			for (int j = 0; j < I[0].size(); j++)
			{
				temp.I[i][j] = I[i][j] * obj;
			}
		}
		return temp;
	}
	matrix operator % (T const &obj) {
		matrix temp=I;
		for (int i = 0; i < I.size(); i++)
		{
			for (int j = 0; j < I[0].size(); j++)
			{
				temp.I[i][j] = temp.I[i][j] % obj;
			}
		}
		return temp;
	}
};


template<class T>
matrix<T> pow(matrix<T> a, long long b, long long mod)
{
	if (!b)return matrix<T>(a.I.size())%mod;
	matrix<T> p = pow(a, b >> 1,mod);
	matrix<T> q = (p * p)%mod;
	if (b & 1)return (q * a)%mod;
	return q;
}






int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for(int I=1;I<=t;I++)
	{
		printf("Case %d: ",I);
		int a,b,c,d,p=1;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		matrix<int> arr,brr;
		brr.I.push_back({b,a});
		arr.I.push_back({1,1});
		arr.I.push_back({1,0});
		while(d--)p*=10;
		arr=pow(arr,c,p);
		arr=(brr*arr)%p;
		printf("%d\n", arr.I[0][1]);
	}
	return 0;
}