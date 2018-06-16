#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  if(n<6) cout<<-1<<endl;
  else {
    cout<<1<<" "<<2<<endl;
    cout<<1<<" "<<3<<endl;
    cout<<1<<" "<<4<<endl;
    for(int i = 5;i<=n;i++)cout<<2<<" "<<i<<endl;
  }
  
  for(int i = 2;i<=n;i++)
    cout<<1<<" "<<i<<endl;

}
