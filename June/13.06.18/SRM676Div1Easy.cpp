#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define faster ios_base:sync_with_stdio(false);cin.tie(0);
#define MINM 1e-9

using namespace std;

class WaterTank{

  int can(double mid,vi t,vi x,int c){
    
    double sum = 0;
    for(int i = 0;i<t.size();i++){
      sum = max(sum+t[i]*(x[i]-mid),0.0);  
      if(sum>c)return 0;
      }
    return 1;
  }

  public:
    double minOutputRate(vi t,vi x,int c){
      double low = 0,high = 1e7;
      while(high-low>=MINM){
        double mid = (high+low)/2;
        
        if(can(mid,t,x,c))high = mid; else low = mid+MINM;
      }
      return low;
    }
};

int main(){

  int c=3,size=2;
  
  int a[] = {3,3};
  int b[] = {1,2};
  
  vi t(a,a+size),x(b,b+size);
  WaterTank w;
  cout<<setprecision(9)<<w.minOutputRate(t,x,c)<<endl;
}
