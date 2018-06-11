#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

class DoubleOrOneEasy{
  
  int minimalSteps(int a,int b,int newA,int newB){
    if(a>b)swap(a,b),swap(newA,newB);
    
    if(a>newA || b>newB || (newA-a > newB -b) || (a==newA && b<newB) || (newA-a >0 && newB- b > 0 && log2(newB*1.0/b) > log2(newA*1.0/a))) return -1;
    
    int ans= 0;
    while(a< newA && b<newB){
      if(2*a<newA && 2*b <newB && (newB-2*b)>=(newA-2*a)) a = 2*a,b=2*b;
      else a++,b++;
      ans++;
    }
    cout<<ans<<endl;
  }
};

int main(){
  
  DoubleOrOneEasy

}
