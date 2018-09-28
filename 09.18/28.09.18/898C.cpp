#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  int n;
  cin>>n;
  
  map< string, set< string > > input;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    int num;
    cin>>num;
    for(int j=0;j<num;j++){
      string y;
      cin>>y;
      set< string >::iterator it;
      int flag = 1;
      for(it= input[s].begin();it != input[s].end();it++){
        string temp = *it;
        if(temp.length()>y.length() && temp.substr(temp.length()-y.length())==y){flag = 0;break; }
      } 
      if(!flag)continue;
      for(int k=1;k<y.length();k++){
        if(input[s].find(y.substr(k))!= input[s].end())
          input[s].erase(input[s].find(y.substr(k)));
      }
      input[s].insert(y);
    }
  }
  cout<<input.size()<<endl;
  map< string, set< string > >::iterator it;
  for(it = input.begin();it != input.end();it++){
    set< string > x = it->second;
    cout<<it->first<<" "<<x.size()<<" ";
    set< string >::iterator it2;
    for(it2 = x.begin(); it2 != x.end();it2++)cout<<*it2<<" ";
    cout<<endl;   
  }
}
