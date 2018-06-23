#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

int main(){

  int n,a,b,c;
  cin>>a>>b>>c>>n;
  
  int num = n -(a+b-c);
  if(num>=1 && a>=c && b>=c) cout<<num<<endl;
  else cout<<-1<<endl;
}
