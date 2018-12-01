#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define PI 3.14159265
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){

  int n;
  cin>>n;
  vp input(n);
  for(int i=0;i<n;i++) cin>>input[i].first>>input[i].second;

  vector< double > angles;
  for(int i=0;i<n;i++){
    double x = input[i].first,y= input[i].second;
    if(x>=0 && y>=0){
      if(x==0) angles.push_back(90); else angles.push_back(atan(y/x)*180.0/PI);
    } else if(x<0 && y>=0){
      angles.push_back(180.0-atan(abs(y)/abs(x))*180.0/PI);
    } else if(x>=0 && y<0){
      if(x==0) angles.push_back(270); else angles.push_back(360.0-atan(abs(y)/abs(x))*180.0/PI);
    } else if(x<0 && y<0){
      angles.push_back(180.0+atan(abs(y)/abs(x)));
    }
  }
  sort(angles.begin(),angles.end());
  double ans = INT_MAX;
  for(int i=0;i<n;i++){
//    cout<<angles[i]<<endl;
    double x = angles[(i-1+n)%n]-angles[i];
    if(x<0) x += 360;
    ans = min(x,ans);
  }
  cout<<setprecision(15)<<ans<<endl;
}
