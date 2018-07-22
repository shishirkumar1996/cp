#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< string,string >
#define pi pair< int,int >

using namespace std;

int main(){

  int n,d;
  cin>>n>>d;
  map< pr,pi > process;
  
  set< pr > ans;
  for(int i=0;i<n;i++){
    int t;
    string a,b;
    cin>>a>>b>>t;
    pr x = make_pair(a,b),y=make_pair(b,a);
    if(process[x].first != t+1){
      process[x].second  = process[x].first;
      process[x].first = t+1;
    }
//    cout<<process[x]<<" "<<process[y]<<endl;
    if((process[y].first>0 && process[y].first < process[x].first && process[y].first +d>=process[x].first)||(process[y].second>0 && process[y].second < process[x].first && process[y].second +d>=process[x].first)){
      if(a>b) swap(a,b);
      ans.insert(make_pair(a,b));
    }
  }
  
  cout<<(int)ans.size()<<endl;
  set< pr >::iterator it;
  for(it = ans.begin();it!= ans.end();it++)cout<<(*it).first<<" "<<(*it).second<<endl;

}
