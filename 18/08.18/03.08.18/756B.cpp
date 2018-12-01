#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n;
  cin>>n;
  
  vi process;
  lld total[n];
  for(int i=0;i<n;i++){
    lld a;
    cin>>a;
    lld minm = 20;
    lld x = a-90+1,y= a-1440+1;
    int index1 = lower_bound(process.begin(),process.end(),x)-process.begin();
    int index2 = lower_bound(process.begin(),process.end(),y)-process.begin();
    if(index1>0) minm = min(minm,50-(total[i-1]-total[index1-1]));
    else if(i>0) minm = min(minm,50-total[i-1]);
    if(index2>0) minm = min(minm,120-(total[i-1]-total[index2-1]));
    else if(i>0) minm = min(minm,120-total[i-1]);
    
    process.push_back(a);
    total[i] = minm+((i==0)?0:total[i-1]);
    cout<<minm<<endl;
  }

}
