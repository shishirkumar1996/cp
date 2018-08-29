#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  
  int ans = 0;
  int i = 0;
  int max_len = 0;
  while(i<input.length()){
    int len = 1;
    while(input[i+len]=='0' && i+len<input.length()) len++;
    if(len>max_len || (len==max_len && input[0]<input[i])) ans=1;
    else ans++;
    i += len;
    max_len = i;
  }
  cout<<ans<<endl;
}
