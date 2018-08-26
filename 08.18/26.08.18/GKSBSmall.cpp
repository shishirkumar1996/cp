#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int t;
  cin>>t;
  int cs = 1;
  while(t--){
    int n,m,p;
    cin>>n>>m>>p;
    vector< string > input(n);
    for(int i=0;i<n;i++)cin>>input[i];
    
    vector< string > forbidden(m);
    for(int i=0;i<m;i++) cin>>forbidden[i];
    int ans = INT_MAX;
    for(int i=0;i<(1<<p);i++){
      string x = "";
      for(int j=0;j<p;j++)if( (i & (1<<j))) x += "1"; else x += "0";
      
      int flag = 1;
      for(int j=0;j<m;j++) if(x==forbidden[j])flag = 0;
      if(!flag)continue;
      int temp = 0;      
      for(int j=0;j<p;j++)
        for(int k=0;k<n;k++)
          if(x[j] != input[k][j])temp++;
      ans = min(ans,temp); 
    }
    cout<<"Case #"<<cs<<": "<<ans<<endl;
    cs++;
  }
}
