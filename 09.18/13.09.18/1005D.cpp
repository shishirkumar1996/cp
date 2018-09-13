#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  
  int ans = 0;
  int temp = 0;
  int x[3];
  x[0] = x[1] = x[2] = 0;
  for(int i=0;i<input.size();i++){
    temp += (input[i]-'0');
    if(temp%3==0||x[temp%3]){ ans++; temp = 0; x[0] = x[1] = x[2] = 0;}
    else x[temp%3]++; 
  }
  cout<<ans<<endl;
}
