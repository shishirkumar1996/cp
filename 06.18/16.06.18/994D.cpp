#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int, int >
#define vpr vector< pr >

using namespace std;


int main(){
  
  int n,m;
  cin>>n>>m;
  vpr one(n),two(m);
  for(int i =0;i<n;i++) cin>>one[i].first>>one[i].second;
  for(int i = 0;i<m;i++) cin>>two[i].first>>two[i].second;
  
  map < int,int >num_count;
  map< pr,int > pair_count;
  
  for(int i = 0;i<n;i++){
    for(int j= 0;j<m;j++){
      if((one[i].first==two[j].first && one[i].second==two[j].second)||(one[i].second==two[j].first && one[i].first == two[j].second))continue;
      else if(one[i].first == two[j].first|| one[i].first == two[j].second) num_count[one[i].first]++,pair_count[one[i]]++,pair_count[two[j]]++;
      else if(one[i].second==two[j].first || one[i].second == two[j].second) num_count[one[i].second]++,pair_count[one[i]]++,pair_count[two[j]]++;
    }
  }
  map< pr,int>::iterator it = pair_count.begin();
  while(it != pair_count.end()){
    if(it->second >= 2){cout<<-1<<endl;return 0;}
    it++;
  }
  
  map< int,int >::iterator it2 = num_count.begin();int count = 0;
  while(it2 != num_count.end()){
    if(it2->second >= 1)count++;
    it2++;
  }
  if(count>1){cout<<0<<endl;return 0;}
  
  it2 = num_count.begin();
  while(it2 != num_count.end()){
    if(it2->second==1){cout<<it2->first<<endl;return 0;}
  }
}
