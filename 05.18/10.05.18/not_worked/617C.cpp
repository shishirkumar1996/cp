#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld  long long int
#define pr pair< lld , lld >
#define vp vector< pr >

using namespace std;
int main(){

  faster
  int n;
  cin>>n;
  vp input(n);
  pr one,two;
  cin>>one.first>>one.second>>two.first>>two.second;
  
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second;
  
  lld r1 = 0,r2 = 0;
  for(int i = 0;i<input.size();i++){
    lld dist1 = pow((input[i].first-one.first),2)+pow((input[i].second-one.second),2);
    lld dist2 = pow((input[i].first-two.first),2)+pow(input[i].second-two.second,2);
    if(dist1 <= r1||dist2<=r2){
      cout<<dist1<<" "<<r1<<" "<<dist2<<" "<<r2<<endl;
      continue;
    }
    if(dist1 <= dist2)
      r1= dist1;
    else
      r2 = dist2;
      
  }
  cout<<r1+r2<<endl;

}
