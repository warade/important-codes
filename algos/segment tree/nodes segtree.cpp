



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
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld ",x)
#define sz(a) lld((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define YES printf("YES\n")
#define NO printf("NO\n")
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(it,c) for(__typeof(c.begin()) it = c.begin(); it!=c.end(); ++it)
#define br printf("\n")
#define checkbit(n,b) ((n>>b)&1)
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
typedef vector<lld> vlld;
typedef pair<lld,lld> plld;
typedef map<lld,lld> mlld;
typedef set<lld> slld;
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
lld A[MAX];
struct node{
	int maxi, mini, cnt, sum;
	inline void leaf(const int &val,const int &y){
		maxi = mini = sum = val;
		cnt = y;
	}
	inline void merge(const node &l,const node &r){
		maxi = max(l.maxi,r.maxi);
		mini = min(l.mini,r.mini);
	}
}tree[4*N];
 
 
void build(int root,int start,int end){
	const int &mid = (start+end)>>1,&lchild = 2*root + 1,&rchild = lchild + 1;
	if(start==end){
		tree[root].leaf(A[start],end-start+1);
		return;
	}
	build(lchild,start,mid);
	build(rchild,mid+1,end);
	tree[root].merge(tree[lchild],tree[rchild]);
}
 
node query(int root,int start,int end,int l,int r){
	const int &mid = (start+end)>>1,&lchild = 2*root + 1,&rchild = lchild + 1;
	if(start==l && end==r)	
	return tree[root];
	if(l>mid)  return query(rchild,mid+1,end,l,r);
	else if(r<=mid) return query(lchild,start,mid,l,r);
	else{
		node n3;
		n3.merge(query(lchild,start,mid,l,mid), query(rchild,mid+1,end,mid+1,r));
		return n3;
	}
}
void update(int root,int start,int end,int pos,int val){
	const int &mid = (start+end)>>1,&lchild = 2*root + 1,&rchild = lchild + 1;
	if(start==end){
		A[pos]=val;tree[root].leaf(val,1);
	}
	else{
		if(start<=pos and pos<=mid) update(lchild,start,mid,pos,val);
		else update(rchild,mid+1,end,pos,val);
		tree[root].merge(tree[lchild],tree[rchild]);
	}
}

void updateRange(int root,int start,int end,int l,int r,int val){
	const int &mid = (start+end)>>1,&lchild = 2*root + 1,&rchild = lchild + 1;
	if(start>end or start>r or end<l){
		return;
	}
	if(start==end){
		tree[root].leaf(val,1);
		return;
	}
	updateRange(lchild,start,mid,l,r,val);
	updateRange(rchild,mid+1,end,l,r,val);
	tree[root].merge(tree[lchild],tree[rchild]);
	
}
int main()
{
	FIO
	lld n,k,ans;
	cin>>n;
	rep(i,0,n)cin>>A[i];
	build(0,0,n-1);
	ans=query(0,0,n-1,1,3).sum;
	cout<<ans<<endl;
	while(1){
		lld pos,val;
		cin>>pos>>val;
		update(0,0,n-1,pos,val);
		rep(i,0,2*n-1)trace2(i,tree[i].sum);
		lld l,r;
		cin>>l>>r>>val;
		updateRange(0,0,n-1,l,r,val);
		rep(i,0,2*n-1)trace2(i,tree[i].sum);
	}
	cout<<ans<<endl;
}

