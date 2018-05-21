#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int vowel(char c){
  
  return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');

}


int main(){

  faster
  string input;
  cin>>input;
  input = "  "+input;
  
  int counter = 2;
  while(counter<input.size()){
    if(input[counter-1]==' '||input[counter-2] == ' '){
      counter++;
      continue;
    }
    if(!vowel(input[counter]) && !vowel(input[counter-1]) && !vowel(input[counter-2])){
      if(input[counter] != input[counter-1] || input[counter] != input[counter-2])
      {
//        cout<<counter<<endl;
        input = input.substr(0,counter)+" "+input.substr(counter);
        counter++;
      }
    }
    counter++;
  }

  input = input.substr(2);
  cout<<input<<endl;

}
