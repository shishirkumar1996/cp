#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define NUM 100

using namespace std;

lld rule[NUM][NUM];
int n,m,k;
vi sat;
lld sol[20][1<<20];


lld dp(int fill,int last,lld mask){

  if(fill == m) return 0;
  
  lld val = sol[last][mask];
  if(val != -1) return val;  

  for(int i = 1;i<=n;i++){
      if(mask&(1<<i)) continue;
      val = max(val,dp(fill+1,i,mask|(1<<i))+rule[last][i]+sat[i]);
  }
  return sol[last][mask] = val;
}

int main(){

  faster
  cin>>n>>m>>k;
  memset(sol,-1,sizeof(sol));
  memset(rule,0,sizeof(rule));  
    
  sat.resize(n+1);
  for(int i = 1;i<=n;i++) cin>>sat[i];
  
  for(int i = 0;i<k;i++){
    int a,b;
    lld c;
    cin>>a>>b>>c;
    rule[a][b] = c;
  }
  
  cout<<dp(0,0,0)<<endl;
}
