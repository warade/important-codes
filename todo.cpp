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
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
inline bool ispalin(string s) { for(int i=0,j=s.size()-1;i<=j;i++,j--) if(s[i]!=s[j]) return false; return true; }
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
lld x[N], compressed[N], done[N], bit[N];
char c[N];
vector<lld> queries;
set<lld> S;
map<lld, lld> family;
void insert(lld idx, lld val) {
	while(idx <= N) {
		bit[idx] += val;
		idx += idx & -idx;
	}
}
lld read(lld idx) {
	lld res = 0;
	while(idx > 0) {
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int main() {
	lld q;
	scanf("%lld", &q);
	rep(i, 1, q + 1) {
		fflush(stdin);
		scanf("%c %lld", &c[i], &x[i]);
		if(c[i] != 'K')
		queries.emplace_back(x[i]);
	}
	sort(all(queries));
	rep(i, 1, q + 1) {
		if(c[i] != 'K')
		compressed[i] = lower_bound(all(queries), x[i]) - queries.begin() + 1, 
		family[compressed[i]] = x[i];
	}
	rep(i, 1, q + 1) {
		if(c[i] == 'I') {
			if(!done[compressed[i]])
			insert(compressed[i], 1), done[compressed[i]] = 1, S.insert(x[i]);
		}
		if(c[i] == 'D') {
			if(done[compressed[i]])
			insert(compressed[i], -1), done[compressed[i]] = 0, S.erase(x[i]);
		}
		if(c[i] == 'C') {
			printf("%lld\n", read(compressed[i]-1));
		}
		if(c[i] == 'K') {
			if(x[i] > S.size()) printf("invalid\n");
			else {
				lld start = 1, end = N, k = x[i], mid;
				while(start <= end) {
				   mid = (start+end) >> 1;
				   if(read(mid) >= k) end=mid-1;
				   else start = mid+1;
				}
				printf("%lld\n", family[start]);
			}
		}
	}
}

