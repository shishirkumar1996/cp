#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster  
  int k;
  cin>>k;
  string input;
  cin>>input;
  
  string temp = input;
  
  for(int i=1;i<k;i++) input += temp;
  set< int > process[26];
  
  bool deleted[input.length()];
  
  for(int i=0;i<input.length();i++){
    process[input[i]-'a'].insert(i);
    deleted[i] = false;
  }
  
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int p;char c;
    cin>>p>>c;  
    set< int >::iterator it = next(process[c-'a'].begin(),p-1);
    int x = *it;
    deleted[x] = true;
    process[c-'a'].erase(it);
  }
  
  for(int i=0;i<input.length();i++) if(!deleted[i])cout<<input[i];
  cout<<endl;
}
