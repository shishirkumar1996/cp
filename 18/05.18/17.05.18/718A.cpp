#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;


int main(){
  
  lld n,t;
  cin>>n>>t;
  
  char input[n+1];
  input[0] = '0';
  for(int i = 1;i<=n;i++) cin>>input[i];
  
  
  lld p = 1;
  while(input[p]!='.') p++;
  p++;
  
  while(p<=n && input[p]-'0' < 5) p++;
  
  if(p==n+1){
    
    for(int i = 1;i<=n;i++)
      cout<<input[i];
    cout<<endl;  
    return 0;
  }
  for(lld i = 1;i<=t;i++){
    
    
    if(input[p]-'0' < 5)
      break;
    
    input[p] = '\0';
    if(input[p-1] != '.') input[p-1] += 1;
    p = p-1;
  
    if(input[p] == '.'){
//      cout<<p<<endl;
      input[p] = '\0';
      p--;
      while(p >= 0){
        if(input[p] == '9')
          input[p] = '0';
        else
        {
          input[p] += 1;
          break;
        }
        p--;
      }
      break;
    }  
    
  }
  
  if(input[0] != '0')
    cout<<input[0];
  int index = 1;
  while(input[index] != '\0'){
    cout<<input[index];
    index++;
  }
  cout<<endl; 
}
