 
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
#define _mp make_pair
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
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
inline bool ispalin(string s) { for(int i=0,j=s.size()-1;i<=j;i++,j--) if(s[i]!=s[j]) return false; return true; }
inline lld lcm(lld a,lld b){ return (a/__gcd(a, b))*b; }
void fastscan(lld &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
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
#define LOGN 20
vector<lld> adj[2*MAX];
vector<lld> one,two;
lld cost[2*MAX];
lld ans;
lld pa[2*MAX][LOGN];
lld depth[2*MAX];
lld Depth[2*MAX];
int LCA(int u, int v)
{
	if(Depth[u] < Depth[v])
		return LCA(v, u);

	int diff = Depth[u] - Depth[v];

	rep(i,0,LOGN)
		if((diff>>i) & 1)
			u = pa[u][i];

	if(u != v){
		repd(i, LOGN-1, 0){
			if(pa[u][i] != pa[v][i]){
				u = pa[u][i];
				v = pa[v][i];
			}
		}	
		u = pa[u][0];
	}
	return u;
}
void dfs(lld curr, lld prev){
	pa[curr][0] = prev;
	depth[curr] = (prev==-1)? cost[curr]:depth[prev]+cost[curr];
	Depth[curr] = (prev==-1)? 0:Depth[prev]+1;
	for(auto it:adj[curr]){
		if(it!=prev){
			dfs(it, curr);
		}
	}
}
unordered_map<lld,lld> Fib;
lld fib(lld n)
{
    if(n<2) return 1;
    if(Fib.find(n) != Fib.end()) return Fib[n];
    Fib[n] = (fib((n+1) / 2)*fib(n/2) + fib((n-1) / 2)*fib((n-2) / 2)) % MOD;
    return Fib[n];
}
int main()
{
	FIO
	lld n;
	fastscan(n);
	rep(i,1,n){
		lld u, v;
		fastscan(u);
		fastscan(v);
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	rep(i,0,n){
		lld c;
		fastscan(c);
		cost[i] = c;
	}
	memset(pa, -1, sizeof pa);
	dfs(0, -1);

	rep(i,0,LOGN-1)
		rep(j,0,n)
			if(pa[j][i] != -1)
				pa[j][i+1] = pa[pa[j][i]][i];
				
	lld half = sqrt(n);
	rep(i,0,half+1){
		rep(j,0,half+1){
			lld lca = LCA(i,j);
			lld idx = depth[i] + depth[j] - 2*depth[lca] + cost[lca];
			ans =  (ans%MOD + fib(idx)%MOD)%MOD;
			if(j==half)one.push_back(i);
		}
	}
	rep(i,half,n){
		rep(j,half,n){
			if(i==half and j==half)continue;
			lld lca = LCA(i,j);
			lld idx = depth[i] + depth[j] - 2*depth[lca] + cost[lca];
			ans =  (ans%MOD + fib(idx)%MOD)%MOD;
			if(i==half)two.push_back(j);
		}
	}
	for(auto it1:one){
		for(auto it2:two){
			if(it1==half)continue;
			lld i = it1, j = it2;
			lld lca = LCA(i,j);
			lld idx = depth[i] + depth[j] - 2*depth[lca] + cost[lca];
			ans =  (ans%MOD + 2*fib(idx)%MOD)%MOD;
		}
	}
	printf("%lld\n",ans%MOD);
}
