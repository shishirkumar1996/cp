#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int m,n;
  cin>>m>>n;
  
  lld fact[20];
  fact[0] = fact[1] = 1;
  for(int i=2;i<20;i++)fact[i] = fact[i-1]*i;

  cout<<"number of ways = "<<fact[n+m-2]/(fact[m-1]*fact[n-1])<<endl;
}
