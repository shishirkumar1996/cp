#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string input;
    cin>>input;
    int flag = 1;
    for(int i=0;i<=n/2;i++){
      if(abs(input[i]-input[n-1-i])>2||abs(input[i]-input[n-1-i])==1){cout<<"NO"<<endl;flag =0;break;}
//      cout<<i<<" "<<input[i]<<" "<<input[n-1-i]<<" "<<abs(input[i]-input[n-1-i])<<endl;
    }
    if(flag)cout<<"YES"<<endl;
  }
}
