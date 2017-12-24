
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
#define T() int t; scanf("%d",&t); while(t--)                      
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
#define MAX 1000001
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

lld tree[4*MAX],lazy[4*MAX];
void updateRange(lld node, lld start, lld end, lld l, lld r, lld val)
{
    if(lazy[node] != 0){
        tree[node] += 1LL*(end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r){
        tree[node] += 1LL*(end - start + 1) * val;
        if(start != end){
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    lld mid = (start + end) / 2;
    updateRange(node*2+1, start, mid, l, r, val);
    updateRange(node*2 + 2, mid + 1, end, l, r, val);
    tree[node] = tree[node*2+1] + tree[node*2+2];
}

lld query(lld node, lld start, lld end, lld l, lld r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0){
        tree[node] += 1LL*(end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    lld mid = (start + end) / 2;
    lld p1 = query(node*2+1, start, mid, l, r);
    lld p2 = query(node*2 + 2, mid + 1, end, l, r); 
    return (p1 + p2);
}
int main()
{
	lld n,m;
	T(){
		scanf("%lld%lld",&n,&m);
		while(m--){
			lld _case;
			scanf("%lld",&_case);
			if(_case==0){
				lld p,q,v;
				scanf("%lld%lld%lld",&p,&q,&v);
				p--,q--;
				updateRange(0,0,n-1,p,q,v);
			}
			else{
				lld p,q;
				scanf("%lld%lld",&p,&q);
				p--,q--;
				lld ans = query(0,0,n-1,p,q);
				printf("%lld\n",ans);
			}
		}
		memset(tree,0,sizeof tree);
		memset(lazy,0,sizeof lazy);
	}
}





