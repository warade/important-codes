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
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define pb push_back
#define _mp make_pair
#define f first
#define sz(a) a.size()
#define s second
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
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
#define pc putchar
using namespace std;
typedef long double ldb;
typedef long long lld;
typedef unsigned long long ulld;
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
inline bool ispalin(string s) { for(int i=0,j=s.size()-1;i<=j;i++,j--) if(s[i]!=s[j]) return false; return true; }
inline lld lcm(lld a,lld b){ return (a/__gcd(a, b))*b; }
void fastscan(lld &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
void printint(lld a){
	char s[21];
	int t = -1;
	do{
		s[++t] = a % 10 + '0';
		a /= 10;
	}while(a > 0);
	while(t >= 0)pc(s[t--]);
	pc('\n');
}
///******Lets start coding :-) *******//
/*
struct DSU{
	lld p[MAX];
	void init(lld n = MAX){
		rep(i,1,n+1) p[i]=i;
	}
	int find(lld x){
		if(p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	void join(lld x, lld y){
		x = find(x);
		y = find(y);
		if(x == y)return;
		if(y < x) swap(x, y); // for root to be the minimum number in the set;
		p[y] = x;
	}
}dsu;
*/
struct Trie{
	struct Trie *next[2];
	lld cnt;
};
struct Trie *getNode(){
	struct Trie *temp = new Trie;
	temp -> next[0] = NULL;
	temp -> next[1] = NULL;
	temp -> cnt = 0;
	return temp;
}
void insert(struct Trie *curr, lld value){
	repd(i, 31, 0){
		lld bit = (value & (1<<i)) >> i;
		if(curr->next[bit] == NULL){
			curr->next[bit] = getNode();
		}
		curr  = curr->next[bit];
		curr -> cnt++;
	}
}

void erase(struct Trie *curr, lld value){
	repd(i, 31, 0){
		lld bit = (value & (1<<i)) >> i;
		curr = curr->next[bit];
		curr -> cnt--;
	}
}

lld query(struct Trie *curr, lld value){
	lld ans = 0;
	repd(i, 31, 0){
		lld bit = (value & (1<<i)) >> i;
		lld opp = !bit;
		if(curr->next[opp] != NULL and curr->next[opp]->cnt>0){
			ans += (1<<i);
			curr = curr->next[opp];
		}
		else curr = curr->next[bit];
	}
	return ans;
}
int main()
{
	FIO
	lld q;
	cin >> q;
	struct Trie *root = getNode();
	insert(root, 0);
	while(q--){
		char c;
		lld x;
		cin >> c >> x;
		if(c == '+') insert(root, x);
		if(c == '-') erase(root, x);
		if(c == '?') cout << query(root, x) << endl;
	}
	
}