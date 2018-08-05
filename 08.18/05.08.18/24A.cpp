#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define ppr pair< pr,int >
#define vppr vector< ppr >
#define vvppr vector< vppr >

using namespace std;

int main(){
  int n;
  cin>>n;
  
  vvppr input(n+1);
  for(int i=1;i<=n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    input[a].push_back(make_pair(make_pair(b,c),1));
    input[b].push_back(make_pair(make_pair(a,c),0));
  }
  
  int ans = INT_MAX;
  
  for(int i=0;i<2;i++){
    int x = input[1][i].first.first;
    int temp = 0,last = 1;
    if(!input[1][i].second) temp = input[1][i].first.second;
    while(x != 1){
      for(int j=0;j<2;j++){
        if(input[x][j].first.first==last)continue;
        if(!input[x][j].second) temp += input[x][j].first.second;
        last= x;x = input[x][j].first.first;
        break;
      }
    }
    ans = min(ans,temp);
  }
  cout<<ans<<endl;
}
