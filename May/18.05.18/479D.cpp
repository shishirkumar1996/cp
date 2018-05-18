#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  lld n,l,x,y;
  cin>>n>>l>>x>>y;
  
  set< lld > input;
  for(int i = 0;i<n;i++) {
    lld a;
    cin>>a;
    input.insert(a);
  }
  
  int first=0,second=0,third=0;
  int pt_both;
  
  set< lld >::iterator it;
  for(it = input.begin();it!=input.end();it++){
    
    lld num = *it;
    if(num-x >=0 && input.count(num-x)) first = 1;
    if(num+x <=n && input.count(num+x)) first = 1;
    if(num -y >=0 && input.count(num-y)) second = 1;
    if(num +y<=l && input.count(num+y)) second = 1;
    
    if(num-x-y>=0 && input.count(num-x-y)) third = 1,pt_both = num-x;
    if(num-x >= 0 && input.count(num-x+y)) third  = 1,pt_both = num-x;
    if(num+x+y<=l && input.count(num+x+y)) third = 1,pt_both = num+x;
    if(num+x<=l && input.count(num+x-y)) third = 1,pt_both = num+x;
    if(num-y>=0 && input.count(num-y+x)) third = 1,pt_both = num-y;
    if(num+y<=l && input.count(num+y-x)) third = 1,pt_both = num+y;
  
  }
  if(first && second){cout<<0<<endl;return 0;}
  if(first){cout<<1<<"\n"<<y<<endl;return 0;}
  if(second){cout<<1<<"\n"<<x<<endl;return 0;}
  if(third){cout<<1<<"\n"<<pt_both<<endl;return 0;}
  cout<<2<<"\n"<<x<<" "<<y<<endl;  

}
