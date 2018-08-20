#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

   lld n,m,k,t;
   cin>>n>>m>>k>>t;
   
   vi process;
   for(int i=1;i<=k;i++){
    lld a,b;
    cin>>a>>b;
    process.push_back(m*(a-1)+b);
   }
   
   sort(process.begin(),process.end());
   for(int i=1;i<=t;i++){
    lld a,b;
    cin>>a>>b;
    lld x = (a-1)*m+b;
    int index = lower_bound(process.begin(),process.end(),x)-process.begin();
    if(process[index]==x)cout<<"Waste"<<endl;
    else {
      int k = (x-index)%3;
      if(k==0)cout<<"Grapes"<<endl;
      else if(k==1)cout<<"Carrots"<<endl;
      else if(k==2)cout<<"Kiwis"<<endl;
    }
   }

}
