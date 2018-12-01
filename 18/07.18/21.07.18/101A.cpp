#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int, char >

using namespace std;

int main(){

  string a;
  int n;
  cin>>a>>n;
  
  map< char, int > process;
  
  set< pr > temp;
  
  for(int i=0;i<a.length();i++){
    process[a[i]]++;
  }
  for(int i=0;i<26;i++){
    char x = 'a'+i;
    if(process[x])temp.insert(make_pair(process[x],x));
  }
  
  while(n && temp.size()){
    pr x = *(temp.begin());
    temp.erase(temp.begin());
    
    char ct = x.second;
    int num = x.first;
    process[ct] = max(0,num-n);
    n = max(0,n-num);
  }
  
  int num = 0;
  for(int i=0;i<26;i++) if(process[i+'a']) num++;
  cout<<num<<endl;
  for(int i=0;i<a.length();i++) if(process[a[i]]){cout<<a[i];process[a[i]]--;}
  cout<<endl;
}
