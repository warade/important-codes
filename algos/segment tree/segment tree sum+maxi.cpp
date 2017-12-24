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
			//  Indian Institute Of Information Technology and Management,Gwalior.  //                                                   												
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define T() int t; cin>>t; while(t--)                      
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define rep1(i,start,lim) for(long long i=start;i<=lim;i++)
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
int a[MAX];
struct node
{
	int sum,maxi;
}tree[LIMIT];
int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].sum=a[start];
		tree[node].maxi=a[start];
	}
	else
	{
		int mid=(start+end)/2;
		build(2*node+1,start,mid);
		build(2*node+2,mid+1,end);
		tree[node].sum=tree[node*2+1].sum+tree[2*node+2].sum;
		tree[node].maxi=max(tree[2*node+1].maxi,tree[2*node+2].maxi);
	}
}
void update(int node,int start,int end,int index,int val)
{
	if(start==end)
	{
		a[index]=val;
		tree[node].maxi=val;
		tree[node].sum=val;
	}
	else
	{
		int mid=(start+end)/2;
		if(index>=start && index<=end)
		update(2*node+1,start,mid,index,val);
		else
		update(2*node+2,mid+1,end,index,val);
		tree[node].sum=tree[node*2+1].sum+tree[2*node+2].sum;
		tree[node].maxi=max(tree[2*node+1].maxi,tree[2*node+2].maxi);
	}
}
int sum_query(int node,int start,int end,int l,int r)
{
	if(l>end||r<start)
	return 0;
	if(l<=start && r>=end)
	return tree[node].sum;
	int mid=(start+end)/2;
	int p1=sum_query(2*node+1,start,mid,l,r);
	int p2=sum_query(2*node+2,mid+1,end,l,r);
	return p1+p2;
}
int maxi_query(int node,int start,int end,int l,int r)
{
	if(l>end||r<start)
	return 0;
	if(l>=start && r<=end)
	return tree[node].maxi;
	int mid=(start+end)/2;
	int p1=sum_query(2*node+1,start,mid,l,r);
	int p2=sum_query(2*node+2,mid+1,end,l,r);
	return max(p1,p2);
}
int main()
{
	FIO
	int n;
	cin>>n;
	rep(i,0,n)
	cin>>a[i];
	/*build time*/build(0,0,n-1);
	rep(i,0,2*n-1)cout<<tree[i].sum<<" ";
	cout<<endl;
	cout<<sum_query(0,0,n-1,0,1)<<" ";
	cout<<sum_query(0,0,n-1,1,1)<<" ";
	cout<<sum_query(0,0,n-1,2,2)<<" ";
	cout<<sum_query(0,0,n-1,3,3);
	/*
	rep(i,0,2*n-1)cout<<tree[i].maxi<<" ";
	cout<<endl;
	update(0,0,n-1,3,100);
	rep(i,0,2*n-1)cout<<tree[i].sum<<" ";
	cout<<endl;
	rep(i,0,2*n-1)cout<<tree[i].maxi<<" ";
	cout<<endl;
	cout<<sum_query(0,0,n-1,0,n-1)<<endl;
	cout<<maxi_query(0,0,n-1,0,n-1)<<endl;*/
	return 0;
}

