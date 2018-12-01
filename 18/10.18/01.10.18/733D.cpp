#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;

int main(){
  int n;
  cin>>n;
  
  map< pr,vp > process;
  for(int i=0;i<n;i++){
    vi temp(3);
    cin>>temp[0]>>temp[1]>>temp[2];
    sort(temp.begin(),temp.end());
    process[make_pair(temp[2],temp[1])].push_back(make_pair(temp[0],i+1));
  }
  map< pr,vp >::iterator it;
  lld maxm = 0;
  vi output;
  for(it = process.begin();it!=process.end();it++){
    pr x = it->first;
    vp y = it->second;
    sort(y.begin(),y.end());
    lld z;
    vi s;
    if(y.size()==1){ z = y[0].first; s.push_back(y[0].second); }
    else{ 
      z = y[y.size()-1].first+y[y.size()-2].first;
      s.push_back(y[y.size()-1].second);
      s.push_back(y[y.size()-2].second);
    }
    lld temp = min(z,min(x.first,x.second));
    if(temp>maxm){maxm = temp; output = s;}
  }
  cout<<output.size()<<endl;
  for(int i=0;i<output.size();i++)cout<<output[i]<<" ";
  cout<<endl;
}
