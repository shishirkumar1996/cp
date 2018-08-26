#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int t;
  cin>>t;
  int cs = 1;
  for(int l=1;l<=t;l++){
    int k,n;
    cin>>n>>k;
    vi input(n);
    for(int i=0;i<n;i++){ cin>>input[i];input[i] += 1; }
    sort(input.begin(),input.end());
    int ans = 0;
    int day =1,index = 0;
    while(index < n){
      int minm = 0;
      while(day>=input[index] && index<n) index++;
      
      while(minm < k && index < n && day< input[index]){
        minm++;index++;
      }
      ans += minm;
      day++;
    }
    cout<<"Case #"<<cs<<": "<<ans<<endl;
    cs++;
  }
  return 0;
}
