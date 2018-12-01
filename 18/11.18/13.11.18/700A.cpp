#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n,k;
  lld l;
  double v1,v2;
  cin>>n>>l>>v1>>v2>>k;
  
  int num = (n+k-1)/k;
  double ans = l/v2;
  double x = 0;
  
  cout<<ans<<endl;
  for(int i=2;i<=num;i++){
    double dist = v1*(l-x)/v2;
    x += dist;
    double time =  (l-x)/(v1+v2);
    x += v1*time;
    ans += 2*time;
    cout<<ans<<endl;
  }
  cout<<setprecision(9)<<fixed;
  cout<<ans<<'\n';
}
