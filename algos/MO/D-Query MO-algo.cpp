



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
#define MAX 300001
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
int A[MAX],n,q,BLOCK_SIZE,ans[311111],cnt[1111111],current_ans;
struct node{
	int l,r,id;
}queries[311111];

bool mo_comp(node a,node b){
	if((a.l/BLOCK_SIZE)!=(b.l/BLOCK_SIZE)){
		return (a.l/BLOCK_SIZE)<(b.l/BLOCK_SIZE);
	}
	else return a.r < b.r; 
}
inline void add(int x){
	if(cnt[x]==0)
	current_ans++;
}
inline void remove(int x){
	if(cnt[x]==1)
	current_ans--;
}
int main()
{
	//FIO
	scanf("%d",&n);
	BLOCK_SIZE = int(sqrt(n));
	rep(i,0,n)scanf("%d",&A[i]);
	scan(q);
	rep(j,0,q){
		int l,r;
		scanf("%d%d",&l,&r);
		l--,r--;
		queries[j].l=l,queries[j].r=r,queries[j].id=j;
	}
	sort(queries,queries+q,mo_comp);
	int mo_left=0,mo_right=-1;
	rep(i,0,q){
		int left=queries[i].l,right=queries[i].r,idx=queries[i].id;
		while(mo_right<right){
			mo_right++;
			add(A[mo_right]);
			cnt[A[mo_right]]++;
		}
		while(mo_left>left){
			mo_left--;
			add(A[mo_left]);
			cnt[A[mo_left]]++;
		}
		while(mo_left<left){
			remove(A[mo_left]);
			cnt[A[mo_left]]--;
			mo_left++;
		}
		while(mo_right>right){
			remove(A[mo_right]);
			cnt[A[mo_right]]--;
			mo_right--;
		}
		ans[idx]=current_ans;
	}
	rep(i,0,q)printf("%d\n",ans[i]);
}

