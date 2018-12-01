#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);

using namespace std;

int main(){

  int n,k;
  cin>>n>>k;
  string input;
  cin>>input;
  
  sort(input.begin(),input.end());
  
  int ans = 0;
  int i=0,j=0,last = -2;
  while(i<k && j<n){
    int x = input[j] - 'a';
    if(x-last >= 2){
      ans += x+1;
      last = x;
      i++;
    }
    j++;
  }
  if(i==k)cout<<ans<<endl;
  else cout<<-1<<endl;

}
