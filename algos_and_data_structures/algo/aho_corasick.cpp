#include<bits/stdc++.h>
#define vs vector< string >
#define NUM 100007

using namespace std;

const int MAXS = 500; // max number of states in the matching machine
const int MAXC=26;   // max number of characters in the input alphabet  

vs arr(NUM);
string text;
int k; //number of strings in the pattern
int out[MAXS],f[MAXS];
int g[MAXS][MAXC]; //trie

int build_matching_machine(){
  memset(out,0,sizeof(out));
  memset(g,-1,sizeof(g));
  
  
  int states = 1;
  for(int i=0;i<k;++i){
    string word = arr[i];
    int cur_state = 0;
    for(int j=0;j<word.size();j++){
      int ch = word[j] - 'a';
      if(g[cur_state][ch]==-1)g[cur_state][ch] = states++;
      cur_state = g[cur_state][ch];  
    }
    out[cur_state] |= (1<<i);
  }
  for(int ch = 0;ch<MAXC;ch++) if(g[0][ch] == -1) g[0][ch] = 0;
  memset(f,-1,sizeof(f));
  
  queue< int > q;
  for(int ch =0;ch<MAXC;ch++)
    if(g[0][ch] != 0){f[g[0][ch]]=0;q.push(g[0][ch]);}
    
  while(q.size()){
    int state = q.front();
    q.pop();
    for(int ch =0;ch<=MAXC;ch++){
      if(g[state][ch] != -1){
        int failure = f[state];
        while(g[failure][ch] == -1) failure = f[failure];
        
        failure = g[failure][ch];
        f[g[state][ch]] = failure;
        
        out[g[state][ch]] |= out[failure];
        q.push(g[state][ch]);
      }
    }
  }    
  return states; 
}

int find_next_state(int cur_state,char input){
  int ans = cur_state;
  int ch = input-'a';
  while(g[ans][ch] == -1) ans = f[ans];
  
  return g[ans][ch];
}

void search_words(){
  build_matching_machine();
  int cur_state = 0;
  for(int i=0;i<text.size();i++){
    cur_state = find_next_state(cur_state,text[i]);
    if(out[cur_state] == 0)continue;
    for(int j=0;j<k;j++){
      if(out[cur_state] & (1<<j))
        cout<<"Word "<<arr[j]<<" appears from "<<i-arr[j].size()+1<<" to "<<i<<endl;
    }
  }
}
int main(){
  string x[] = {"he", "she", "hers", "his"};
  text = "ahishers";
  k = 4;
  for(int i=0;i<4;i++)arr[i] = x[i];

  search_words();

  return 0;
}
