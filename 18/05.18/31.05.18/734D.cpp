#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld ,lld >
#define pcr pair < char, pr >
#define vpcr vector< pcr >

using namespace std;

lld r,c;
int compare(pcr a,pcr b){
  return (abs(a.second.first-r)+abs(a.second.second-c)<abs(b.second.first-r)+abs(b.second.second-c));
}

int find(lld a,lld b){
  if(r==a){
    if(b>c) return 2; else return 6;
  }
  else if(c==b){
    if(a<r) return 0; else return 4;
  }
  else if(abs(r-a)==abs(c-b)){
    if(a<r && b>c) return 1;
    else if(a>r && b>c) return 3;
    else if(a>r && b<c) return 5;
    else if(a<r && b<c) return 7;
  }
  else return -1;

}


int main(){

  faster
  lld n;
  cin>>n;
  cin>>r>>c;
  
  vpcr input(n);
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second.first>>input[i].second.second;
  
  int blocked[8];
  for(int i =0;i<8;i++) blocked[i] = false;
  
  sort(input.begin(),input.end(),compare);
  
  for(int i = 0;i<n;i++){
    
    int orientation = find(input[i].second.first,input[i].second.second);
    if(orientation == -1 || blocked[orientation]) continue;
    
    blocked[orientation] = true;
    char piece = input[i].first;
    if((piece=='R' && orientation%2==0)||(piece=='B' && orientation%2==1)|| piece=='Q'){
      cout<<"YES"<<endl;
      return 0;
    }
  
  }
  cout<<"NO"<<endl;

}
