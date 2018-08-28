#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

struct sq{
  lld bottom_x,bottom_y,top_x,top_y;
};

int compare(sq a,sq b){
  return (a.bottom_x<b.bottom_x)||(a.bottom_x==b.bottom_x && a.bottom_y==b.bottom_y);
}

int main(){

  int n;
  cin>>n;
  vector< sq > squares(n);
  for(int i=0;i<n;i++)
    cin>>squares[i].bottom_x>>squares[i].bottom_y>>squares[i].top_x>>squares[i].top_y;

  sort(squares.begin(),squares.end(),compare);
  lld left_x=squares[0].bottom_x,low_y=squares[0].bottom_y,right_x=squares[0].top_x,high_y=squares[0].top_y;
  
  int flag = 1;
  int num = 1;
  for(int i=1;i<n;i++){
    if(right_x<squares[i].bottom_x||low_y>squares[i].top_y||high_y<squares[i].bottom_y)continue;
    left_x = max(left_x,squares[i].bottom_x);
    right_x = min(right_x,squares[i].top_x);
    low_y = max(low_y,squares[i].bottom_y);
    high_y = max(high_y,squares[i].top_y);
    num++;
  }
  if(num==n-1){ cout<<left_x<<" "<<low_y<<endl; return 0; }
  left_x = squares[1].bottom_x;
  low_y = squares[1].bottom_y;
  right_x = squares[1].top_x;
  high_y = squares[1].top_y; 
  for(int i=2;i<n;i++){
    left_x = max(left_x,squares[i].bottom_x);
    right_x = min(right_x,squares[i].top_x);
    low_y = max(low_y,squares[i].bottom_y);
    high_y = max(high_y,squares[i].top_y);
  }
  cout<<left_x<<" "<<low_y<<endl;
}
