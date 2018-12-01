#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define vp vector< pr >
#define vi vector< int >
#define NUM 100007

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  vector< set< pr > > positive(NUM);
  vector< set< pr > > negative(NUM);
  
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    if(b-a<0) negative[a-b].insert(make_pair(a,b));
    else positive[b-a].insert(make_pair(a,b));
  }
  
  vi w(n);
  for(int i=0;i<n;i++)cin>>w[i];
  
  vp output;
  pr last;
  for(int i=0;i<n;i++){
    if(output.size()) last = output[output.size()-1];
//    cout<<last.first<<" "<<last.second<<endl;
    pr x;
    if(w[i]<0){
      if(!negative[-w[i]].size()){cout<<"NO"<<endl;return 0;}
      x = *negative[-w[i]].begin();
      negative[-w[i]].erase(negative[-w[i]].begin());
    } else {
      if(!positive[w[i]].size()){cout<<"NO"<<endl;return 0;}
      x = *positive[w[i]].begin();
      positive[w[i]].erase(positive[w[i]].begin());
    }
    if(output.size()&& last.first >= x.first && last.second>=x.second){     
      cout<<"NO"<<endl;return 0;}
    output.push_back(x);
  }
  cout<<"YES"<<endl;
  for(int i=0;i<n;i++)cout<<output[i].first<<" "<<output[i].second<<endl;
}
