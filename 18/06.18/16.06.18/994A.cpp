#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  
  vi x(n);
  map< int , int > mp;
  for(int i = 0;i<n;i++) cin>>x[i];
  for(int i = 0;i<m;i++){
    int a;
    cin>>a;
    mp[a]++;
  }
  
  for(int i = 0;i<n;i++) if(mp[x[i]])cout<<x[i]<<" ";
  cout<<endl;

}
