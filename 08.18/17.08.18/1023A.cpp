#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int n,m;
  cin>>n>>m;
  string a,b;
  cin>>a>>b;
  
  int index1 = 0,index2 = 0;
  while(index1<n && index2<m){
    if(a[index1]==b[index2]){index1++;index2++;}
    else if(a[index1]=='*'){break;}
    else{cout<<"NO"<<endl;return 0;}
  }
  int index3 = n-1,index4 = m-1;
  while(index3>=index1 && index4>=index2){
    if(a[index3]==b[index4]){index3--;index4--;}
    else if(a[index3]=='*'){break;}
    else {cout<<"NO"<<endl;return 0;}
  }
  if(index3!=index1)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}
