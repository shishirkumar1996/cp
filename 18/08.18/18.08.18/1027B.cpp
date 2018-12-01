#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  faster
  lld n,q;
  cin>>n>>q;
  
  for(int i=0;i<q;i++){
    lld r,c;
    cin>>r>>c;
    lld num;
    if((r+c)%2==0){  
      num = 0;
      if(n%2==0){
        num += (r-1)*(n/2);
        num += (c+1)/2;
      } else {
        if(r%2==0){
          num += (r-2)/2*n;
          num += (n+1)/2;
          num += (c+1)/2;
        } else {
          num += (r-1)/2*n;
          num += (c+1)/2;
        }
      }
    } else {
      num = (n*n+1)/2;
      if(n%2==0){
        num += (r-1)*(n/2);
        num += (c+1)/2;
      } else {
        if(r%2==0){
          num += (r-2)/2*n;
          num += n/2;
          num += (c+1)/2;
        } else {
          num += (r-1)/2*n;
          num += (c+1)/2;
        }
      }
    }
    cout<<num<<endl;

  }
}
