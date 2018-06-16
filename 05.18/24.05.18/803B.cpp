#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){
  
  faster
  int n;
  cin>>n;
  vi input(n);
  for(int i = 0;i<n;i++)  cin>>input[i];
  
  vi process,ans(n);
  for(int i =0;i<n;i++) if(!input[i]) process.push_back(i);
  
  for(int i = 0;i<n;i++){
    int index = upper_bound(process.begin(),process.end(),i)-process.begin();
    lld x = n+1;
    if(index > 0) x = min(x,abs(process[index-1]-i));
    if(index < process.size()) x = min(x,abs(process[index]-i));
    ans[i] = x;
  }
  for(int i = 0;i<n;i++)cout<<ans[i]<<" ";
  cout<<endl;

}
