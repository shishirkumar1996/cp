#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;

int main(){

  faster
  lld n,p;
  cin>>n>>p;
  
  vp input(n);
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second;
  double sum = 0;
  
  for(int i= 0;i<n;i++){
    lld first = input[i].second-input[i].first+1;
    lld second = input[(i+1)%n].second - input[(i+1)%n].first+1;
    lld num_first = (input[i].second)/p-(input[i].first-1)/p;
    lld num_second = (input[(i+1)%n].second)/p - (input[(i+1)%n].first-1)/p;
    sum += 1.0 - ((first-num_first)*1.0/first) * ( (second - num_second)*1.0/second);
  }
  cout<<setprecision(8)<<2000.0*sum<<endl;

}
