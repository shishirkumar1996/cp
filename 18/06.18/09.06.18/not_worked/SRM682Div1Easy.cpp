#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >

using namespace std;

class SmilesTheFriendshipUnicorn{

  public:
    string hasFriendshipChain(int N,vi A,vi B){
      vii input(N);
      for(int i =0;i<A.size();i++){
        input[A[i]].push_back(B[i]);
        input[B[i]].push_back(A[i]);
      }
      
      for(int i= 0;i<N;i++){
        bool visited[N];
        for(int j = 0;j<N;j++) visited[j] = false;    
        stack< pr > dfs;
        dfs.push(make_pair(i,0));
        while(dfs.size()){
          pr top = dfs.top();
          dfs.pop();
          int vertex = top.first;
          int dist = top.second;
          if(dist==4)return "Yay!";
          visited[vertex] = true;
          for(int j = 0;j<input[vertex].size();j++){
            int child = input[vertex][j];
            if(!visited[child]) dfs.push(make_pair(child,dist+1)); 
          }
        }
      }
      return ":(";
    }
};

int main(){
  SmilesTheFriendshipUnicorn s;
  int size = 42;
  int x[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
  28,29,30,31,32,33,34,35,36,37,38,39,40,41};
  int y[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
  28,29,30,31,32,33,34,35,36,37,38,39,40,41,0};
  
  
  vi A,B;
  for(int i = 0;i<size;i++)A.push_back(x[i]),B.push_back(y[i]);

  cout<<s.hasFriendshipChain(42,A,B)<<endl;
}
