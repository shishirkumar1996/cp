#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< lld, lld >
#define ppr pair< pr, int >
#define vp vector< ppr >

using namespace std;


int compare(ppr a,ppr b){
  return a.first.first*a.first.second < b.first.first*b.first.second;  

}

int main(){

  faster
  int n,w,h;
  cin>>n>>w>>h;
  
  vp input(n);
  for(int i = 0;i<n;i++){
    cin>>input[i].first.first>>input[i].first.second;
    input[i].second = i+1;
  }
  vp process;
  process.push_back(make_pair(make_pair(w,h),0));
  
  sort(input.begin(),input.end(),compare);
  for(int i = 0;i<n;i++)
    if(input[i].first.first > w && input[i].first.second > h)
      process.push_back(input[i]);
  
  int dp[process.size()];
  memset(dp,0,sizeof(dp));
  
  int parent[process.size()];
  memset(parent,0,sizeof(parent));
  
  for(int i = 1;i<process.size();i++)
    for(int j = 0;j<i;j++)
      if(process[i].first.first > process[j].first.first && process[i].first.second > process[j].first.second)
        if(dp[i] < dp[j]+1){
          dp[i] = dp[j]+1,parent[i] = j;
//          cout<<dp[i]<<" "<<i<<endl;
        }
  
  int maxm = 0,max_index = 0;
  for(int i = 0;i<process.size();i++)
    if(dp[i] > maxm) maxm = dp[i],max_index = i;

  cout<<maxm<<endl;
  vector< int > answer;
  while(max_index > 0){
    answer.push_back(process[max_index].second);
    max_index = parent[max_index];
  }
  for(int i = maxm - 1;i>=0;i--)
    cout<<answer[i]<<" ";
  cout<<endl;
}
