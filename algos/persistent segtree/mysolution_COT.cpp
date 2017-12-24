
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
#define N 111111
#define LOGN 19
int n,m;
int pa[N][LOGN],arr[N],depth[N];
vector<int> adj[N];
vector<int> V;
struct node{
	int count;
	node *left, *right;
	node(int count,node *left,node *right):
		count(count),left(left),right(right) {}
	node* insert(int l,int r,int w);
};
node *null = new node(0,NULL,NULL);
node *root[N];

node * node::insert(int l,int r,int w){
	if(l<=w and w<=r){
		if(l==r){
			return new node(this->count+1,null,null);
		}
		int mid=(l+r)>>1;
		return new node(this->count+1,this->left->insert(l,mid,w),this->right->insert(mid+1,r,w));
	}
	return this;
}

void dfs(int cur,int prev){
	pa[cur][0] = prev;
	depth[cur] = (prev==-1)? 0:depth[prev]+1;
	root[cur] = ((prev==-1)? null:root[prev])-> insert(0,n-1,arr[cur]);
	rep(i,0,adj[cur].size()){
		if(adj[cur][i]!=prev)
			dfs(adj[cur][i],cur);
	}
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k){
	if(l == r)
		return l;
	int count = a->left->count + b->left->count - c->left->count - d->left->count;
	int mid=(l+r)>>1;
	if(count >= k)
		return query(a->left, b->left, c->left, d->left, l, mid, k);
	return query(a->right, b->right, c->right, d->right, mid+1, r, k-count);	
}
int LCA(int u, int v)
{
	if(depth[u] < depth[v])
		return LCA(v, u);

	int diff = depth[u] - depth[v];

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
int main()
{
	//inputs
	scanf("%d %d",&n,&m);
	rep(i,0,n){
		scanf("%d",&arr[i]);
		V.pb(arr[i]);
	}
	rep(i,0,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	//end
	
	sort(all(V));
	rep(i,0,n){
		arr[i] = lower_bound(all(V),arr[i]) - V.begin();
	}
	memset(pa,-1,sizeof pa);
	null->left=null->right=null;
	dfs(0,-1);
	
	rep(i,0,LOGN-1)
		rep(j,0,n)
			if(pa[j][i] != -1)
				pa[j][i+1] = pa[pa[j][i]][i];
	
	while(m--){
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		l--,r--;
		int lca = LCA(l, r);
		int at = query(root[l],root[r],root[lca],(pa[lca][0]==-1 ? null:root[pa[lca][0]]), 0,n-1,k);
		printf("%d\n",V[at]);
	}
}
