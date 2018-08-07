#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

struct item{ int t,d,p,index;};

int compare(item a,item b){
  return a.d<b.d;
}

int main(){
  
  faster
  int n;
  cin>>n;
  
  item input[n+1];
  int maxm = 0;
  for(int i=1;i<=n;i++){
    cin>>input[i].t>>input[i].d>>input[i].p;
    input[i].index = i;
    maxm = max(input[i].d,maxm);
  }
  sort(input+1,input+n+1,compare);
  int saves[n+1][maxm+1];
  int ans[n+1][maxm+1];
  for(int i=0;i<=n;i++)for(int j=0;j<=maxm;j++)ans[i][j] = saves[i][j] = 0;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=maxm;j++){
      ans[i][j] = ans[i-1][j];
      if(j>=input[i].d || j-input[i].t<0)continue;
      if(ans[i][j] < ans[i-1][j-input[i].t]+input[i].p){
        ans[i][j] = ans[i-1][j-input[i].t]+input[i].p;
        saves[i][j] = 1;
      } 
    }
  }

  vi output;
  int y=0,max_index=0;
  for(int i=1;i<=maxm;i++){if(ans[n][i]>y)y=ans[n][i],max_index = i;}
  cout<<ans[n][max_index]<<endl;
  int x=n;
  y=max_index;
  while(x>0){
    if(saves[x][y]){output.push_back(input[x].index);y = y-input[x].t;}
    x--;
  }
  cout<<output.size()<<endl;
  for(int i=output.size()-1;i>=0;i--)cout<<output[i]<<" ";
  cout<<endl;
}
