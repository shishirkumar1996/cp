#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >

using namespace std;

int compare(string a,string b){

  lld a_s=0,b_s=0,a_h=0,b_h=0;
  for(int i = 0;i<a.size();i++) if(a[i]=='s')a_s++; else a_h++;
  for(int i = 0;i<b.size();i++) if(b[i]=='s') b_s++; else b_h++;

  return a_s*b_h > b_s*a_h;
}


int main(){

  int n;
  cin>>n;
  
  vs input(n);
  for(int i=0;i<n;i++) cin>>input[i];
  sort(input.begin(),input.end(),compare);
  
//  cout<<endl;
//  for(int i=0;i<n;i++)cout<<input[i]<<endl;
 
 
  int num_h = 0;
  lld ans = 0;
  int counter = 0;
  for(int i= 0;i<n;i++){
    for(int j= 0;j<input[i].size();j++){
      counter++;
      if(input[i][j]=='h'){num_h++; ans+=(counter-num_h);}
    }
  }
  cout<<ans<<endl;
}
