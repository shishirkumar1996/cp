#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define vi vector< int >

using namespace std;

int main(){

  int n,p;
  cin>>n>>p;
  
  string input;
  cin>>input;
  
  int correct = 0;
  for(int i= 0;i<p;i++){
    int flag = -1;
    for(int j= i;j<n;j+=p){
      if(input[j]!='.'){
        if(flag == -1) flag = (input[j]-'0');
        else if(flag != -1 && ((input[j]-'0')!= flag)) {
          correct = 1;
        } 
      }
    }
    if(flag != -1){
      for(int j= i;j<n;j+=p) if(input[j] == '.') {
        input[j] = ('1'-flag);correct = 1;
      }  
    } else{
      input[i] = '0';    
    for(int j = i+p;j<n;j+=p) {input[j] = '1',correct = 1;}
    }
  }
  if(correct)
  cout<<input<<endl;  
  else
  cout<<"No"<<endl;
}
