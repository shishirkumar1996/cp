#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n,p;
  cin>>n>>p;

  string input;
  cin>>input;
  for(int i=n-1;i>=0;i--){
    int j;
    int flag = 0;
    for(j=1+input[i]-'a';j<p;j++){
      char c = 'a'+j;
      if((i-1>=0 && input[i-1]==c)||(i-2>=0 && input[i-2]==c))continue;
    else {flag = 1;break;}
    }
    if(flag){
      input[i] = j+'a';
      for(int k=i+1;k<n;k++){
        int temp = input[k]-'a';
        for(int l=0;l<p;l++){
          char ct = 'a'+l;
          if((k-1>=0 && input[k-1]==ct)||(k-2>=0 && input[k-2]==ct))continue;
          else{input[k]=ct;break;}
        }
      }  
      cout<<input<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;

}
