#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
template<class T>
class matrix
{
	typedef vector<vector<ull>> mat;
public:
	mat I;
	matrix() {}
	matrix(int n) {
		vector<ull> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			v[i] = 1;
			I.push_back(v);
			v[i] = 0;
		}
	}
	matrix(int r, int c, int val)
	{
		I.resize(r, vector<ull> (c, val));
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
			vector<ull> v;
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
				}
			}
		}
		return temp;
	}
};

template<class T>
matrix<T> pow(matrix<T> a, ull b)
{
	if (!b)return matrix<T>(a.I.size());
	matrix<T> p = pow(a, b >> 1);
	matrix<T> q = (p * p);
	if (b & 1)return q * a;
	return q;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	for (int I = 1; I <= t; I++)
	{
		printf("Case %d: ", I);
		ull a, b, c;
		scanf("%llu %llu %llu", &a, &b, &c);
		vector<vector<ull>> kk, k;
		kk.push_back({a, 1});
		kk.push_back({ -b, 0});
		k.push_back({a, 2});
		matrix<ull> ans(kk);
		ans = pow(ans, c);
		ans = matrix<ull>(k) * ans;
		printf("%llu\n", ans.I[0][1]);
	}
}