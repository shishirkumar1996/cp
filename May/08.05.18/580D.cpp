#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define NUM 100

using namespace std;

lld rule[NUM][NUM];
int n,m,k;
vi sat;

lld dp(int fill,vi taken,lld val,lld last){

  if(fill == m)
    return val;
  lld maxm = val;
  
//  if(fill==3)
//    cout<<val<<" "<<last<<" "<<fill<<endl;
  
  for(int i = 1;i<=n;i++){
    int flag = 1;
    for(int j = 0;j<taken.size();j++)if(taken[j] == i) flag = 0;
      if(!flag)
        continue;
      vi new_taken = taken;
      new_taken.push_back(i);

      maxm = max(maxm,dp(fill+1,new_taken,val+sat[i]+rule[last][i],i));
      
  }
  return maxm;
}

int main(){

  cin>>n>>m>>k;
  
  for(int i = 0;i<NUM;i++)
    for(int j =0;j<NUM;j++) rule[i][j] =  0;
    
  sat.resize(n+1);
  for(int i = 1;i<=n;i++) cin>>sat[i];
  
  for(int i = 0;i<k;i++){
    int a,b;
    lld c;
    cin>>a>>b>>c;
    rule[a][b] = c;
  }
  
  vi process;
  cout<<dp(0,process,0,0)<<endl;
}
