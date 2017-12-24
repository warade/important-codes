// Inspired from : https://raw.githubusercontent.com/hellman/libnum/master/libnum/modular.py
//
#include<bits/stdc++.h>
#define rep(i,start,lim) for(lld i=start;i<lim;i++)
#define repd(i,start,lim) for(lld i=start;i>=lim;i--)
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld ",x)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define br printf("\n")
#define sz(a) lld((a).size())
#define YES printf("YES\n")
#define NO printf("NO\n")
#define all(c) (c).begin(),(c).end()
using namespace std;
#define INF         1011111111
#define LLINF       1000111000111000111LL
#define EPS         (double)1e-10
#define MOD         1000000007
#define PI          3.14159265358979323
using namespace std;
typedef long double ldb;
typedef long long lld;
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
typedef vector<lld> vlld;
typedef pair<lld,lld> plld;
typedef map<lld,lld> mlld;
typedef set<lld> slld;
#define N 1000005
lld maxp[N];
#define MM 998244353
lld extended_euclid(lld a,lld b,lld &x,lld &y) {  
	lld xx = y = 0;
	lld yy = x = 1;
	while (b) {
	int q = a/b;
	int t = b; b = a%b; a = t;
	t = xx; xx = x-q*xx; x = t;
	t = yy; yy = y-q*yy; y = t;
	}
	return a;
}
lld mod(lld a,lld b) {
	return ((a%b)+b)%b;
}
lld inversemod(lld a,lld n) {
	lld x, y;
	lld d = extended_euclid(a, n, x, y);
	if(d > 1) return -1LL;
	return mod(x,n);
}
plld chinese_remainder_theorem(lld x,lld a,lld y,lld b) {
  lld s, t;
  lld d = extended_euclid(x, y, s, t);
  if(a%d != b%d) return make_pair(0LL, -1LL);
  return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}
plld chinese_remainder_theorem(const vlld &x, const vlld &a) { // x are the modules and a are remainders
	plld ret = make_pair(a[0], x[0]);
	lld tmp=x.size();
	rep(i,0,tmp) {
		ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
		if (ret.second == -1) break;
	}
	return ret;
}
lld countFact(lld n,lld p)
{
    lld k=0;
    while(n>=p) k+=n/p,n/=p;
    return k;
}
lld factorial_mod(lld n,lld m)
{
    lld res=1; 
    while(n>0)
    {
        for(lld i=2, m=n%MOD; i<=m; i++)
            res=(res*i) % MOD;
        if ((n/=MOD)%2 > 0) 
            res = MOD - res;
    }
    return res;
}
lld nCk_get_prime_pow(lld n,lld k,lld p) {
	lld res=countFact(n,p)-countFact(k,p)-countFact(n-k,p);
	return res;
}
lld nCk_get_non_prime_part(lld n,lld k,lld p,lld e) {
	lld pe=powm(p,e,LLINF);
	lld r=n-k,acc=1;
	vlld fact_pe;
	fact_pe.pb(1LL);
	rep(x,1,pe) {
		if(x%p == 0) fact_pe.pb(acc);
		else acc=(acc*x)%pe,fact_pe.pb(acc);
		//if(p==2) cout<<x<<" "<<acc<<" "<<endl;
	}
	//if(p==2) for(auto i:fact_pe) cout<<i<<" ";br;	
	lld top=1,bottom=1,is_neg=0,digits=0;
	while(n!=0) {
		if(acc!=1) {
			if(digits>=e) {
				is_neg ^= (n&1);
				is_neg ^= (r&1);
				is_neg ^= (k&1);
			}
		}
		top=(top*fact_pe[n%pe])%pe;
		bottom=(bottom*fact_pe[r%pe])%pe;
		bottom=(bottom*fact_pe[k%pe])%pe;
		n/=p,r/=p,k/=p;
		digits+=1;
	}
	lld res=(top*inversemod(bottom,pe))%pe;
	if(p!=2 or e<3) 
		if(is_neg) res=pe-res;
		
	return res;
}
lld nCk_mod_prime_power(lld n,lld k,lld p,lld e) {
	lld prime_part_pow = nCk_get_prime_pow(n,k,p);
	if(prime_part_pow >=e) return 0;
	//cout<<"Prime_part_pow: "<<n<<" "<<k<<" "<<p<<" "<<e<<" "<<prime_part_pow<<endl;
	lld modpow = e - prime_part_pow,tmp=nCk_get_non_prime_part(n,k,p,modpow);
	lld r = tmp % (powm(p,modpow,LLINF));
	//cout<<r<<" "<<tmp<<" "<<p<<" "<<modpow<<endl;
	return (powm(p,prime_part_pow,LLINF) * r)%(powm(p,e,LLINF));
}
lld nCk_mod(lld n,lld k,lld m) {
	if(n<k) return 0LL;
	if(k==0 or k==n) return 1LL;
	if(k==1) return n;
	vlld rems,mods;
	lld curr=0;
	while(1) {
		lld tmp=maxp[m];
		while(m%tmp == 0) curr++,m/=tmp;
		lld tmp2=nCk_mod_prime_power(n,k,tmp,curr);
		//cout<<tmp<<" "<<curr<<" "<<tmp2<<endl;
		rems.pb(tmp2);
		mods.pb(powm(tmp,curr,LLINF));
		curr=0;
		if(tmp==1 or m==1) break;
	}
	return chinese_remainder_theorem(mods,rems).f;
} 
int main() {
	lld a, b, c;
	cin >> a >> b >> c;
	lld one = 0, two = 0, three = 0;
	rep(i, 0, min(a, b) + 1) {
		one = (one + (nCk_mod(a,i,MM)%MM * nCk_mod(b,i,MM)%MM * factorial_mod(i, MM)%MM)%MM)%MM;
	}
	rep(i, 0, min(a, c) + 1) {
		two = (two + (nCk_mod(a,i,MM)%MM * nCk_mod(c,i,MM)%MM * factorial_mod(i, MM)%MM)%MM)%MM;
	}
	rep(i, 0, min(b, c) + 1) {
		three = (three + (nCk_mod(b,i,MM)%MM * nCk_mod(c,i,MM)%MM * factorial_mod(i, MM)%MM)%MM)%MM;
	}
	cout << (((one*two)%MM)*three)%MM << endl;
}
 
