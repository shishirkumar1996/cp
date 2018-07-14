#include<bits/stdc++.h>
#define lld long long int
#define pr pair< int,int >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vp vector< pr >

using namespace std;

int gcd(int a,int b){

  if(a%b==0) return b;
  return gcd(b,a%b);
}


int main(){

  faster
  int n,m;
  cin>>n>>m;
  
  vp output;
  for(int i= 1;i<n;i++){
    int flag = 0;
    for(int j= i+1;j<=n;j++){
      if(gcd(i,j)==1)output.push_back(make_pair(i,j));
      if(output.size()==m) {flag = 1;break;}
    }
    if(flag) break;
  }

  if(output.size()==m){
    cout<<"Possible"<<endl;
    for(int i=0;i<output.size();i++)
      cout<<output[i].first<<" "<<output[i].second<<endl;;
  }
  else cout<<"Impossible"<<endl;
}
