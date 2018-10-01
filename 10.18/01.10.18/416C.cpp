#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int, int >
#define vp vector< pr >
#define vi vector< int >

using namespace std;


int main(){

  faster
  int n;
  cin>>n;
  vp input(n);
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second;
  
  int k;
  cin>>k;
  vp table(k);
  for(int i = 0;i<k;i++){
    cin>>table[i].first;
    table[i].second = i;
  }
  sort(table.begin(),table.end());
  vp ans;
  int sum = 0;
  int taken[n];
  for(int i = 0;i<n;i++) taken[i]= 0;
  
  for(int i = 0;i<k;i++){
    int maxm = 0,max_index = -1;
    for(int j = 0;j<n;j++){
      if(!taken[j] && input[j].first<=table[i].first && maxm<input[j].second)
        maxm = input[j].second,max_index = j;
    }
    if(max_index != -1){ 
      ans.push_back(make_pair(max_index+1,table[i].second+1));
      taken[max_index] = 1;
      sum+= maxm;
    }
  }
  cout<<ans.size()<<" "<<sum<<endl;
  for(int i= 0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
