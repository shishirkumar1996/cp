#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >


using namespace std;


int main(){


  int parallel[4][2],tilt[4][2];
  
  for(int i =0;i<4;i++) cin>>parallel[i][0]>>parallel[i][1];
  for(int i =0;i<4;i++) cin>>tilt[i][0]>>tilt[i][1];

  for(int i=0;i<4;i++)for(int j= 0;j<4;j++)
    if(parallel[i][1] == tilt[i][1] && parallel[i][0] == tilt[i][0]){
    cout<<"YES"<<endl;
    return 0;
  }

  int max_x = INT_MIN,max_y = INT_MIN,min_x = INT_MAX,min_y = INT_MAX;
  for(int i =0;i<4;i++){
    max_x = max(max_x,parallel[i][0]);
    max_y = max(max_y,parallel[i][1]);
    min_x = min(min_x,parallel[i][0]);
    min_y = min(min_y,parallel[i][1]);
  }
  
  for(int i =0;i<4;i++)
    if(tilt[i][0] >= min_x && tilt[i][0]<=max_x && tilt[i][1]>=min_y && tilt[i][1]<= max_y)
    {
      cout<<"YES"<<endl;return 0;
    }
  
  int max_tilt_x = INT_MIN,max_tilt_y = INT_MIN,min_tilt_x = INT_MAX,min_tilt_y = INT_MAX;
  for(int i =0;i<4;i++){
    max_tilt_x = max(max_tilt_x,tilt[i][0]);
    max_tilt_y = max(max_tilt_y,tilt[i][1]);
    min_tilt_x = min(min_tilt_x,tilt[i][0]);
    min_tilt_y = min(min_tilt_y,tilt[i][1]);
  }
  double center_x=0.5*(max_tilt_x+min_tilt_x),center_y = 0.5*(max_tilt_y+min_tilt_y);
  
  for(int i =0;i<4;i++){
    if(parallel[i][0] >= min_tilt_x && parallel[i][0] <= max_tilt_x && parallel[i][1] >= min_tilt_y && parallel[i][1] <= max_tilt_y){
      int coord_x,coord_y;
      if(abs(max_tilt_x-parallel[i][0]) > abs(min_tilt_x-parallel[i][0]))
        coord_x = min_tilt_x; else coord_x = max_tilt_x;
      if(abs(max_tilt_y-parallel[i][1]) > abs(min_tilt_y-parallel[i][1]))
        coord_y = min_tilt_y;else coord_y = max_tilt_y;
//      cout<<coord_x<<" "<<coord_y<<endl;
      if(pow(coord_x-parallel[i][0],2)+pow(coord_y-parallel[i][1],2) >= pow(center_x - parallel[i][0],2)+pow(center_y - parallel[i][1],2)){
//        cout<<pow(coord_x-parallel[i][0],2)+pow(coord_y-parallel[i][1],2)<<" "<<" "<<pow(center_x - parallel[i][0],2)+pow(center_y - parallel[i][1],2)<<endl;
        cout<<"YES"<<endl;return 0;
      }
      
    }
  }
  
  if(max_tilt_x >= max_x && min_tilt_x <= min_x && max_tilt_y > max_y && min_tilt_y <= min_y){
    cout<<"YES"<<endl;return 0;
  }
  
  cout<<"NO"<<endl;
}
