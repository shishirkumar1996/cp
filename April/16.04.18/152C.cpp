#include<bits/stdc++.h>
#define vs vector< string >
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

#define mod ((lld)1e9+7)

using namespace std;

lld calc(int n,int m,vs input){
  
  lld counter = 1;
  for(int i =0;i<m;i++){
    
    lld sum  = 0;
    map< char,int> present;
    for(int j = 0;j<input.size();j++){
      if(!present[input[j][i]])
        present[input[j][i]] = 1, sum++;
    }
    counter = (counter*sum)%mod;
  }
  return counter;
}

int main(){

  faster
  int n,m;
  cin>>n>>m;
  vs input(n);
  for(int i =0;i<n;i++)
    cin>>input[i];
    
  cout<<calc(n,m,input)<<endl;
}
