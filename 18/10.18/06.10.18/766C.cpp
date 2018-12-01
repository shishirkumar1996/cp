#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define vp vector< pr >
#define MAXM (1e10)
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = ";for(int i=0;i<n;i++) cerr<<a[i]<<' ';cerr<<'\n';}
#define TM

using namespace std;

int main(){
  
  faster
  int n;
  string input;
  cin>>n>>input;
  int process[26];
  for(int i=0;i<26;i++)cin>>process[i];
  lld maxm[n+1],min_sub[n+1],num[n+1];
  for(int i=0;i<=n;i++)maxm[i] = num[i] = 0,min_sub[i] = MAXM;
  
  num[0] = 1;
  min_sub[0] = 0;
  int sum[26][n+1];
  for(int i=0;i<26;i++)sum[i][0]= 0;
  for(int i=0;i<input.size();i++)for(int j=0;j<26;j++)
    sum[j][i+1] = sum[j][i]+((input[i]=='a'+j)?1:0);
 
  for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
      int flag = 1;
      for(int k=0;k<26;k++)
//        if(sum[k][i]-sum[k][j]>process[k]){flag =0;break;}      
        if(i-j>process[k] && sum[k][i]-sum[k][j]>0){flag = 0;break;}
      if(!flag)continue;
      num[i] = (num[i]+num[j])%MOD;
      maxm[i] = max(maxm[i],max(maxm[j],(lld)(i-j)));
      min_sub[i] = min(min_sub[i],min_sub[j]+1);
    }  
  }
  cout<<num[n]<<'\n'<<maxm[n]<<'\n'<<min_sub[n]<<'\n'; 
//  trace2(num,n+1);
//  trace2(min_sub,n+1);
  
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
