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
template<typename T1, typename T2> inline pair<T1, T2> operator+(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first + p2.first, p1.second + p2.second); }
template<typename T1, typename T2> inline pair<T1, T2> operator-(const pair<T1, T2> &p1 , const pair<T1, T2> &p2) { return pair<T1, T2>(p1.first - p2.first, p1.second - p2.second); }
#define DA(a,n) cout<<#a<<"=[ "; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=[ "; printarray(a,n,s); cout<<"]\n"
template<typename T, typename T2>void printarray(T a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; }
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

#define N 100
lld dp[N][N];
lld s[N][N];
void insert_braces(int i,int j)
{
	if(i==j){
		cout<<"A"<<i;
	}
	else{
		cout<<"(";
		insert_braces(i,s[i][j]);
		insert_braces(s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
	FIO
	lld n,length,q;
	cin>>n;
	lld p[n+1];
	rep(i,0,n+1)cin>>p[i];
	length=n;
	for(int l=2; l<=n; l++){
		for(int i=1; i<=n-l+1; i++){
			int j=i+l-1;
			q=INF;
			for(int k=i; k<j; k++){
				q=min(dp[i][k]+dp[k+1][j]+p[i-1]*p[j]*p[k],q);
				if(q==dp[i][k]+dp[k+1][j]+p[i-1]*p[j]*p[k])s[i][j]=k;
			}
			dp[i][j]=q;
		}
	}
	cout<<dp[1][n]<<endl;
	// for inserting braces....
	insert_braces(1,n);
}

/* efficient matrix chain multiplication.. minimum cost or calculations needed to solve the chain
#define N 100
lld dp[N][N];
int main()
{
	FIO
	lld n,length,q;
	cin>>n;
	lld p[n+1];
	rep(i,0,n+1)cin>>p[i];
	length=n;
	for(int l=2; l<=n; l++){
		for(int i=1; i<=n-l+1; i++){
			int j=i+l-1;
			q=INF;
			for(int k=i; k<j; k++){
				q=min(dp[i][k]+dp[k+1][j]+p[i-1]*p[j]*p[k],q);
			}
			dp[i][j]=q;
		}
	}
	cout<<dp[1][n]<<endl;
}
*/


/*  cutting the rod problem....
lld dp[MAX];
int main()
{
	FIO
	lld n,q;
	cin>>n;
	lld p[n+1];
	dp[0]=0;
	rep(i,1,n+1){
		cin>>p[i];
	}	
	rep(i,1,n+1){
		q=-INF;
		rep(j,1,i+1){
			q=max(q,p[j]+dp[i-j]);
		}
		dp[i]=q;
	}
	rep(i,1,n+1)
	cout<<dp[i]<<endl;
}
*/


/* represent a number in the form of 1 3 and 4 (i mean sum) eg `1 1 3, 1 3 1 are counted as different...for n=5;
lld dp[MAX];
int main()
{
	lld n;
	cin>>n;
	dp[0]=dp[1]=dp[2]=1;
	dp[3]=2;
	rep(i,4,11){
		dp[i]=dp[i-1]+dp[i-3]+dp[i-4];
	}
	cout<<dp[n]<<endl;
}*/


/*
dp example coins... minimum number of coins sum up to given value;;
lld dp[MX];
int main()
{
	lld n,s,mn;
	cin>>n>>s;
	lld a[n];
	rep(i,0,n)cin>>a[i];
	dp[0]=0;
	rep(i,1,MX)
	{
		mn=INF;
		rep(j,0,n)
		{
			if(a[j]<=i)
			mn=min(mn,dp[i-a[j]]+1);
		}
		dp[i]=mn;
	}
}
*/

/* dp problem of longest increasing subsequence....
lld dp[MX];
int main()
{
	lld n,innermost=1,inner=0;
	cin>>n;
	lld a[n];
	rep(i,0,n)cin>>a[i];
	
	rep(i,0,n)
	{
		rep(j,0,i)
		{
			if(a[j]<=a[i])
			innermost=max(innermost,dp[j]+1);
		}
		inner=max(inner,innermost);
		dp[i]=inner;
		innermost=1;
	}
	cout<<inner<<endl;
}
*/
