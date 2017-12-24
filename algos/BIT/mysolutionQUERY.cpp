#include<bits/stdc++.h>
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
 
using namespace std;
 
struct node{
    int v;
    int i;
    int j;
    int q;
};
 
typedef node node;
 
int tree[30001];
node inp[230000];
int n;
int maxVal;
 
bool operator <( node a, node b ) {
    if ( a.v == b.v ) {
        return a.j > b.j;
    }
    return a.v > b.v;
}
 
 
 
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int main()
{
    int m;
    scanf("%d", &n);
    maxVal = n;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &inp[i].v);
        inp[i].i = i + 1;
        inp[i].j = -1;
        tree[i] = 0;
    }
    scanf("%d", &m);
    int res[m];
 
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d", &inp[i + n].i , &inp[i + n].j, &inp[i + n].v);
        inp[i + n].q = i;
    }
 
    sort( inp, inp + n + m );
    for(int i = 0 ; i < n + m ; i++){
        if(inp[i].j == -1){
            update(inp[i].i, 1);
        }else{
            int result = read(inp[i].j) - read(inp[i].i - 1);
            res[inp[i].q] = result;
        }
    }
 
    for(int i = 0 ; i < m ; i++)
        printf("%d\n", res[i]);
    return 0;
} 
