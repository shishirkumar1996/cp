#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;

int main(){

  lld n,m,a,b;
  cin>>n>>m>>a>>b;
  lld process = n%m;
  cout<<min(process*b,(m-process)*a)<<endl;  
}
