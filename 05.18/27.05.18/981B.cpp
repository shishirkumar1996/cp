#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;


int main(){

  faster
  map< lld, lld > val;
  lld sum = 0;
  int n,m;
  cin>>n;
  
  for(int i = 0;i<n;i++){
    lld a,b;
    cin>>a>>b;
    val[a] = b;
    sum+= b;
  }
  cin>>m;
  for(int i = 0;i<m;i++){
    lld a,b;
    cin>>a>>b;
    if(b>val[a]) sum += b-val[a];
  }
  cout<<sum<<endl;

}
