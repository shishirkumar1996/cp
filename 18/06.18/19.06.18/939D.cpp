#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >
#define vpr vector< pr >

using namespace std;

int main(){
  int n;
  cin>>n;
  
  string a,b;
  cin>>a>>b;
  
  vii process(26);
  for(int i =0;i<n;i++) if(a[i] != b[i]) {
    process[a[i]-'a'].push_back(b[i]-'a');
    process[b[i]-'a'].push_back(a[i]-'a');
  }
  
  bool visited[26];
  vpr output;
  for(int i = 0;i<26;i++) visited[i] = false;
  for(int i =0;i<26;i++){
    if(!process[i].size()) continue;
    stack< int > temp;
    temp.push(i);
    visited[i] = true;
    while(temp.size()){
      int top = temp.top();
      temp.pop();
      for(int j = 0;j<process[top].size();j++){
        int child = process[top][j];
        if(!visited[child]){
          output.push_back(make_pair(top,child));
          temp.push(child);
          visited[child] = true;
        }
      }
    }
  }
  cout<<output.size()<<endl;
  for(int i= 0;i<output.size();i++)
    cout<<(char)(output[i].first+'a')<<" "<<(char)(output[i].second+'a')<<endl;

}
