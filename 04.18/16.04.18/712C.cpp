#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;


int calc(int x,int y){

  int init[3] = {y,y,y};
  
  int res = 0;
  while(init[0] != x || init[1] != x || init[2] != x){
    res++;
    int minm = INT_MAX,minIndex = -1;
    for(int i =0;i<3;i++)
      if(init[i] < minm)
        minm = min(minm,init[i]),minIndex = i;
  
    init[minIndex] = min(x,init[0]+init[1]+init[2]-1-init[minIndex]);
  }

  return res;

}

int main(){
  
  faster
  int x,y;
  cin>>x>>y;
  cout<<calc(x,y)<<endl;

}
