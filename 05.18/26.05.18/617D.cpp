#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;

int main(){

  faster
  vp input(3);
  for(int i = 0;i<3;i++)cin>>input[i].first>>input[i].second;
  
  sort(input.begin(),input.end());
  if((input[0].first==input[1].first && input[1].first == input[2].first)||(input[0].second==input[1].second && input[0].second==input[2].second)){
    cout<<1<<endl;return 0;
  }
  else {
    do{
      if((input[0].first==input[1].first && (input[2].second>=max(input[0].second,input[1].second)||input[2].second<=min(input[0].second,input[1].second)))||(input[0].second==input[1].second && (input[2].first>=max(input[0].first,input[1].first)||input[2].first<=min(input[0].first,input[1].first)))){
        cout<<2<<endl;return 0;
      }
    
    }while(next_permutation(input.begin(),input.end()));  
  }
  cout<<3<<endl;

}
