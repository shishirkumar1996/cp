#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vi input(n);
  for(int i =0;i<n;i++) cin>>input[i];
  
  vi ans;
  for(int i =0;i<n;i++){
    int index = upper_bound(ans.begin(),ans.end(),input[i])-ans.begin();
    if(index==ans.size()) ans.push_back(input[i]);
    else ans[index]= input[i];
  }
  cout<<ans.size()<<endl;

}
