#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

bool check(lld n,lld k){

  lld vas = 0;
  lld temp = n;
  while(n!= 0){
    vas += min(n,k);
    n -= min(n,k);
    n -= n/10;
  }
  if(vas>=(temp+1)/2)return true; else return false;
}


int main(){

  lld input;
  cin>>input;
  
  lld low = 1,high = input;
  
  while(low<high){
    lld mid = (low+high)/2;
    if(check(input,mid)) high = mid;
    else low = mid+1;
  }
  
  cout<<low<<endl;

}
