#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  int n,k;
  cin>>n>>k;
  
  int ans = INT_MAX;
  vi output;
  for(int i=1;i<=k+1 && i<=n;i++){
    vi x;
    int temp = 0;
    int j;
    for(j=i;j<=n;j+= 2*k+1){temp++;x.push_back(j);}
    j -= (2*k+1);
    if(n-j>k)continue;
    if(temp<ans){ans=temp;output = x;}
  }
  cout<<ans<<endl;
  for(int i=0;i<ans;i++)cout<<output[i]<<" ";cout<<endl;
}
