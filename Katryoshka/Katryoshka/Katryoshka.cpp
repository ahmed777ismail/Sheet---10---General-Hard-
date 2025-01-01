#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, k, res = 0; cin >> n >> m >> k;
    long long minn = min({ n,m,k });
    res += minn;
    n -= minn;
    m -= minn;
    k -= minn;
    res += min(n / 2, k);
    cout << res;
    return 0;
}