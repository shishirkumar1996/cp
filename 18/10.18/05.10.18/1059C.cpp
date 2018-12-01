#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n;
  cin>>n;
  
  vi output;
  int rem = n;
  for(int i=1;i<=n;i*=2){
    if(rem==3){
      output.push_back(i);output.push_back(i);output.push_back(i*3);
      break;
    } else
    for(int j=i;j<=n;j+= 2*i){ rem--;output.push_back(i); }
  }
  for(int i = 0;i<output.size();i++)cout<<output[i]<<" ";cout<<endl;

}
