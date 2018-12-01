#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int num(string s){ return stoi(s);}

int main(){

  string input;
  cin>>input;
  
  int n= input.length();
  int ans = -1;
  if(input.length()>21){cout<<-1<<endl;return 0;}
  
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      string x = input.substr(0,i+1);
      string y = input.substr(i+1,j-i);
      string z = input.substr(j+1,n-j-1);
      if((x.length()>=2 && x[0]=='0')||(y.length()>=2 && y[0]=='0')||(z.length()>=2 && z[0]=='0'))continue;
      if(x.length()>7||y.length()>7||z.length()>7)continue;
      int a = num(x);
      int b = num(y);
      int c = num(z);
      if(a>1000000||b>1000000||c>1000000)continue;
      ans = max(ans,a+b+c);
    }
  }  
  cout<<ans<<endl;

}
