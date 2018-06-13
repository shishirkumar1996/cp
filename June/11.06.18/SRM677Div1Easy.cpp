#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define MAXM 1e5

using namespace std;

class DoubleOrOneEasy{
  
  public:
    int minimalSteps(int a,int b,int newA,int newB){
      if(a>b)swap(a,b),swap(newA,newB);
      
      if(a<=newA && b<=newB && newB>=newA && a-newA >= b-newB){
        if(b==a && newB>newA) {return -1;}
        if((b==a && newB==newA)||(log2(1.0*(newB-newA)/(b-a)) == (int)(log2(1.0*(newB-newA)/(b-a))))){
          int x;
          if(b==a && newB==newA) x = MAXM;
          else
          x = log2(1.0*(newB-newA)/(b-a));
          
          int ans = 0;
          if(b==a || a*pow(2,x)<=newA){
            while(newA> a)
              if(newA%2==0 && newA/2 >=a  && x>0) x--,ans++,newA = newA/2;
             else 
             ans++,newA = newA-1;
            return ans;
          }
        }
      }
      return -1;
    }
};

int main(){
  
  DoubleOrOneEasy d;
  int a,b,newA,newB;
  cin>>a>>b>>newA>>newB;
  cout<<d.minimalSteps(a,b,newA,newB)<<endl;
}
