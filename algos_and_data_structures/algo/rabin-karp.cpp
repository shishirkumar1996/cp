#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define d 256

using namespace std;

void search(string pat, string txt,int q){
  
  int m = pat.length();
  int n= txt.length();
  int p=0; //hash value for pattern
  int t = 0;//hash value for txt
  int h = 1;
  
  for(int i=0;i<m-1;i++) h = (h*d)%q;
  
  for(int i=0;i<m;i++){ p = (d*p+pat[i])%q;t = (d*t+txt[i])%q;}
  
  for(int i=0;i<=n-m;i++){
    if(p==t){
      int j;
      for(j=0;j<m;j++) if(txt[i+j]!=pat[j]) break;
    if(j==m)cout<<" pattern  found at index "<<i<<endl;
    }
    
    if(i<n-m){
      t = (d*(t-txt[i]*h)+txt[i+m])%q;
      if(t<0) t = t+q;
    }
  }
}

int main(){
  string txt,pat;
  cin>>txt>>pat;
  int q = 101;    //prime number to calculate hash values
  search(pat,txt,q);
}
