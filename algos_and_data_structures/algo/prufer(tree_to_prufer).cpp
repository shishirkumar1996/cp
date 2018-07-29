#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
 
using namespace std;
 
int main()
{
	int i, j, v, e, min, x;
	cout<<"Enter the number of vertexes of the tree: ";
	cin>>v;
 
	e = v-1;
	int edge[e][2], deg[v+1] = {0};
 
	// Enter the vertex pairs which have an edge between them.
	for(i = 0; i < e; i++){
		cin>>edge[i][0]>>edge[i][1];
		deg[edge[i][0]]++;deg[edge[i][1]]++;
	}
 
	cout<<"\nThe Prufer code for the given tree is: { ";
	for(i = 0; i < v-2; i++){
		min = 10000;
		for(j = 0; j < e; j++){
			if(deg[edge[j][0]] == 1)if(min > edge[j][0]){min = edge[j][0];x = j;}
			if(deg[edge[j][1]] == 1){if(min > edge[j][1]){min = edge[j][1];x = j;}
			}
		}
		deg[edge[x][0]]--;deg[edge[x][1]]--;
 
		if(deg[edge[x][0]] == 0)cout<<edge[x][1]<<" ";
		else cout<<edge[x][0]<<" ";	
	}
	cout<<"}"<<endl;
	return 0;
}
