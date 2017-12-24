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
const int N = 5e5 + 5;
lld n, q, L, R;
lld arr[N];

struct segtree {
	lld ans, leftbest, rightbest;
	inline void merge(const segtree &l, const segtree &r, lld start, lld mid, lld end) {
		lld right = r.leftbest, left = l.rightbest;
		ans = l.ans + r.ans - (right*(right+1)/2) - (left*(left+1)/2) + (right+left)*(right+left+1)/2;
		leftbest = (left == mid - start + 1)? left + right: l.leftbest;
		rightbest = (right == end - mid)? left + right: r.rightbest;
	}
}tree[4*N], ped[4*N];

void build(lld node, lld start, lld end) {
	if(start == end) {
		tree[node].ans = tree[node].leftbest = tree[node].rightbest = arr[start];
		ped[node].ans = ped[node].leftbest = ped[node].rightbest = arr[start];
		return;
	}
	lld mid = (start + end) >> 1;
	lld lchild = 2*node, rchild = 2*node + 1;
	build(lchild, start, mid);
	build(rchild, mid + 1, end);
	tree[node].merge(tree[lchild], tree[rchild], start, mid, end);
	ped[node].merge(ped[lchild], ped[rchild], start, mid, end);
}

void update1(lld node, lld start, lld end, lld index, lld val) {
	if(start == end) {
		tree[node] .ans = tree[node].leftbest = tree[node].rightbest = val;
		return;
	}
	lld mid = (start + end) >> 1;
	lld lchild = 2*node, rchild = 2*node + 1;
	if(start <= index and index <= mid) update1(lchild, start, mid, index, val);
	else update1(rchild, mid + 1, end, index, val);
	tree[node].merge(tree[lchild], tree[rchild], start, mid, end);
}

void update2(lld node, lld start, lld end, lld index, lld val) {
	if(start == end) {
		ped[node] .ans = ped[node].leftbest = ped[node].rightbest = val;
		return;
	}
	lld mid = (start + end) >> 1;
	lld lchild = 2*node, rchild = 2*node + 1;
	if(start <= index and index <= mid) update2(lchild, start, mid, index, val);
	else update2(rchild, mid + 1, end, index, val);
	ped[node].merge(ped[lchild], ped[rchild], start, mid, end);
}

segtree query1(lld node, lld start, lld end, lld l, lld r) {
	if(r < start or end < l) {
		segtree nude;
		nude.ans = nude.leftbest = nude.rightbest = 0;
		return nude;
	}
	if(l <= start and end <= r) {
		return tree[node];
	}
	lld mid = (start + end) >> 1;
	lld lchild = 2*node, rchild = 2*node + 1;
	segtree first = query1(lchild, start, mid, l, r);
	segtree second = query1(rchild, mid + 1, end, l, r);
	segtree nude;
	nude.merge(first, second, start, mid, end);
	return nude;
}
segtree query2(lld node, lld start, lld end, lld l, lld r) {
	if(r < start or end < l) {
		segtree nude;
		nude.ans = nude.leftbest = nude.rightbest = 0;
		return nude;
	}
	if(l <= start and end <= r) {
		return ped[node];
	}
	lld mid = (start + end) >> 1;
	lld lchild = 2*node, rchild = 2*node + 1;
	segtree first = query2(lchild, start, mid, l, r);
	segtree second = query2(rchild, mid + 1, end, l, r);
	segtree nude;
	nude.merge(first, second, start, mid, end);
	return nude;
}
void init() {
	cin >> n >> q >> L >> R;
	rep(i, 1, n + 1) arr[i] = 1;
	build(1, 1, n);
}

void solve() {
	lld _case, x, y, l, r;
	while(q--) {
		cin >> _case;
		if(_case == 1) {
			cin >> x >> y;
			if(y > R) update1(1, 1, n, x, 0), update2(1, 1, n, x, 0);
			if(L <= y and y <= R) update1(1, 1, n, x, 1), update2(1, 1, n, x, 0);
			if(y < L) update1(1, 1, n, x, 1), update2(1, 1, n, x, 1); 
		}
		else {
			cin >> l >> r;
			cout << query1(1, 1, n, l, r).ans - query2(1, 1, n, l, r).ans << endl;
		}
	}
}
int main() {
	FIO
	init();
	solve();
}
