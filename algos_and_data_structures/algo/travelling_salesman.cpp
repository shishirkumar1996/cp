#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

int n,start;
vii cities(NUM),state(NUM);

int tsp(int pos, int visited)
{ 
    if(visited == ((1 <<n) - 1)) return cities[pos][0];

    if(state[pos][visited] != INT_MAX) return state[pos][visited];
    for(int i = 0; i < n; ++i){
      if(i == pos || (visited & (1 << i)))continue;
      int distance = cities[pos][i] + tsp(i, visited | (1 << i));
      if(distance < state[pos][visited]) state[pos][visited] = distance;
    }
    return state[pos][visited];
}

int main()
{
    start = 0;
    n = 4;    
    int x[n][n] =     { { 0, 20, 42, 35 },
                        { 20, 0, 30, 34 },
                        { 42, 30, 0, 12 },
                        { 35, 34, 12, 0 }
                      };
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    cities[i].push_back(x[i][j]);

    for(int i=0;i<n;i++)
      for(int j=0;j<(1<<n)-1;j++) state[i].push_back(INT_MAX);

    cout << "minimum: " << tsp(start, 1) << endl;
    return 0;
}
