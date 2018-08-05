#include<bits/stdc++.h>
using namespace std;
#define MAXM 500500

int end[MAXM];
int next[27][MAXM];
int sz=0;

void insert(string &s){
  int v=0;
  for(int i=0;i<s.size();i++){
    int c=s[i]-'a';
    if(!next[c][v]) next[c][v]=++sz;
    v=next[c][v];
  }
  ++end[v];
}

bool search(string tmp){
  int v=0;
  for(int i=0;i<tmp.size();i++){
    int c=tmp[i]-'a';
    if(!next[c][v]) return false;
    v=next[c][v];
  }
  return end[v]>0;
}

int main(){
    for(int i=0;i<27;i++)for(int j=0;j<MAXM;j++)next[i][j] = 0;
    int n,m;
    cin>>n>>m;
    string key[n];
    for(int i=0;i<n;i++){ cin>>key[i];insert(key[i]); }
    
    string output[]={"N ","Y"};
    for(int i=0;i<m;i++){
      string a;cin>>a;
      cout<<output[search(a)]<<endl;
     }
}
