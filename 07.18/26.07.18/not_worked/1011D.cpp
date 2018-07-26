#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    faster
    int p = 0;
    int index = 1;
    lld m;
    int n;
    scanf("%lld%d",&m,&n);
    int response;
    while(p==0){
      printf("%d\n",1);
      fflush(stdout);
      scanf("%d",&response);
      if(response == -1){p=index;}
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
      else if(response == 1){
        if(index%n==p) r = mid-1;
        else l = mid+1;
      } else if(response == -1){
        if(index%n==p) l = mid+1;
        else r = mid-1;
      }
      index++;
    }

}
