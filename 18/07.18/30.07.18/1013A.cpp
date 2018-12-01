#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  
  int ans =0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    ans += a;
  }
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    ans-= a;
  }
  if(ans>=0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
