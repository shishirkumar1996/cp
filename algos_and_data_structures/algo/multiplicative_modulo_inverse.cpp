#include<bits/stdc++.h>


using namespace std;


int gcdExtended(int a,int b,int *x,int *y);

void modInverse(int a,int m){
  
  int x,y;
  int gcd = gcdExtended(a,m,&x,&y);
  if(gcd != 1) cout<<"Inverse doesn't exist"<<endl;
  else {
    int res = (x%m+m)%m;
    cout<<res<<endl;
  }
}

// extended euclidean algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
      *x = 0, *y = 1;
      return b;
    }
 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int main(){

  int a,m;
  cin>>a>>m;
  modInverse(a,m);
}
