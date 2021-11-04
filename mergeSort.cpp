#include <bits/stdc++.h>
using namespace std;

// see value of mx
// see data type of arr
const static int mx = 200010;
int arr[mx], temp[mx];
// arr = array that I need to sort
void mergesort(int l, int r) {
	if (l < r) {
		int mid = (l + r) >> 1;
		mergesort(l, mid);
		mergesort(mid + 1, r);
		int x = l, y = mid + 1, k = l;
		while (x <= mid && y <= r) {
			if (arr[x] < arr[y])temp[k++] = arr[x++];
			else temp[k++] = arr[y++];
		}
		while (x <= mid)temp[k++] = arr[x++];
		while (y <= r)temp[k++] = arr[y++];
		for (x = l; x <= r; x++)arr[x] = temp[x];
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	mergesort(0, n - 1);
	for (int i = 0; i < n; i++)cout << arr[i] << '\n';
	return 0;
}
