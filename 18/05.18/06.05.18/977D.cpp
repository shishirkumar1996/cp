#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define pr pair< lld,lld >
#define ppr pair< lld, pr >
#define vpr vector< ppr >

using namespace std;

int compare(ppr a,ppr b){
  return (a.second.first > b.second.first || (a.second.first == b.second.first && a.second.second < b.second.second));
}

int main(){

  int n;
  cin>>n;
  vpr input(n);
  for(int i = 0;i<n;i++){
    lld a;
    cin>>a;
    lld threes = 0;
    lld twos = 0;
    lld b = a;
    while(a>0){
      if(a%3!=0)
        break;
      a = a/3;
      threes++;
    }
    while(a>0){
      if(a%2!=0)
        break;
      a = a/2;
      twos++;
    }
        
    input[i] = (make_pair(b,make_pair(threes,twos)));
//    cout<<input[i].first<<endl;
  }
  sort(input.begin(),input.end(),compare);
  
  for(int i = 0;i<n;i++)
    cout<<input[i].first<<" ";
  cout<<endl;
}

