#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n,m;
  cin>>n>>m;
  string first="",second="";
  int digits = n/4;
  for(int i=1;i<=digits;i++){
    first += "4";
    second += "5";
  }
  first += "5";second += "5";
  cout<<first<<endl<<second<<endl;
}
