#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define NUM 100007

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  
  vii input(m+1);
  for(int i=0;i<n;i++){
    lld a,b;
    cin>>a>>b;
    input[a].push_back(b);
  }
  
  lld ans[NUM];
  lld sol = 0;
  for(int i=0;i<NUM;i++)ans[i] = 0;
  for(int i=1;i<=m;i++){
    sort(input[i].begin(),input[i].end());
    reverse(input[i].begin(),input[i].end());
    if(input[i].size()){
      if(input[i][0]>=0)ans[0] += input[i][0];
      sol = max(sol,ans[0]);
      for(int j=1;j<input[i].size();j++){
        input[i][j] = input[i][j-1]+input[i][j];
        if(input[i][j]>=0)ans[j] += input[i][j];
        sol = max(sol,ans[j]);
      }
    }
  }
  cout<<sol<<'\n';
}
