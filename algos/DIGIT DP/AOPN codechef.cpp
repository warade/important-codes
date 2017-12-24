/* Man Mohan Mishra
   IIIT Allahabad
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long dp[20][10][10][2][2][2];
vector <int> dig;
 
long long count(long long n) {
	int i,j,k,is_odd,is_even,cur,sz;
	long long ans;
	dig.clear();
	while (n > 0) {
		dig.push_back(n % 10);
		n = n / 10;
	}
	sz = dig.size();
	reverse(dig.begin(),dig.end());
	if (sz < 3) return 0LL;
	memset(dp,0LL,sizeof(dp));
	for (i = 1; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (i * 10 + j <= dig[0] * 10 + dig[1]) {
				dp[1][i][j][0][i == j][(i * 10 + j) == (dig[0] * 10 + dig[1])] += 1;
			}
		}
	}
	for (i = 2; i < sz; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				for (is_odd = 0; is_odd < 2; is_odd++) {
					for (is_even = 0; is_even < 2; is_even++) {
						for (cur = 0; cur < 10; cur++) {
							dp[i][k][cur][is_odd | (cur == j)][is_even | (cur == k)][0] += dp[i - 1][j][k][is_odd][is_even][0];
							if (cur == dig[i]) {
								dp[i][k][cur][is_odd | (cur == j)][is_even | (cur == k)][1] += dp[i - 1][j][k][is_odd][is_even][1];
							} else if (cur < dig[i]) {
								dp[i][k][cur][is_odd | (cur == j)][is_even | (cur == k)][0] += dp[i - 1][j][k][is_odd][is_even][1];
							}
						}
					}
				}
			}
		}
		for (j = 1; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				dp[i][j][k][0][j == k][0] += 1;
			}
		}
	}
	ans = 0LL;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			ans += dp[sz - 1][i][j][1][1][0];
			ans += dp[sz - 1][i][j][1][1][1];
		}
	}
	return ans;
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while (t --) {
		long long a,b,ans;
		scanf("%lld%lld",&a,&b);
		ans = count(b) - count(a);
		printf("%lld\n",ans);
	}
	return 0;
}
