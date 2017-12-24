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
const int N = 4e5+5;
vector<int> v;
int a[N];
vector<int> tree[N];
void build(int node,int start,int end){
	int lchild=2*node,rchild=2*node+1,mid=(start+end)>>1;
	if(start==end){
		tree[node].pb(a[start]);
		return;
	}
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	merge(tree[lchild].begin(),tree[lchild].end(),tree[rchild].begin(),tree[rchild].end(),back_inserter(tree[node]));
}
int query(int node,int start,int end,int l,int r,int x){
	int lchild=2*node,rchild=2*node+1,mid=(start+end)>>1;
	if(end<l or start>r)return  0;
	if(start>=l and end<=r){
		int k = upper_bound(all(tree[node]),x)-tree[node].begin();
		return k;
	}
	return query(lchild,start,mid,l,r,x) + query(rchild,mid+1,end,l,r,x);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1){	
		scan(a[i]);
		v.pb(a[i]);
	}
	sort(all(v));
	rep(i,1,n+1){
		a[i] = lower_bound(all(v),a[i])-v.begin()+1;
	}
	build(1,1,n);
	rep(i,0,m){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		int left=1,right=n,MID,ans;
		while(left<=right){
			MID = (left+right)>>1;
			int k=query(1,1,n,l,r,MID);
			if(k>=x){
				ans=MID;
				right=MID-1;
			}
			else left=MID+1;
		}
		printf("%d\n",v[ans-1]);
	}
}
