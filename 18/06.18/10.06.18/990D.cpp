#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int output[1001][1001];

int main(){

  int n,a,b;
  cin>>n>>a>>b;
  
  if((a>1 && b>1)||(a==1 && b==1 && n>=2 && n<=3)){cout<<"NO"<<endl;return 0;}
  
  for(int i=0;i<n;i++)for(int j = 0;j<n;j++)output[i][j] = 0;
  
  int maxm = max(a,b);
  maxm = n-maxm+1;
  for(int i=0;i<maxm-1;i++) output[i][i+1] = output[i+1][i] = 1; 

  if(a<b){
    for(int i =0;i<n;i++) for(int j= 0;j<n;j++)
    if(i!=j) output[i][j] = output[i][j] ^1;
  }
  cout<<"YES"<<endl;
  for(int i= 0;i<n;i++){
    for(int j= 0;j<n;j++)cout<<output[i][j];
    cout<<endl;
  }
}
