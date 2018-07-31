#include <bits/stdc++.h>
using namespace std;
 
#define N 1000001
 
int visited[N];
 
int goesTo[N];
 
int dfs(int i){
    if (visited[i] == 1)return 0;
    visited[i] = 1;
    int x = dfs(goesTo[i]);
    return (x + 1);
}
 
int noOfTranspositions(int P[], int n){
    for (int i = 1; i <= n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++)goesTo[P[i]] = i + 1;
    int transpositions = 0;
    for (int i = 1; i <= n; i++) 
      if (visited[i] == 0) { int ans = dfs(i);transpositions += ans - 1;}
    
    return transpositions;
}
 
int main()
{
    int permutation[] = { 5, 1, 4, 3, 2 };
    int n = sizeof(permutation) / sizeof(permutation[0]);
    cout << noOfTranspositions(permutation, n)<<endl;
    return 0;
}
