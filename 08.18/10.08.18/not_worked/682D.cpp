#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int process[1007][1007][12];
bool last[1007][1007][12];

int main(){
  
  faster
  int n,m,t;
  string a,b;
  cin>>n>>m>>t>>a>>b;
  a = " "+a;b = " "+b;
  for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=t;k++)
    process[i][j][k] = 0,last[i][j][k] = false;
    
  for(int k=1;k<=t;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        process[i][j][k]=max(process[i-1][j-1][k],process[i][j][k]);
        if(a[i]==b[j]){
          last[i][j][k] = true;
          process[i][j][k] = max(process[i][j][k],process[i-1][j-1][k-1]+1);
          if(a[i-1]==b[j-1] && last[i-1][j-1][k])
            process[i][j][k] = max(process[i][j][k],process[i-1][j-1][k]+1);
        }
        if(process[i][j-1][k]>process[i][j][k] || process[i-1][j][k]>process[i][j][k]|| process[i-1][j-1][k]>process[i][j][k])last[i][j][k] = false;
        process[i][j][k] = max(process[i][j][k],max(process[i-1][j-1][k-1],max(process[i][j-1][k],process[i-1][j][k])));
        cout<<i<<" "<<j<<" "<<last[i][j][k]<<" "<<process[i][j][k]<<endl;
      }
    }
  }
  cout<<process[n][m][t]<<endl;
}
