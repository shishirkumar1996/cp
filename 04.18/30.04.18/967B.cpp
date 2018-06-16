#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

int main(){

  lld n,m,k;
  cin>>n>>m>>k;
  lld row = 1,col = 1;
  if(k<n){
    cout<<1+k<<" "<<col<<endl;
    return 0;
  }
  row = n;
  k -= n-1;
  
  lld step = (k-1)/(2*(m-1));
  row -= 2*step;
  k = (k-1)%(2*(m-1))+1;
  lld n_step = (k-1)/(m-1);
  row -= n_step;
  k = (k-1)%(m-1)+1;
  
  
  if(n_step){ // this means on odd row
    col = m-(k-1);
  }
  else{
    col = 2+(k-1);
  }

  cout<<row<<" "<<col<<endl;
}
