#include<bits/stdc++.h>


using namespace std;


int main(){

  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  
  
  string result = "/";
  for(int i = 0;i<n;i++){
    string query;
    cin>>query;
    string res = "";
    if(query=="cd"){
      string input;
      cin>>input;    
      
      
      for(int i = 0;i<input.size();i++){
        if(input[i]=='/'|| i==input.size()-1)
        {
          if(i==input.size()-1)
            res += input[i];
          if(res == "")
            result = "/";
          else  
          if(res != "..")
          {
            result += res+"/";
            res = "";
          }
          else if(res== "..")
          {
            res = "";
            int size = result.size()-2;
            while(result[size] != '/')
              size--;
            result = result.substr(0,size+1);
          }
        }
        else res += input[i];
      }
      
    }
    else if(query=="pwd"){
      cout<<result<<endl;
    }
    
  }



}
