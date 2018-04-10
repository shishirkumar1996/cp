#include<bits/stdc++.h>

using namespace std;


bool check(string n){
  
  int num = 0;
  for(int i = 0;i<n.size();i++)
    num = num*10 + (n[i]-'0');
  if(num %8 ==0)
    return true;
  else
    return false;
}


string calc(string input){


  
  for(int i = 0;i< input.size();i++){
    string a = "";
    a += input[i];
    if(check(a))
      return a;
    for(int j = i+1;j<input.size();j++){
      string b = a+input[j];
      if(check(b))
        return b;
      for(int k= j+1;k<input.size();k++){
        string c = b+input[k];
        if(check(c))
          return c;
      }
    
    }
        
  }
  
  return "-1";

}

int main(){

  string input;
  cin>>input;
  string result = calc(input);
  if(result=="-1")
  {
    cout<<"NO"<<endl;
    return 0;
  }
  else {
    cout<<"YES"<<endl;
    cout<<result<<endl;
  }

}


