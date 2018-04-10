#include<bits/stdc++.h>
#include<map>

using namespace std;



void calc(){
  
  int n,m;
  // n is the number of words in the lecture
  // m is the number of words in each of the language
  
  map<string,string> second;
  map<string,string> first;
  
  cin>>n>>m;
  
  
  for(int i = 0;i<m;i++){
    string a,b;
    cin>>a>>b;
    second[a] = b;
    second[b] = a;
  }
  
  for(int i = 0;i<n;i++){
    string inp;
    cin>>inp;
    if(second[inp]=="") //this means that string is in second language
      cout<<(first[inp].length()<=inp.length()?first[inp]:inp)<<" ";
    else
      cout<<(inp.length()<=second[inp].length()?inp:second[inp])<<" ";
  }
  cout<<endl;  

}



int main(){

  calc();

}
