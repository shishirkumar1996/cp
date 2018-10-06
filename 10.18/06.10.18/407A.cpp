#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; for(int i=0;i<n;i++) cerr<<a[i]<<' ';cerr<<'\n'; }
#define TM

using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main(){

  int a,b;
  cin>>a>>b;
  if(a>b)swap(a,b);
  int g = gcd(a,b);
//  if(b%a != 0){ cout<<"NO"<<endl;return 0;}

  int temp = g*g;
  int x,y;int flag = 0;
  unordered_map< int,int > s;
  for(int i=1;i*i<=temp;i++){
    s[i*i] = 1;
    if(s.find(temp-i*i) != s.end()){
      x = sqrt(temp-i*i),y = i;
      flag = 1;break;
    }
  }
  if(!flag){cout<<"NO"<<endl;return 0;}
  int factor_a = a/g;
  int factor_b = b/g;
  cout<<"YES"<<endl;
  cout<<0<<" "<<0<<endl;
  if(factor_a*y != x*factor_b){
    cout<<factor_a*x<<" "<<factor_a*y<<endl;
    cout<<-y*factor_b<<" "<<x*factor_b<<endl;
  }
  else{
    cout<<factor_b*x<<" "<<factor_b*y<<endl;
    cout<<-y*factor_a<<" "<<x*factor_a<<endl;
  }
  #ifdef TM
    cerr<<" Time elapsed : "<<1.0*clock()/CLOCKS_PER_SEC<<" s\n";
  #endif
}
