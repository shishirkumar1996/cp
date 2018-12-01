#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

int main(){
  
  lld n;
  cin>>n;
  
  lld ans = 0;
  ans += n/100;
  n = n%100;
  ans += n/20;
  n = n%20;
  ans += n/10;
  n = n%10;
  ans += n/5;
  n = n%5;
  ans += n/1;
  n = n%1;
  cout<<ans<<endl;

}
