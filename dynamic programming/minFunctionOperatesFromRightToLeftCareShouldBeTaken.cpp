#include<bits/stdc++.h>
using namespace std;
int func1(int x){
	cout<<"i am func1"<<endl;
	return x;
}
int func2(int x)
{
	cout<<"i am func2"<<endl;
	return x;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<min(func1(a),func2(b));
}
