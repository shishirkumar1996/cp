#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int t;
  cin>>t;
  cout<<setprecision(12);cout<<fixed;
  while(t--){
    double d;
    cin>>d;
    if(d==1||d==2||d==3){cout<<"N\n";continue; }
    double x = (d+sqrt(d*d-4*d))/2;
    double y = (d-sqrt(d*d-4*d))/2;
    cout<<"Y "<<x<<" "<<y<<'\n';
  }
}
