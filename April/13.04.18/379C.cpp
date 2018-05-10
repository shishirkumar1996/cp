#include<bits/stdc++.h>

#define lld long long int
#define vi vector < lld >
#define pr pair < lld, lld >
#define vp vector < pr >

using namespace std;


int compare1(pr a,pr b){
  return (a.first < b.first || (a.first == b.first && a.second < b.second));   

}


int compare2(pr a,pr b){
  return a.second < b.second;
}

void calc(int n, vi input){

  vp process;
  for(int i =0;i<n;i++){
    lld num= input[i];
    pr a;
    a.first = num,a.second = i;
    process.push_back(a);
  }
  
  sort(process.begin(),process.end(),compare1);
  lld minm = -1;
  
  for(int i = 0;i<n;i++){
    
    if(minm>=process[i].first)
      process[i].first = minm+1;
    minm = process[i].first;
    
  }
  
  sort(process.begin(),process.end(),compare2);

  for(int i = 0;i<n;i++){
    cout<<process[i].first<<" ";
  }  
  cout<<endl;

}

int main(){
  
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vi input;
  for(int i = 0;i<n;i++){
    lld num;
    cin>>num;
    input.push_back(num);
  }
  calc(n,input);

}

