#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  faster
  int n,k;
  cin>>n>>k;
  
  if(n*(n-1)/2 < k*n) {cout<<-1<<endl;return 0;}
  
  cout<<n*k<<endl;
  for(int i =1;i<=n;i++)
    for(int j = 1;j<=k;j++)
      printf("%d %d\n",i,(i+j-1)%n+1);
}
