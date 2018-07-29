#include<bits/stdc++.h>
#define vi vector< int >

using namespace std;

vi prufer;
int n;//number of elements in prufer code;
 
void printTreeEdges()
{
    int vertices = n + 2;
    int vertex_set[vertices];
    for (int i=0; i<vertices; i++ )vertex_set[i]=0;
 
    for (int i=0; i<vertices-2; i++)vertex_set[prufer[i]-1] += 1;
    cout<<"\nThe edge set E(G) is :\n";
    int j = 0;
    for (int i=0; i<vertices-2; i++)
        for (j=0; j<vertices; j++)
            if (vertex_set[j] == 0){
                vertex_set[j] = -1;
                cout <<(j+1) <<" "<< prufer[i]<<endl;
                vertex_set[prufer[i]-1]--;
                break;
            }
 
    for (int i=0; i<vertices; i++ ){
        if(vertex_set[i] == 0 && j == 0 ){cout <<(i+1) << " ";j++;}
        else if (vertex_set[i] == 0 && j == 1 )cout<<(i+1)<<endl;
    }
}
 
int main()
{
    int pruf[] = {4, 1, 3, 4};
    n = 4;
    for(int i=0;i<4;i++)prufer.push_back(pruf[i]);
    printTreeEdges();
    return 0;
}
