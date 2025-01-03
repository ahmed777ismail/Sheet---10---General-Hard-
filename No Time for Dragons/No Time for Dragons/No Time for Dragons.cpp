#include<bits/stdc++.h>
using namespace std;
int main() {

	long long size;
	cin >> size;
	vector<pair<long, pair<long, long> > > v(size);

	for (int i = 0; i < size; i++) {
		long long n1, n2;
		cin >> n1 >> n2;
		v[i].first = (n1 - n2);
		v[i].second = { n1,n2 };
	}
	sort(v.begin(), v.end());
	long long total = v[size - 1].second.first;
	long long sol = v[size - 1].first;

	for (int i = size - 2; i >= 0; i--) {
		if (sol < v[i].second.first) {
			total += v[i].second.first - sol;
			sol = v[i].first;
		}
		else {
			sol -= v[i].second.second;
		}
	}
	cout << total;

}