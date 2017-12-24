/*
 
		 /-----                      |                                         |           |
		/                            |                                         |           |
	   /                             |                                         |           |
	  /------  /---/ ////  /---/  /--|   /---/ \    /     /---/ |----|  |----  |---- |   | |
	 /        /   /  /    /   /  /   |  /   /   \  /     /   /  |    |  |____  |   | |   | |
	/         \___\  /    \___\  \___|  \___\    \/ _____\___\  |    | _____|  |   | |___| |
												 /
												/
											   /
*/
//  Indian Institute Of Information Technology and Management,Gwalior.  //                                                   												
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define T() int t; cin>>t; while(t--)                      
#define rep(i,start,lim) for(int i=start;i<lim;i++)
#define repd(i,start,lim) for(int i=start;i>=lim;i--)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define YES printf("YES\n")
#define NO printf("NO\n")
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define debug cout<<"here"<<endl
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#else
#define trace1(x)                printf("")
#define trace2(x, y)             printf("")
#define trace3(x, y, z)          printf("")
#define trace4(a, b, c, d)       printf("")
#define trace5(a, b, c, d, e)    printf("")
#define trace6(a, b, c, d, e, f) printf("")
#endif
#define MAX 100005
#define LIMIT       262950
#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define MOD         1000000007
#define PI          3.14159265358979323
#define gc getchar
using namespace std;

typedef long double ldb;
typedef long long lld;
typedef unsigned long long ulld;
typedef pair<lld, lld> plld;
typedef vector<lld, lld> vlld;
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
inline bool ispalin(vector<lld> s) { for(int i=0,j=s.size()-1;i<=j;i++,j--) if(s[i]!=s[j]) return false; return true; }
inline lld lcm(lld a,lld b){ return (a/__gcd(a, b))*b; }
void fastscan(int &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

#define sz(c) (c).size()
///******Lets start coding :-) *******//
/*
struct DSU{
	lld p[MAX];
	void init(lld n){
		rep(i,1,n+1)p[i]=i;
	}
	int find(lld x){
		if(p[x]==x)return x;
		return p[x]=find(p[x]);
	}
	void join(lld x,lld y){
		x=find(x);
		y=find(y);
		if(x==y)return;
		p[y]=x;
	}
}dsu;

*/
const int N = 2e5 + 5;
vector<lld> prefix[N], arr[N];
map< pair<lld, lld>, lld> memo;
int main() {
	 FIO
	 lld n, m, sze, el;
	 cin >> n;
	 rep(i, 1, n + 1) {
	 	cin >> sze;
	 	rep(j, 0, sze) {
	 		cin >> el;
	 		arr[i].emplace_back(el);
	 	}
	 	sort(all(arr[i]));
	 }
	 rep(i, 1, n + 1) {
	 	rep(j, 0, sz(arr[i])) {
	 		if(j != 0)
	 		prefix[i].emplace_back(*prev(prefix[i].end()) + arr[i][j]);
	 		else prefix[i].emplace_back(arr[i][j]);
	 	}
	 }
	 cin >> m;
	 while(m--) {	
	 	lld u, v;
	 	cin >> u >> v;
	 	if(sz(arr[u]) > sz(arr[v])) swap(u, v);
	 	lld ans = 0; 
	 	if(memo.find(make_pair(u, v)) != memo.end()) {
	 		cout << memo[make_pair(u, v)] << endl;
	 		continue;
	 	}
	 	for(auto it: arr[u]) {
	 		lld left = upper_bound(all(arr[v]), it) - arr[v].begin(), right = sz(arr[v]) - left;
	 		ans -= prefix[v][left-1], ans += left*it, ans -= right*it, ans += prefix[v][sz(prefix[v])-1] - prefix[v][left-1];
	 	}
	 	memo[make_pair(u, v)] = ans;
	 	cout << ans << endl;
	 }
}

