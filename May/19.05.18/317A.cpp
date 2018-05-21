#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);

using namespace std;

int main(){

  faster
  lld x,y,m;
  cin>>x>>y>>m;
  
  if(x>=m || y>=m) cout<<0<<endl;
  else if(x<=0 && y<=0) cout<<-1<<endl;
  else{
    lld count = 0;
    while(x<m && y<m){
      if(x<0||y<0){
        if(x<0)
          count = (-x/y)+1,x = x+y*count;
        else
          count =(-y/x)+1,y = y+x*count;
        continue;
      }
      if(x<=y) x = x+y;
      else y = x+y;
      count++;
    }
    cout<<count<<endl;  
  }
}
