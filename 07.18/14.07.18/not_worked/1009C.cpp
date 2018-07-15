#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< double,double >
#define vp vector< pr >

using namespace std;

int main(){
  
  int n,m;
  cin>>n>>m;
  
  vp process(m);
  for(int i=0;i<m;i++) cin>>process[i].first>>process[i].second;
  
  double ans = 0;
  for(int i=0;i<m;i++){
    ans += process[i].first;
    double x = process[i].second;
    if(x<0){
      int y = n/2;
      if(n%2==0){
        ans+= x*y*(y+1)/(2.0*n);
        ans += x*y*(y-1)/(2.0*n);
      } else {
        ans += 2*x*y*(y+1)/(2.0*n);
      }
    } else {
//      cout<<x*n*(n-1)/(2.0*n)<<endl;
      ans += x*n*(n-1)/(2.0*n);
      
    }
//    cout<<ans<<endl;
  }    
  cout<<setprecision(9)<<ans<<endl;
}
