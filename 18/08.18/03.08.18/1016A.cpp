#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){

  lld sum = 0,last =0,a;
  int n;
  lld m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a;
    sum += a;
    lld x = sum/m;
    cout<<x-last<<" ";
    last = x;   
  }
  cout<<endl;
}
