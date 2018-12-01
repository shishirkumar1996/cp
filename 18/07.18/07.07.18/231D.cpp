#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int x,y,z,x1,y1,z1,ans,box_x[2],box_y[2],box_z[2];
  
  ans = 0;
  cin>>x>>y>>z>>x1>>y1>>z1>>box_y[0]>>box_y[1]>>box_z[0]>>box_z[1]>>box_x[0]>>box_x[1];
  
  if(x>x1) ans+= box_x[1]; else if(x<0) ans+= box_x[0];
  if(y>y1) ans+= box_y[1]; else if(y<0) ans+= box_y[0];
  if(z>z1) ans+= box_z[1]; else if(z<0) ans+= box_z[0];  
  cout<<ans<<endl;
}
