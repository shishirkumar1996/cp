#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define  vi vector< lld >
#define MAXM (lld)(1e9+7)

using namespace std;

int main(){
  faster
  int n;
  cin>>n;
  vi input(n);
  for(int i= 0;i<n;i++)cin>>input[i]; 
  sort(input.begin(),input.end());
  
  vi ans;
  for(int i =0 ;i<n;i++){
    for(int j = 0;j<50 && pow(2,j)+input[i]<=MAXM && ans.size()<3;j++){
      int index = lower_bound(input.begin(),input.end(),input[i]+pow(2,j))-input.begin();
      if(index<n && input[index] == input[i]+pow(2,j)){
        ans.clear();
        ans.push_back(input[i]);ans.push_back(input[index]);
        lld dist = (lld)(pow(2,j));
          int index2 = lower_bound(input.begin(),input.end(),input[index]+dist)-input.begin();
          if(index2<n && input[index2]==input[index]+dist)
            ans.push_back(input[index2]);
      }
    }
  }
  if(!ans.size()) ans.push_back(input[0]);
  cout<<ans.size()<<endl;
  for(int i =0;i<ans.size();i++) cout<<ans[i]<<" ";
  cout<<endl;
}
