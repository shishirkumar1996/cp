#include<bits/stdc++.h>
#define vi vector< int >
#define st set< int >
#define vst vector< st >
#define NUM 100

using namespace std;


vst input(NUM);
vi output;
int n; //number of sets;
int cost[NUM];
int output_size; // size of the sets in the output

st difference(st a,st b){
  st output;
  st::iterator it;
  for(it = a.begin();it != a.end();it++)if(!b.count(*it)) output.insert(*it);
  return output;
}

st st_union(st a,st b){
  st::iterator it;
  for(it = b.begin();it!=b.end();it++) a.insert(*it);
  return a;
}

void set_cover(){
  st cover;
  int index = 0;
  while(index != -1){
    double val = INT_MAX;
    index = -1;
    for(int i=0;i<n;i++){
      st process = difference(input[i],cover);
      int size = (int)process.size();
      if(size==0)continue;
      if(cost[i]*1.0/size<val){val = cost[i]*1.0/size;index = i;}
    }
    if(index == -1)return;
    cover = st_union(cover,input[index]);
    output.push_back(index);
  }
}

int main(){
  
  n = 5;
  input[0].insert(1);input[0].insert(2);
  input[1].insert(2);input[1].insert(3);input[1].insert(4);input[1].insert(5);
  input[2].insert(6);input[2].insert(7);input[2].insert(8);input[2].insert(9);input[2].insert(10);input[2].insert(11);input[2].insert(12);input[2].insert(13);
  input[3].insert(1);input[3].insert(5);input[3].insert(7);input[3].insert(9);input[3].insert(11);input[3].insert(13);
  input[4].insert(2);input[4].insert(4);input[4].insert(6);input[4].insert(8);input[4].insert(10);input[4].insert(12);input[4].insert(13);
  
  for(int i=0;i<n;i++) cost[i] = 5;
  
  set_cover();
  cout<<"The sets included are "<<endl;
  for(int i=0;i<output.size();i++)cout<<output[i]<<" ";
  cout<<endl;
}
  
