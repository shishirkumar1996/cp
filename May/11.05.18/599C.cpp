#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  vp input(n);
  for(int i = 0;i<n;i++){
    cin>>input[i].first;
    input[i].second = i;
  }

  vp process = input;
  sort(input.begin(),input.end());
  
  int gr = n;
  int index = 0;
  for(int i = 0;i<n;i++){
    int ind = lower_bound(input.begin(),input.end(),process[i])- input.begin();
    if(ind > index){
      gr -= (ind-index);
//      cout<<ind<<" "<<index<<endl;
    }    
    index = max(index,max(i+1,ind));
  }
  cout<<gr<<endl;
}
