#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e17)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){
  
  int n;
  cin>>n;
  lld input[2][n];
  
  for(int i=0;i<2;i++)for(int j=0;j<n;j++)cin>>input[i][j];
  lld up[n],down[n],common[n]; //up is for up to down
  up[n-1] = 0*input[0][n-1]+1*input[1][n-1];
  down[n-1] = 0*input[1][n-1]+1*input[0][n-1];
  common[n-1] = input[0][n-1]+input[1][n-1];
  
  for(int i=n-2;i>=0;i--){
    up[i] = up[i+1]+common[i+1]+0*input[0][i]+(2*(n-i)-1)*input[1][i];
    down[i] = down[i+1]+common[i+1]+(2*(n-i)-1)*input[0][i]+0*input[1][i];
    common[i] = common[i+1]+input[0][i]+input[1][i];
  }
  lld ans = 0;
  lld temp = 0;int orientation = 0;
  for(lld i=0;i<n;i++){
    if(orientation==0) ans = max(ans,temp+up[i]+2*i*common[i]);
    else ans = max(ans,temp+down[i]+2*i*common[i]);
    temp += (2*i)*input[orientation][i]+(2*i+1)*input[orientation^1][i];
    orientation ^=1 ;
  }
  cout<<ans<<endl;
}
