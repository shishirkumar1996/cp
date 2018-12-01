#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< lld, lld >
#define pc pair< lld, char >
#define vp vector< pr >
#define vpc vector< pc >

using namespace std;

int compare(pr a,pr b){
  
  return abs(a.first) < abs(b.first) || (abs(a.first) == abs(b.first)  && abs(a.second) < abs(b.second));

}


int main(){
  
  faster
  lld count = 0;
  int n;
  cin>>n;
  vp input(n);
  for(int i = 0;i<n;i++) {
    cin>>input[i].first>>input[i].second;
    if(input[i].first == 0 || input[i].second == 0)
      count++;
  }
  
  sort(input.begin(),input.end(),compare);
  cout<<6*n-2*count<<endl;
  
  for(int i = 0;i<n;i++){
    
    if(input[i].first < 0) cout<<"1 "<<abs(input[i].first)<<" L"<<'\n';
    else 
    if(input[i].first > 0) cout<<"1 "<<abs(input[i].first)<<" R"<<'\n';
    
    if(input[i].second < 0)cout<<"1 "<<abs(input[i].second)<<" D"<<'\n';
    else if(input[i].second > 0) cout<<"1 "<<abs(input[i].second)<<" U"<<'\n';
    
    cout<<"2"<<'\n';
    
     if(input[i].second < 0)cout<<"1 "<<abs(input[i].second)<<" U"<<'\n';
    else if(input[i].second > 0) cout<<"1 "<<abs(input[i].second)<<" D"<<'\n';
    
    if(input[i].first < 0) cout<<"1 "<<abs(input[i].first)<<" R"<<'\n';
    else 
    if(input[i].first > 0) cout<<"1 "<<abs(input[i].first)<<" L"<<'\n';
    
    cout<<"3"<<'\n';
  }

}
