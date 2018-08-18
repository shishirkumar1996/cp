#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e10+7)

using namespace std;

int main(){
  faster
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;  
    map< int,int > process;
    vi num;
    for(int i=0;i<n;i++){
      int a;
      cin>>a;
      if(process[a]%2==1)num.push_back(a);
      process[a]++;
    }  
    sort(num.begin(),num.end());
    double minm = MAXM;
    lld first,second;
    for(int i=0;i<num.size()-1;i++){
      lld p = 2*(num[i]+num[i+1]);
      lld s = num[i]*num[i+1];
      double val = (p*p*1.0)/s;
//      cout<<val<<" "<<num[i]<<" "<<num[i+1]<<endl;
      if(minm>val){minm=val;first =num[i];second = num[i+1];}
    }
//    cout<<num[0]<<" "<<num[1]<<endl;
    cout<<first<<" "<<first<<" "<<second<<" "<<second<<endl;
  }  
  
}
