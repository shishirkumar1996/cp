#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){
  int k,n;
  cin>>n>>k;
  
  vp input(n);
  for(int i=0;i<n;i++){
    cin>>input[i].first;
    input[i].second = i+1;
  }
  sort(input.begin(),input.end());
  reverse(input.begin(),input.end());
  lld ans = 0;
  
  vi process;
  for(int i=0;i<k;i++){
    process.push_back(input[i].second);
    ans+= input[i].first;
  }
  
  cout<<ans<<endl;
  sort(process.begin(),process.end());
  int ind = 0;
  for(int i=0;i<process.size();i++){
    if(i==k-1) process[i]  = n;
    cout<<process[i]-ind<<" ";
    ind = process[i];
  }
  cout<<endl;
  
}
