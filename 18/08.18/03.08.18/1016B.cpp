#include<bits/stdc++.h>
#define pr pair< int,int >
#define NUM 100007 
#define vi vector< int > 
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std; 
 
int lps[NUM]; 
int M,N;
map< int,int > found;
 
void computeLPSArray(string pat);


void KMPSearch(string pat,string txt){
    computeLPSArray(pat);
    int i = 0,j  = 0;
//    for(int x=0;x<M;x++)cout<<lps[x]<<endl;
    while (i < N){
      if (pat[j] == txt[i]){ j++;i++; }
      if (j == M){
        found[i-j]++;
//        cout<<"find pattern at index "<<i-j<<endl;
        j = lps[j-1];
      } else if (i < N && pat[j] != txt[i]){
        if (j != 0) j = lps[j-1]; else i = i+1;
      }
    }
}
 
void computeLPSArray(string pat){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M){
        if (pat[i] == pat[len]){ len++;lps[i] = len;i++;}
        else{
          if (len != 0) len = lps[len-1];
          else{ lps[i] = 0;i++;}
        }
    }
}
 
int main()
{
    faster
    int q;
    string txt,pat;
    cin>>N>>M>>q>>txt>>pat;
    KMPSearch(pat, txt);
    int num[N+1];
    for(int i=0;i<=N;i++)num[i] = 0;
    for(int i=0;i<N;i++){
      num[i] = (i==0)?0:num[i-1];
      if(found[i])num[i]++;
    }   
    for(int i=0;i<q;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      if(b-a+1<M)cout<<0<<endl;
      else{
        int ans = num[b-M+1]-((a==0)?0:num[a-1]);
        cout<<ans<<endl;  
      }
    }   
    return 0;
}
