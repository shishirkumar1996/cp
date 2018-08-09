#include <bits/stdc++.h>
#define lld long long int
#define NUM 200007
#define vi vector< lld >

using namespace std;
lld X[NUM],Y[NUM];
vi a;
 
void calcsubarray(lld x[], int n, int c){
    for (int i=0; i<(1<<n); i++){
        lld s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j)) s += a[j+c];
        x[i] = s;
    }
}
 
lld solveSubsetSum(int n, lld S){
    calcsubarray(X, n/2, 0);
    calcsubarray(Y, n-n/2, n/2);
 
    int size_X = 1<<(n/2);
    int size_Y = 1<<(n-n/2);
 
    sort(Y, Y+size_Y);
 
    lld max = 0;
 
    for (int i=0; i<size_X; i++){
        if (X[i] <= S){
            int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;
 
            if (p == size_Y || Y[p] != (S-X[i]))p--;
 
            if ((Y[p]+X[i]) > max)max = Y[p]+X[i];
        }
    }
    return max;
}
 
// Driver code
int main()
{
    lld arr[] = {3, 34, 4, 12, 5, 2};
    int n=6;
    for(int i=0;i<n;i++)a.push_back(arr[i]);
    lld S = 10;
    printf("Largest value smaller than or equal to given "
           "sum is %lld\n", solveSubsetSum(n,S));
    return 0;
}
