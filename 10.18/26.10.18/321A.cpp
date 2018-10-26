#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vp vector< pr >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  faster
  lld a,b;
  cin>>a>>b;
  string input;
  cin>>input;
  
  vp process;
  process.push_back(make_pair(0,0));
  lld x=0,y=0;
  for(int i=0;i<input.size();i++){
    if(input[i]=='R')x++;
    else if(input[i]=='L') x--;
    else if(input[i]=='U') y++;
    else if(input[i]=='D') y--;
    process.push_back(make_pair(x,y));
  }
  lld fin_x = process[process.size()-1].first;
  lld fin_y = process[process.size()-1].second;
  
  for(int i=0;i<process.size();i++){
    lld rem_x = a-process[i].first;
    lld rem_y = b-process[i].second;
    
    if(fin_x==0||fin_y==0){
      if(fin_x && !rem_y && rem_x%fin_x==0){ cout<<"Yes\n";return 0;}
      if(fin_y && !rem_x && rem_y%fin_y==0){cout<<"Yes\n";return 0;}
    } else
    if(rem_x/fin_x==rem_y/fin_y && rem_x%fin_x==0 && rem_y%fin_y==0){
      cout<<"Yes\n";return 0;
    }
  }
  cout<<"No\n";
}
