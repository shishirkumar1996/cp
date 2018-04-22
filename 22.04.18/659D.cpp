#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;


struct point{
int x,y;
};


int calc(vector < struct point > input){

  int num = 0;
  for(int i = 0;i<input.size()-1;i++){
    struct point last = input[(i+2)%input.size()];
    struct point middle = input[(i+1)%input.size()];
    struct point first = input[i];
  
    int val = (last.y-middle.y)*(first.x-middle.x) - (first.y-middle.y)*(last.x-middle.x);
    if(val < 0)
      num++;
  }

  return num;
}

int main(){
  faster
  int n;
  cin>>n;
  vector<struct point> input(n+1);
  for(int i = 0;i<=n;i++){
    cin>>input[i].x>>input[i].y;
  }
  cout<<calc(input)<<endl;
}
