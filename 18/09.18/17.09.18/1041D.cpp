#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e10+7)
#define pr pair< lld,lld >
#define vp vector< pr >


using namespace std;

int main(){

  int n;
  lld h;
  cin>>n>>h;
  
  vi process;
  vp input(n);
  int size = 1;
  process.push_back(0);
  cin>>input[0].first>>input[0].second;
  for(int i=1;i<n;i++){
    cin>>input[i].first>>input[i].second;
    lld dist = (input[i].first-input[i-1].second);
    process.push_back(dist+process[size-1]);
    size++;
  }
  process.push_back(MAXM);
//  for(int i=0;i<process.size();i++)cout<<process[i]<<" "; cout<<endl;
  
  lld ans = 0;
  for(int i=0;i<n;i++){
    int index = lower_bound(process.begin(),process.end(),process[i]+h)-process.begin();
    lld last = input[index-1].second;
    lld x = (last-input[i].first)-(process[index-1]-process[i]);
    ans = max(ans,x+h);
//    cout<<i<<" "<<x<<" "<<last<<" "<<index<<endl;
  }
  cout<<ans<<endl;
}
