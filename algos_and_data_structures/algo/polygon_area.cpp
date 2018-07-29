#include<bits/stdc++.h>
#define vi vector< int >
#define vp vector< pr >
#define pr pair< int,int >

using namespace std;

vp points;
int n;

float area(){
  
  float ar = 0;
  for(int i=0;i<n;i++)
    ar += points[i].first*abs(points[(i+1)%n].second-points[(i-1+n)%n].second);
  
  return ar;
}

int main(){
  
  n = 3;
  points.push_back(make_pair(0,0));
  points.push_back(make_pair(0,5));
  points.push_back(make_pair(5,0));

  cout<<area()<<endl;
}
