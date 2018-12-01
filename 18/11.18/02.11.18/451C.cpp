#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int t;
  cin>>t;
  
  while(t--){
    lld n,k,d1,d2;
    cin>>n>>k>>d1>>d2;
    
    if(n%3 != 0){cout<<"no\n";continue;}
    int flag = 0;
    for(int i=-1;i<=1;i++){
      for(int j=-1;j<=1;j++){
        if(i==0||j==0)continue;
        lld temp = k+i*d1+j*d2;
        if(temp%3 !=0)continue;
        lld x1 = temp/3;
        lld x2 = x1 - i*d1;
        lld x3 = x1-j*d2;
        if(x1<0 || x1>k|| x2<0 || x2>k || x3<0 || x3>k || x1>n/3|| x2>n/3 || x3>n/3) continue;
        cout<<"yes\n";
        flag = 1;
        break;
      }
      if(flag)break;
    }
    if(!flag)cout<<"no\n";
  }

}
