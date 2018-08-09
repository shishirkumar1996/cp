#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int max_sharp[105];
  max_sharp[1] = 1;
  max_sharp[3] = 5;
  
  int sharp = 1;
  int index = 5;
  while(sharp<=100){
    
    if((index-1)%4==0) sharp = (index-1)/2*index+(index+1)/2;
    else sharp = 2*(index+1)/2+(index-3)/2*index+index/2;
    max_sharp[index] = sharp;
//    cout<<index<<" "<<max_sharp[index]<<endl;
    index += 2;
  }
  int n;
  cin>>n;
  if(n==3){cout<<5<<endl;return 0;}
  index = 1;
  while(max_sharp[index]<n)index+=2;
  cout<<index<<endl;

}
