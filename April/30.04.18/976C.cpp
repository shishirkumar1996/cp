#include<bits/stdc++.h>
#define lld long long int
#define pr pair< lld,lld >
#define ppr pair< pr , lld >
#define vi vector< lld >
#define vp vector< pr >
#define vpp vector< ppr >

using namespace std;


int compare(ppr a,ppr b){
  return a.first.first< b.first.first || (a.first.first==b.first.first && a.first.second > b.first.second);

}

void calc(lld n,vpp  input){
  
  sort(input.begin(),input.end(),compare);
  vi process1(n);
  vi process2(n);
  for(int i =0;i<n;i++){
    process1[i] = input[i].first.first;
    process2[i] = input[i].first.second;
  }
  
  sort(process2.begin(),process2.end());
  
  int index = 0,flag = 0;
  for(int i =0;i<n;i++){
    lld ind= upper_bound(process2.begin(),process2.end(),input[i].first.second)-process2.begin();
    ind--;
    if(ind > i){
 
      flag = 1;
      index = i;
      break;
    }  
  }
  if(!flag){
    cout<<-1<<" "<<-1<<endl;
    return;
  }
  for(int i = index+1;i<n;i++){
    if(input[index].first.second>=input[i].first.second){
      cout<<input[i].second+1<<" "<<input[index].second+1<<endl;
      return;
    }
  }

}


int main(){
  lld n;
  cin>>n;
  vpp input(n);
  for(int i =0;i<n;i++){
    cin>>input[i].first.first>>input[i].first.second;
    input[i].second = i;
  }
  calc(n,input);
}
