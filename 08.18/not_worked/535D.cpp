#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM (lld)(1e6+7)
#define MOD (lld)(1e9+7)
#define vi vector< int >

using namespace std;

int lps[NUM];

void computeLPSArray(string pat){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    int M = pat.length();
    while (i < M){
        if (pat[i] == pat[len]){ len++;lps[i] = len;i++;}
        else{
          if (len != 0) len = lps[len-1];
          else{ lps[i] = 0;i++;}
        }
    }
}

int main(){
  
  faster
  int n,m;
  cin>>n>>m;
  string text;
  cin>>text;
  computeLPSArray(text);
  
  int check[text.length()-1];
  for(int i=0;i<text.length();i++)check[i] = 0;
  int index = text.length()-1;
  while(lps[index]){ check[lps[index]] = 1;index = lps[index]; }
  
  int init = n;
  vi process(m);
  for(int i=0;i<m;i++){cin>>process[i];process[i]--;}
  
  for(int i=0;i<m;i++){
    if(i==0|| process[i] - process[i-1]>=text.length()) init = init-text.length();
    else {
      int y = text.length()-(process[i]-process[i-1]);
      if(!check[y]){cout<<0<<endl;return 0;}
      init = init-(text.length()-y);
    }
  }  
  
  lld ans = 1;
  for(int i=0;i<init;i++)ans = (ans*26)%MOD;
  cout<<ans<<endl;
}
