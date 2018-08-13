#include<bits/stdc++.h>
#define lld long long  int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){
  
  faster
  string a,b;
  cin>>a>>b;
  
  vii pos(26);
  for(int i=0;i<a.length();i++) pos[a[i]-'a'].push_back(i);
  
  int ans = 1;
  int index = 0;
  for(int i=0;i<b.length();i++){
    int ch = b[i]-'a';
    if(pos[ch].size()==0){cout<<-1<<endl;return 0;}
    
    int x = lower_bound(pos[ch].begin(),pos[ch].end(),index)-pos[ch].begin();
    int y;
    if(x==pos[ch].size()){
      index = 0;
      ans++;
      x = lower_bound(pos[ch].begin(),pos[ch].end(),index)-pos[ch].begin();
    }
    y = pos[ch][x];
    index = y+1;
  }
  cout<<ans<<endl;
}
