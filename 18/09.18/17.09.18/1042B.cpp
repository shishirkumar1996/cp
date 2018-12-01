#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,string >
#define vp vector< pr >
#define MAXM (lld)(1e9+7)

using namespace std;

int main(){

  int n;
  cin>>n;
  
  vp input(n);
  
  for(int i=0;i<n;i++)cin>>input[i].first>>input[i].second;
  
  lld minm[8];
  int val[3];
  val[0] = 1;val[1] = 2;val[2] = 4;
  minm[0] = 0;
  for(int i=1;i<8;i++) minm[i] = MAXM;

  for(int j=0;j<n;j++){
      int temp = 0;
      for(int k=0;k<input[j].second.size();k++)
        temp += val[input[j].second[k]-'A'];   
      minm[temp] = min(minm[temp],input[j].first);
  }

  for(int i=1;i<=7;i++)
    for(int k=1;k<=7;k++)
      for(int j=1;j<=7;j++){
        if((k|j)==i) minm[i] = min(minm[i],minm[k]+minm[j]);
      }
    
  if(minm[7]==MAXM)cout<<-1<<endl;
  else cout<<minm[7]<<endl;
}
