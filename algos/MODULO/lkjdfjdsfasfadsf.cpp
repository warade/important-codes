/*
	This Solution Is developed By Shivam Sinha
	Student ABV-IIITM Gwalior
	IPG-2014082
	Strassens Algorithm
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
	
void split(int **c, int **a, int k, int l,int len){
	int i1,j1,i2,j2;
	for(i1=0,i2=k;i1<len;i1++,i2++){
		for(j1=0,j2=l;j1<len;j1++,j2++){
			c[i1][j1] = a[i2][j2];
		}
	}
}
void join(int **c, int **r ,int k, int l, int len){
	int i1,i2,j1,j2;
	for(i1 = 0, i2 = k; i1 < len; i1++, i2++)
            for(j1 = 0, j2 = l; j1 < len; j1++, j2++)
                r[i2][j2] = c[i1][j1];
}
void add(int **a, int **b, int **c, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
void sub(int **a, int **b, int **c, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}
void multiply(int **a, int **b, int **res, int n){
	//int r[n][n];
	if(n==1){
		//cout<<n<<"\n";
		res[0][0] = a[0][0]*b[0][0];
	}
	else{
		//int a11[n/2][n/2],a12[n/2][n/2],a21[n/2][n/2],a22[n/2][n/2],b11[n/2][n/2],b12[n/2][n/2],b21[n/2][n/2],b22[n/2][n/2];
		int **a11,**a12,**a21,**a22,**b11,**b12,**b21,**b22,**c11,**c12,**c21,**c22;
		a11 = new int *[n/2];
		a12 = new int *[n/2];
		a21 = new int *[n/2];
		a22 = new int *[n/2];

		b11 = new int *[n/2];
		b12 = new int *[n/2];
		b21 = new int *[n/2];
		b22 = new int *[n/2];

		c11 = new int *[n/2];
		c12 = new int *[n/2];
		c21 = new int *[n/2];
		c22 = new int *[n/2];

		int i,j;
		for(i=0;i<n/2;i++){
			a11[i] = new int[n/2];
			a12[i] = new int[n/2];
			a21[i] = new int[n/2];
			a22[i] = new int[n/2];
			b11[i] = new int[n/2];
			b12[i] = new int[n/2];
			b21[i] = new int[n/2];
			b22[i] = new int[n/2];
			c11[i] = new int[n/2];
			c12[i] = new int[n/2];
			c21[i] = new int[n/2];
			c22[i] = new int[n/2];
		}
		split(a11,a,0,0,n/2);
		split(a12,a,0,n/2,n/2);
		split(a21,a,n/2,0,n/2);
		split(a22,a,n/2,n/2,n/2);

		split(b11,b,0,0,n/2);
		split(b12,b,0,n/2,n/2);
		split(b21,b,n/2,0,n/2);
		split(b22,b,n/2,n/2,n/2);
		
		int **p1,**p2,**p3,**p4,**p5,**p6,**p7;
		p1 = new int *[n/2];
		p2 = new int *[n/2];
		p3 = new int *[n/2];
		p4 = new int *[n/2];
		p5 = new int *[n/2];
		p6 = new int *[n/2];
		p7 = new int *[n/2];

		for(i=0;i<n/2;i++){
			p1[i] = new int[n/2];
			p2[i] = new int[n/2];
			p3[i] = new int[n/2];
			p4[i] = new int[n/2];
			p5[i] = new int[n/2];
			p6[i] = new int[n/2];
			p7[i] = new int[n/2];
		}
		int **ar,**br;
		ar = new int *[n/2];
		br = new int *[n/2];
		for(i=0;i<n/2;i++){
			ar[i] = new int[n/2];
			br[i] = new int[n/2];
		}
		/** 
              M1 = (A11 + A22)(B11 + B22)
              M2 = (A21 + A22) B11
              M3 = A11 (B12 - B22)
              M4 = A22 (B21 - B11)
              M5 = (A11 + A12) B22
              M6 = (A21 - A11) (B11 + B12)
              M7 = (A12 - A22) (B21 + B22)
            **/
		add(a11,a22,ar,n/2);
		add(b11,b22,br,n/2);
		multiply(ar,br,p1,n/2);
		//cout<<ar[0][0]<<" "<<br[0][0]<<" "<<p1[0][0]<<"\n";
		add(a21, a22,ar,n/2);
		multiply(ar,b11,p2,n/2);
		//cout<<ar[0][0]<<" "<<b11[0][0]<<" "<<p2[0][0]<<"\n";
		sub(b12,b22,br,n/2);
		multiply(a11,br,p3,n/2);
		//cout<<a11[0][0]<<" "<<br[0][0]<<" "<<p3[0][0]<<"\n";
		sub(b21,b11,br,n/2);
		multiply(a22,br,p4,n/2);
		//cout<<a22[0][0]<<" "<<br[0][0]<<" "<<p4[0][0]<<"\n";
		add(a11,a12,ar,n/2);
		multiply(ar,b22,p5,n/2);
		//cout<<ar[0][0]<<" "<<b22[0][0]<<" "<<p5[0][0]<<"\n";
		sub(a21,a11,ar,n/2);
		add(b11,b12,br,n/2);
		multiply(ar,br,p6,n/2);
		//cout<<ar[0][0]<<" "<<br[0][0]<<" "<<p6[0][0]<<"\n";
		sub(a12,a22,ar,n/2);
		add(b21,b22,br,n/2);
		multiply(ar,br,p7,n/2);
		//cout<<ar[0][0]<<" "<<br[0][0]<<" "<<p7[0][0]<<"\n";
		 /**
              C11 = M1 + M4 - M5 + M7
              C12 = M3 + M5
              C21 = M2 + M4
              C22 = M1 - M2 + M3 + M6
            **/
          int **w,**x,**y,**z;
		  w = new int *[n/2];
		  x = new int *[n/2];
		  y = new int *[n/2];
		  z = new int *[n/2];
		for(i=0;i<n/2;i++){
			w[i] = new int[n/2];
			x[i] = new int[n/2];
			y[i] = new int[n/2];
			z[i] = new int[n/2];
		}
          add(p1,p4,w,n/2);
          sub(p7,p5,x,n/2);
          add(w,x,c11,n/2);
          //cout<<c11[0][0]<<"\n";
          add(p3,p5,c12,n/2);
          //cout<<c12[0][0]<<"\n";
          add(p2,p4,c21,n/2);
         // cout<<c21[0][0]<<"\n";
          sub(p1,p2,y,n/2);
          add(p3,p6,z,n/2);
          add(y,z,c22,n/2);
         // cout<<c22[0][0]<<"\n";
          join(c11, res, 0 , 0,n/2);
          join(c12, res, 0 , n/2,n/2);
          join(c21, res, n/2, 0,n/2);
          join(c22, res, n/2, n/2,n/2);   

	}
}


int main() {
	int **a;
	int **b;
	int **res;
	int size;
	cin>>size;
	//randomize();
	a = new int *[size];
	b = new int *[size];
	res = new int *[size];
	int n =size;
	int i,j;
	for(i=0;i<n;i++){
		a[i] = new int[n];
		b[i] = new int[n];
		res[i] = new int[n];
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			a[i][j] = rand()%100 + size;
		}
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			b[i][j] = rand()%100 + size;
		}
	}
	cout<<"First Matrix \n";
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nSecond Matrix \n";
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
	multiply(a,b,res,size);

	cout<<"\n\nAnswer\n\n";
	cout<<"\nSecond Matrix \n";
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
