#include<bits/stdc++.h>

#define lld long long int
#define vstr vector < string >

using namespace std;

lld convert(string num){
  lld x = 0;
  for(int i = 0;i<num.size()  ;i++)
    x = x*10+(num[i]-'0');
  return x;
}

void calc(int n,vstr input){

  double coordinates[n]; 
  map<double,int> ships;
 
  for(int i =0;i<n;i++){
    string val;
    lld a,b,c;
    for(int j = 1;j<input[i].size();j++){
      if(input[i][j]=='+'){
        a = convert(val);
        val = "";
        continue;
      } 
      else if(input[i][j] == ')'){
        b = convert(val);
        val = "";
        j++;
        continue;
      }
      else{
        string letter(1,input[i][j]);
        val += letter;
      }
    }
    c = convert(val);
    double x = (1.0*a+1.0*b)/(1.0*c);
    coordinates[i]= x;
    ships[x]++;
  }

  for(int i = 0;i<n;i++)
    cout<<ships[coordinates[i]]<<" ";
  cout<<endl;
}

int main(){

  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vstr input;
  input.resize(n);
  for(int i = 0;i<n;i++)
    cin>>input[i];
  
  calc(n,input);

}


