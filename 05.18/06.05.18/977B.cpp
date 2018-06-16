#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);


using namespace std;



int main(){

  int a;
  string input;
  cin>>a>>input;
  
  map<string,int> gram;
  set< string > letters;
  
  for(int i=1;i<input.size();i++){
    string x = "";
    x = x+input[i-1]+input[i];
    if(gram[x]==0)
      letters.insert(x);
    gram[x]++;
  }

  set<string>::iterator it;
  string g;
  int max = 0;
  for(it = letters.begin();it != letters.end();it++)
    if(max<gram[*it]){
      max = gram[*it], g = *it;
    }
  cout<<g<<endl;

}
