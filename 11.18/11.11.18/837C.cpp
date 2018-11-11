#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){

  int n,a,b;
  cin>>n>>a>>b;
  
  int maxm = 0;
  int input[n][2];
  for(int i=0;i<n;i++)cin>>input[i][0]>>input[i][1];
  
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=0;k<2;k++)for(int l=0;l<2;l++){
        int w = input[i][k]+input[j][l];
        int h = max(input[i][k^1],input[j][l^1]);
        if((w<=a && h<=b)||(w<=b && h<=a)) maxm = max(maxm,input[i][0]*input[i][1]+input[j][0]*input[j][1]);
      }
    }
  }
  cout<<maxm<<endl;

}
