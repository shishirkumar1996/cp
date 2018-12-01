#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define ppr  pair< pr,lld >
#define vppr vector< ppr >

using namespace std;

bool prime(lld n){
  if(n==1) return false;
  for(int i = 2;i<=pow(n,0.5);i++) if(n%i==0)return false;
  return true;
}



int main(){

  int n,m;
  cin>>n>>m;
  
  lld dist[n+1];
  
  vppr ans;
  for(int i =1;i<=n;i++) dist[i] = 0;
  
  for(int i=  2;i<=n;i++){ 
    ans.push_back(make_pair(make_pair(i-1,i),1));
    dist[i] = dist[i-1]+1;
  } 
  
  int x= ans.size();
  while(true){
    if(prime(dist[n])) break;
    ans[x-1].second++;dist[n]++;
  }
  
  m = m-x;
  int index = 1,second_ind = 2;
  while(m>0){
    if(second_ind==n) index++,second_ind = index+2;
    else  second_ind++;
    ans.push_back(make_pair(make_pair(index,second_ind),dist[second_ind]+1)); 
    m--;
  }
  cout<<dist[n]<<" "<<dist[n]<<endl;
  for(int i = 0;i<ans.size();i++)
    cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;

}
