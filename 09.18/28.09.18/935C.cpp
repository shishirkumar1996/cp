#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  lld r,x1,y1,x2,y2;
  cin>>r>>x1>>y1>>x2>>y2;
  
  double dist = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
  if(dist>=r*r){ cout<<x1<<" "<<y1<<" "<<r<<endl;return 0; }
  
  dist = sqrt(dist);
  if(dist==0){
    cout<<setprecision(15)<<x1+r/2.0<<" "<<y1<<" "<<r/2.0<<endl;
    return 0;
  }
  double rad = (dist+r)/2;
  double xans = x2+rad*(x1-x2)/dist;
  double yans = y2 +rad*(y1-y2)/dist;
  cout<<setprecision(15)<<xans<<" "<<yans<<" "<<rad<<endl;

}
