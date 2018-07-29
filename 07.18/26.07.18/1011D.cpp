#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main() {
    faster
    int index = 0;
    lld m;
    int n;
    scanf("%lld%d",&m,&n);
    vi incorrect;
    int response;
    while(index<n){
      printf("%d\n",1);
      fflush(stdout);
      scanf("%d",&response);
      if(response == -1){incorrect.push_back(index);}
      else if(response==0){fflush(stdout);return 0;}
      index++;
    }
    
    lld l = 1,r = m;
    
    while(true) {
      lld mid = (l+r)/2;
      printf("%lld\n",mid);
      fflush(stdout);
      scanf("%d",&response);
      if(response ==0){fflush(stdout);return 0;}
      else{
        int flag = 1;
        for(int i=0;i<incorrect.size();i++)if(index%n==incorrect[i]) flag = 0;
        
        if(response == 1){
        if(!flag) r = mid-1;else l = mid+1;
        } else if(response == -1){
        if(!flag) l = mid+1;else r = mid-1;
        }
      }
      index++;
    }

}
