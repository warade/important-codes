/*
	By Anudeep Nekkanti
	Editorial at www.blog.anudeep.com/persistent-segment-trees-explained-with-spoj-problems
	Question at http://www.spoj.com/problems/COT/
	O( (N+M) * log N )
*/
#include<bits/stdc++.h>
using namespace std;
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
#define sz size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)

#define N 111111
#define LN 19
int v[N], pa[N][LN], RM[N], depth[N], maxi = 0;
vector <int> adj[N];
map <int, int> M;

struct node
{
	int count;
	node *left, *right;

	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}

	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL); //see line 135

node * node::insert(int l, int r, int w)
{
	trace4(this->count,l,r,w);
	if(l <= w && w <= r)
	{
		// With in the range, we need a new node
		if(l == r)
		{
			return new node(this->count+1, null, null);
		}

		int m = (l+r)>>1;

		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m+1, r, w));
	}

	// Out of range, we can use previous tree node.
	return this;
}

node *root[N];
void dfs(int cur, int prev)
{
	pa[cur][0] = prev;
	depth[cur] = (prev == -1 ? 0 : depth[prev] + 1);

	// Construct the segment tree for this node using parent segment tree	
	// This is the formula we derived
	//trace6(cur,prev,root[cur],v[cur],M[v[cur]],maxi);
	root[cur] = ( prev == -1 ? null : root[prev] )->insert( 0, maxi, M[v[cur]] );
	printf("\n");

	rep(i, adj[cur].sz)
		if(adj[cur][i] != prev)
			dfs(adj[cur][i], cur);
}

int LCA(int u, int v)
{
	if(depth[u] < depth[v])
		return LCA(v, u);

	int diff = depth[u] - depth[v];

	rep(i, LN)
		if((diff>>i) & 1)
			u = pa[u][i];

	if(u != v)
	{
		fd(i, LN-1, 0)
			if(pa[u][i] != pa[v][i])
			{
				u = pa[u][i];
				v = pa[v][i];
			}
		u = pa[u][0];
	}

	return u;
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k)
{
	if(l == r){
		return l;
	}
	
	// This is the formula we derived
	int count = a->left->count + b->left->count - c->left->count - d->left->count;
	int m = (l+r)>>1;

	// We have enough on left, so go left
	if(count >= k)
		return query(a->left, b->left, c->left, d->left, l, m, k);

	// We do not have enough on left, go right, remove left elements count
	return query(a->right, b->right, c->right, d->right, m+1, r, k - count);
}
void func(node *a,char ch){
	if(a==null)return;
	printf("%d-%c ",a->count,ch);
	func(a->left,'l');
	func(a->right,'r');
}
int main()
{
	int n, m;

	scanf("%d%d", &n, &m);

	rep(i, n){
		scanf("%d", &v[i]);
		M[v[i]];
	}

	maxi = 0;
	for( map <int, int > :: iterator it = M.begin(); it != M.end(); it++ ){
		M[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}
	maxi--;
	for(int i=0; i<n-1; i++)printf("%d %d\n",M[RM[i]],RM[i]);
	// We compressed the given weights into the range [0..n)

	rep(i, n-1){
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	// Root the tree at some node.
	memset(pa, -1, sizeof pa);
	// node's left and right are also pointers so set them equal to null;;;;;;
	null->left = null->right = null;
	dfs(0, -1);
	
	rep(i,8){
		func(root[i],'x');
		printf("\n");
	}
	// Build jump table for LCA in O( log N )
	rep(i, LN-1)
		rep(j, n)
			if(pa[j][i] != -1)
				pa[j][i+1] = pa[pa[j][i]][i];

	while(m--)
	{
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		u--; v--;

		int lca = LCA(u, v);
		// Four nodes we spoke about are u, v, lca, parent(lca)
		int ans = query(root[u], root[v], root[lca], (pa[lca][0] == -1 ? null : root[ pa[lca][0] ]), 0, maxi, k);

		// Reverse Map the values, that is, uncompress
		printf("%d\n", RM[ans]);
	}
}
