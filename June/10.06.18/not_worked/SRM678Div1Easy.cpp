#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;


class ANewHope{
  
  public:
    int count(vi firstWeek,vi lastWeek,int D){
      
      faster      
      int ans = INT_MIN;
      int n= firstWeek.size();
      for(int i = firstWeek.size()-1;i>=0;i--)
        for(int j= 0;j<=i;j++){
          if(firstWeek[i] == lastWeek[j]){
//            cout<<i<<" "<<j<<" "<<change<<endl;
            ans = max(ans,(int)(1+ceil(1.0*(i-j)/(n-D))));
//            cout<<ans<<endl;
            break;
          } 
        }
      return ans;
    }
};

int main(){
  int size = 8;
  int a[] = {8,5,4,1,7,6,3,2};
  int b[] = {2,4,6,8,1,3,5,7};

  ANewHope x;
  vi firstWeek(a,a+size),lastWeek(b,b+size);
  cout<<x.count(firstWeek,lastWeek,3)<<endl;
}
