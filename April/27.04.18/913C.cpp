#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false); cin.tie(0);
#define lld long long int
#define pr pair< lld, int >
#define vp vector< pr >

using namespace std;

int compare(pr a, pr b){
  return (a.first*1.0/pow(2,a.second-1))<(b.first*1.0/pow(2,b.second-1));
}


lld calc(lld remainder,int index,vp input){
  
  lld num = remainder/(int)(pow(2,input[index].second-1));
  lld cost = num*input[index].first;
  lld rem = remainder -num*pow(2,input[index].second-1);
  
  if(rem ==0)
    return cost;
  
    
  return cost+min(input[index].first,calc(rem,index+1,input));

}


int main(){ 
  
  int n;
  lld l;
  cin>>n>>l;
  vp input(n);
  for(int i = 0;i<n;i++){
    cin>>input[i].first;
    input[i].second = i+1;
  }
    
  sort(input.begin(),input.end(),compare);

  cout<<calc(l,0,input)<<endl;
  

}



