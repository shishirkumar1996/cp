#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int d,n;
  cin>>d>>n;
  lld temp =1;
    for(int i = 1;i<=d;i++) temp = temp*100;

  lld ans = 0;
  for(int i = 0;i<n;i++) ans += temp;
  if(n==100) ans += temp;
  
  cout<<ans<<endl;
}
