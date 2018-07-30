#include<bits/stdc++.h>

using namespace std;

string text;

int min(int a, int b){
    int res;
    if(b < a) res = b; else res = a;
    return res;
}
 
void findLongestPalindromicString(){
  int N = text.length();
  if(N == 0)return;
  N = 2*N + 1; //Position count
  int L[N]; //LPS Length Array
  L[0] = 0;L[1] = 1;
  int C = 1; //centerPosition 
  int R = 2; //centerRightPosition
  int i = 0; //currentRightPosition
  int iMirror; //currentLeftPosition
  int maxLPSLength = 0,maxLPSCenterPosition=0;
  int start = -1,end = -1,diff=-1;
       
  for (i = 2; i < N; i++) {
    iMirror  = 2*C-i;
    L[i] = 0;
    diff = R - i;
    if(diff > 0)L[i] = min(L[iMirror], diff);
  
    while ( ((i + L[i]) < N && (i - L[i]) > 0) && 
        ( ((i + L[i] + 1) % 2 == 0) || 
        (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))){ L[i]++; }

    if(L[i] > maxLPSLength){
      maxLPSLength = L[i];maxLPSCenterPosition = i;
    }
    
    if (i + L[i] > R) {C = i;R = i + L[i];}
  }
  start = (maxLPSCenterPosition - maxLPSLength)/2;
  end = start + maxLPSLength - 1;
  cout<<"LPS of string "<<text<<" is :";
  for(i=start; i<=end; i++) printf("%c", text[i]);
  printf("\n");
}

int main(int argc, char *argv[])
{
  cin>>text; 
  findLongestPalindromicString();
  return 0;
}
