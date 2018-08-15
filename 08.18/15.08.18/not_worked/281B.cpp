#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int x,y,n;
  cin>>x>>y>>n;
  
  double diff = INT_MAX;
  int a,b;
  for(int i =1;i<=n;i++){
    int temp_a,temp_b;
    temp_b = i;
    temp_a = round(x*1.0*temp_b/(y*1.0));
    if(abs(x*1.0*temp_b/(y*1.0)-temp_a)==0.5)temp_a--;
    double temp_diff = abs(1.0*(temp_b*x-temp_a*y)/(1.0*temp_b*y));
    if(temp_diff<diff){
      diff = temp_diff;
      a = temp_a;
      b = temp_b;
    }
  }
  cout<<a<<"/"<<b<<endl;
}
