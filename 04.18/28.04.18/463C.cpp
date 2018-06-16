#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< int , int >
#define vi vector< lld >
#define vii vector< vi >
using namespace std;



int main(){
  
  faster
  int n;
  cin>>n;
  vii input(n);
  vi d1(2*n-1,0),d2(2*n-1,0);
  for(int i = 0;i<n;i++){ 
    input[i].resize(n);
    for(int j =0;j<n;j++){
      cin>>input[i][j];
      d1[i+j] += input[i][j];
      d2[i-j+n-1] += input[i][j];
    }
  }
  
  lld sol[2];
  pr pos[2];
  sol[0] = sol[1] = -1;
  for(int i =0;i<n;i++)
    for(int j = 0;j<n;j++){
      lld val = d1[i+j]+d2[i-j+n-1]-input[i][j];
      if(val > sol[(i+j)%2]){
        sol[(i+j)%2] = val;
        pos[(i+j)%2].first = i;
        pos[(i+j)%2].second = j;
      }
    
    }
  cout<<sol[0]+sol[1]<<endl;;
  cout<<pos[0].first+1<<" "<<pos[0].second+1<<" "<<pos[1].first+1<<" "<<pos[1].second+1<<endl;

}  
