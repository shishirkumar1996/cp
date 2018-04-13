#include<bits/stdc++.h>
#define lld long long int
#define pr pair < lld,lld >
#define vp vector< pr >


using namespace std;


lld calc(lld n,lld m,vp input){
  
  lld maxm = 0;
  lld current = input[0].second;
  
  lld initial_days_diff = input[0].first - 1;
  maxm = max(maxm,input[0].second+initial_days_diff);
  
  for(int i = 0;i<m-1;i++){
    maxm = max(maxm,input[i].second);
    lld diff = input[i+1].second - input[i].second;
    lld days = input[i+1].first - input[i].first;
    if(abs(days) < abs(diff))
      return -1;  
    
    lld mid = input[i].second+(days+diff)/2;
    maxm = max(maxm,mid);
  }
  lld days_diff = n - input[m-1].first;
  maxm  = max(maxm, input[m-1].second+days_diff);
  
  return maxm;

}

int main(){

  ios::sync_with_stdio(false);
  lld n,m;
  cin>>n>>m;
  vp input;
  for(int i= 0;i<m;i++){
    lld a,b;
    cin>>a>>b;
    input.push_back(make_pair(a,b));
  }
  
  lld result = calc(n,m,input);
  if(result==-1)
    cout<<"IMPOSSIBLE"<<endl;
  else
    cout<<result<<endl;

}
