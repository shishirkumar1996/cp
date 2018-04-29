#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false); cin.tie(0);
#define lld long long int

using namespace std;


int main(){

  lld w,h,n;
  cin>>w>>h>>n;
  set<lld> orientation[2];
  multiset<lld> width[2];
  
  set<lld>::iterator it1,it2;
  
  orientation[0].insert(0);
  orientation[0].insert(h);
  orientation[1].insert(0);
  orientation[1].insert(w);
  
  width[0].insert(-h);
  width[1].insert(-w);
  
  for(int i =0;i<n;i++){
    
    char c;
    lld m;
    cin>>c>>m;
    int index = 0;
    if(c=='V')
      index = 1;
    
    it1 = orientation[index].lower_bound(m);
    it2 = it1;
    it2--;
    width[index].erase(width[index].find(*it2-*it1));
    width[index].insert(*it2-m);
    width[index].insert(m-*it1);
    orientation[index].insert(m);
    cout<<(*width[0].begin())*(*width[1].begin())<<endl;
  
  }
}
