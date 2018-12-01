#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(2e9+7)

using namespace std;

int main(){

  lld l,r;
  cin>>l>>r;
  
  vi output;
  for(lld i=1;i<=MAXM;i=i*2)
    for(lld j=1;j*i<=MAXM;j=j*3)output.push_back(i*j);
  
  sort(output.begin(),output.end());
  
  int index1 = lower_bound(output.begin(),output.end(),l)-output.begin();
  int index2 = lower_bound(output.begin(),output.end(),r+1)-output.begin()-1;
  cout<<index2-index1+1<<endl;

}
