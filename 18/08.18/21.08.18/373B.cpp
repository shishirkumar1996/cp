#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int num_digit(lld num){
  int ans = 0;
  while(num){ ans++;num = num/10; }
  return ans;
}

lld largest(int digit){

  lld x = 0;
  for(int i=1;i<=digit;i++)x = x*10+9;
  return x;
}

int main(){

  lld w,m,k;
  cin>>w>>m>>k;

  int digit = num_digit(m);
  lld ans = 0;
  while(true){
    lld tot = largest(digit)-m+1;
    if(tot>=w/(k*digit)){ ans += w/(k*digit);break; }  
    w -= tot*k*digit;  
    ans += tot;
    m = largest(digit)+1;
    digit++;
  }
  cout<<ans<<endl;
}
