#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  string a,b;
  cin>>a>>b;
  
  lld type01=0,type00=0,type10=0,type11=0;
  
  for(int i=0;i<n;i++)
    if(a[i]=='0'&&b[i]=='0')type00++;
    else if(a[i]=='0' && b[i]=='1')type01++;
    else if(a[i]=='1' && b[i]=='0') type10++;
    else if(a[i]=='1' && b[i]=='1')type11++;

  lld ans = 0;
  ans += type01*type10;
  ans += type11*type00;
  ans += type00*type10;
  cout<<ans<<endl;
}


