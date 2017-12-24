
/*
 
		 /-----                      |
		/                            |                                         |           |
	   /                             |                                         |           |
	  /------  /---/ ////  /---/  /--|   /---/ \    /     /---/ |----|  |----  |---- |   | |
	 /        /   /  /    /   /  /   |  /   /   \  /     /   /  |    |  |____  |   | |   | |
	/         \___\  /    \___\  \___|  \___\    \/ _____\___\  |    | _____|  |   | |___| |
	                                             /
	                                            /
	                                           /
*/	 
//  :::::::::::::::faraday_anshul:::::::::::::::::                      // 
//  Indian Institute Of Information Technology and Management,Gwalior.  //                                                   												
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define T() int t; cin>>t; while(t--)                      
#define rep(i,start,lim) for(int i=start;i<lim;i++)
#define repd(i,start,lim) for(int i=start;i>=lim;i--)
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld",x)
#define space printf(" ")
#define br printf("\n");
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
using namespace std;
typedef long double ldb;
typedef long long lld;
typedef unsigned long long ulld;
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
inline bool ispalin(string s) { for(int i=0,j=s.size()-1;i<=j;i++,j--) if(s[i]!=s[j]) return false; return true; }
inline lld lcm(lld a,lld b){ return (a/__gcd(a, b))*b; }
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
#define N 40000
#define MAXN 1000001
int a[N],pre[N],n,m,dummy[MAXN];
struct node{
	int count;
	node *left, *right;
	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}
	node *insert(int l, int r, int w);
};
node *null = new node(0, NULL, NULL);
node *root[N];
node * node::insert(int l, int r, int w){
	if(l<=w and w<=r){
		if(l==r){
			return new node(this->count+1, null, null);
		}
		int mid = (l+r)>>1;
		return new node(this->count+1, this->left->insert(l, mid, w), this->right->insert(mid+1, r, w));
	}
	return this;
}
int query(node *a, int start, int end, int l, int r){
	if(end<l or start>r)return 0;
	if(start>=l and end<=r){
		return a->count;
	}
	int mid = (start+end)>>1;
	return query(a->left, start, mid, l , r) + query(a->right, mid+1, end, l, r);
}
int main()
{
	scanf("%d",&n);
	rep(i,1,n+1){
		scanf("%d",&a[i]);
		dummy[a[i]] = 0;
	}
	rep(i,1,n+1){
		pre[i] = dummy[a[i]];
		dummy[a[i]] = i;
	}
	//rep(i,1,n+1)printf("%d ",pre[i]);
	null->left = null->right = null;
	root[0] = null;
	rep(i,1,n+1){
		root[i] = ((i==1)? null:root[i-1])-> insert(0, n, pre[i]);
	}
	scanf("%d",&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		int x = query(root[u-1], 0, n, 0, u-1);
		int y = query(root[v], 0, n, 0, u-1);
		printf("%d\n", y-x);
	}
	return 0;
}








