#include<bits/stdc++.h>
using namespace std;
#define scan(oo) scanf("%d",&oo)
#define br printf("\n")
#define print(oo) printf("%d",oo);
#define space printf(" ")
int dp[20][180][2];
void ___getdigits(vector<int> &v,int num){
	while(num!=0){
		v.push_back(num%10);
		num/=10;
	}
}
int solve(int x,vector<int> v){
	int tight=1;
	int sum=0;
	for(int i=v.size()-1; i>=0; i--){
		for(int k=0; k<=v[i]; k++){
			int tight = (v[i]==k)? 1 : 0;
			int upto = (tight)? v[i] : 9;
			for(int j=0; j<=upto; j++){
				
			}
		}
	}
}


int main(){
	int a,b;
	scan(a);scan(b);
	memset(dp,-1,sizeof dp);
	vector<int> digits_a,digits_b;
	___getdigits(digits_a,a);
	___getdigits(digits_b,b);
	print(solve(b,digits_b)-solve(a-1,digits_a));
}
