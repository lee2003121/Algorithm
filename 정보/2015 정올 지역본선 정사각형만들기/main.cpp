#include <bits/stdc++.h>
using namespace std;

int n, m;

int dp[10001][101];
int dfs(int l, int r) {
	if (dp[l][r] != -1)return dp[l][r];
	if (l == r)return dp[l][r] = 0;
	int ret = 987564321;
	if (l >= r * 3)
        return dp[l][r] = 1 + dfs(l - r, r);
	for(int i=1;i<=l-1;i++)
        ret = min(ret, dfs(i, r) + dfs(l - i, r) + 1);
    for(int i=1;i<=r-1;i++)
        ret = min(ret, dfs(l, i) + dfs(l, r - i) + 1);
	return dp[l][r] = ret;
}

int main() {
	scanf("%d %d",&n,&m);
	memset(dp, -1, sizeof(dp));
	printf("%d",dfs(n, m) + 1);
}
