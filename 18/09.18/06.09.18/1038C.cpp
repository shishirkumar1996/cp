#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){

  int n;
  cin>>n;
  
  vi first(n),second(n);
  for(int i=0;i<n;i++) cin>>first[i];
  for(int i=0;i<n;i++) cin>>second[i];
  
  sort(first.begin(),first.end());
  reverse(first.begin(),first.end());
  
  sort(second.begin(),second.end());
  reverse(second.begin(),second.end());
  
  int index1=0,index2=0;
  lld diff = 0;
  int chance = 0;
  while(index1<n || index2 < n){
    lld x=0,y=0;  
    if(index1<n)x = first[index1];
    if(index2<n)y = second[index2];
    
    if(chance==0)
      if(x<=y) index2++; else { diff += x;index1++; }
    else if(chance==1){
      if(x>=y) index1++; else { diff -= y;index2++; } 
    }
    chance ^= 1;
  }
  cout<<diff<<endl;
}
