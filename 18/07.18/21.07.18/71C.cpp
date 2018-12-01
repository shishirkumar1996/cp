#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;


int main(){

  faster
  int n;
  cin>>n;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  for(int i=1;i<=n/3;i++){
    if(n%i !=0) continue;
    
    for(int j=0;j<i;j++){
      int flag = 1;
      int index = j;
      for(int k=0;k<n/i;k++)
        if(input[index] == 0){flag = 0;break;} else index += i;
      if(flag == 1){cout<<"YES"<<endl;return 0;}  
    }
  }
  cout<<"NO"<<endl;
}
