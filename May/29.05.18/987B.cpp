#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

int main(){
  
  faster
  lld x,y;
  cin>>x>>y;
  
  if( x<= y){
    double r = pow(y,x*1.0/y);
    if( x>r) cout<< ">"<<endl;
    else if(x<r) cout<<"<"<<endl;
    else cout<<"="<<endl;  
    return 0;
  } else   
  {
    double r = pow(x,y*1.0/x);
    if( r>y) cout<<">"<<endl;
    else if(r<y) cout<<"<"<<endl;
    else cout<<"="<<endl;
    return 0;
  }  
}
