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
int solve(int index,int sum,int tight,vector<int> digits){
	//print(index);space;print(sum);space;print(tight);br;
	int uttar = 0;
	if(index==-1) return sum;
	if(dp[index][sum][tight] != -1 and tight != 1) return dp[index][sum][tight];
	int k = (tight)? digits[index]:9;
	for(int i=0; i<=k; i++){
		int newTight = (digits[index] == i)? tight:0;
		uttar += solve(index-1,sum+i,newTight,digits);
	}
	if(!tight){
		dp[index][sum][tight] = uttar;
	}
	return uttar;
}


int main(){
	int a,b;
	scan(a);scan(b);
	memset(dp,-1,sizeof dp);
	vector<int> digits_a,digits_b;
	___getdigits(digits_a,a-1);
	___getdigits(digits_b,b);
	print(solve(digits_b.size()-1,0,1,digits_b)-solve(digits_a.size()-1,0,1,digits_a));
}
