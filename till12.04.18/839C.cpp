#include<bits/stdc++.h>

#define lld long long int
#define vi vector < int >
#define vii vector < vi >
#define pr pair < pair < int , double > , int >
using namespace std;



double calc(int n, vii input){
    
  double val = 0;
                       //point //probability // distance
  queue<  pr > points;
  points.push(make_pair(make_pair(1,1),0));
  
  bool visited[n+1];
  memset(visited,false,n+1);
  
  while(points.size()){
    pr front = points.front();
    points.pop();
    int pt = front.first.first;
    double probability = front.first.second;
    int dist = front.second;
    visited[pt] = true;
//    cout<<dist<<endl;
    val = val+dist*probability;
    float flag = 0;
    for(int i = 0;i<input[pt].size();i++)
      if(!visited[input[pt][i]])
        flag++;
    for(int i =0;i<input[pt].size();i++){
      if(!visited[input[pt][i]]){
        pr put = make_pair(make_pair(input[pt][i],probability/flag),1);
        points.push(put);
      }
    }
  }
  
  return val;    

}

int main(){
  
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  
  vii input;
  input.resize(n+1);
  for(int i = 1;i<n;i++){     // no of edges is one less than no of vertices
    int a,b;
    cin>>a>>b;        
    input[a].push_back(b);
    input[b].push_back(a);
  }  
  
  cout<<setprecision(10)<<calc(n,input)<<endl;

}


