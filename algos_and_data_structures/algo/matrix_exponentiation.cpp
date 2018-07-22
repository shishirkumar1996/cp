#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

int f0,f1,f2,a,b,c;

using namespace std;

void multiply(int a[3][3], int b[3][3]){
  int mul[3][3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      mul[i][j] =0;
      for(int k=0;k<3;k++) mul[i][j] += a[i][k]*b[k][j];
    }
  for(int i=0;i<3;i++)for(int j=0;j<3;j++) a[i][j] = mul[i][j];
}

int power(int F[3][3],int n){
  int M[3][3] = {{a,b,c},{1,0,0},{0,1,0}};
  if(n==1)return f2*F[0][0]+f1*F[0][1]+f0*F[0][2];
  
  power(F,n/2);
  multiply(F,F);
  if(n%2 != 0) multiply(F,M);
  
  return f2*F[0][0]+f1*F[0][1]+f0*F[0][2];
}

int findNthTerm(int n){
  int F[3][3] = {{a,b,c},{1,0,0},{0,1,0}};
  return power(F,n-2);
}

int main(){
  int n=5;
  f0=1,f1=1,f2=1;    //can change
  a = 2,b=1,c=1;     //can change
  cout<<"F(5) "<<findNthTerm(n)<<endl; // n must be greater than 2
}
