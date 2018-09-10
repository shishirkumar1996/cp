#include<bits/stdc++.h>
#define lld long long int
#define vs vector< string >
#define faster ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#include<string>

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  priority_queue< lld > sol;
  vs output;
  for(int i =0;i<n;i++){
  
    string s;
    int a;
    cin>>s;
    if(s == "removeMin"){
      if(!sol.size()){
        sol.push(-1);
        output.push_back("insert "+to_string(1));
      }
      sol.pop();
      output.push_back(s);            
    } else if(s== "insert"){
      cin>>a;
      output.push_back("insert "+to_string(a));
      sol.push(-a);
    }
      else if(s== "getMin"){
        cin>>a;
        while(sol.size() && -sol.top()< a){
          sol.pop();
          output.push_back("removeMin");
        }
        if(!sol.size()||(-sol.top()) > a){
          sol.push(-a);
          output.push_back("insert "+to_string(a));
        }
        output.push_back(s+" "+to_string(a));
      }
  }
  
  cout<<output.size()<<'\n';
  for(int i = 0;i<output.size();i++)
    cout<<output[i]<<'\n';

}
