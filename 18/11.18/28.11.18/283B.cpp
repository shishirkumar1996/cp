#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define NUM 200007
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

lld ans[NUM][2];
int visited[NUM][2];
int n;
lld a[NUM];

lld dp(lld v,int x){
  if(v<=0 || v>n) return 0;
  if(visited[v][x] == 1|| ans[v][x] == -1){ return ans[v][x] = -1; }
  if(visited[v][x])return ans[v][x];
  lld sum = a[v];
  lld val;
  visited[v][x]= 1;
  if(x==0) val = dp(v-a[v],x^1);
  else val = dp(v+a[v],x^1);
  visited[v][x] = 2;
  if(val==-1)return ans[v][x] = -1;
  else return ans[v][x] = sum+val;
}


int main(){
  cin>>n;
  for(int i=2;i<=n;i++)cin>>a[i];
  for(int i=0;i<NUM;i++)ans[i][0] = ans[i][1] = visited[i][0] = visited[i][1] = 0;
  ans[1][0] = ans[1][1] = -1;
  for(int i=2;i<=n;i++)for(int j=0;j<2;j++){ if(!visited[i][j]) dp(i,j); }
//  for(int i=2;i<=n;i++)cout<<ans[i][0]<<" "<<ans[i][1]<<'\n';
  
  for(lld i=2;i<=n;i++) {
    if(ans[i][0]==-1)cout<<-1<<'\n';
    else cout<<(i-1)+ans[i][0]<<'\n';
  }

}
