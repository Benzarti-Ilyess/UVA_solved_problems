#include <iostream>
#include <cmath>
#include <cstdlib>
#define inf 500000000

using namespace std;

int N, B, H, W;
int main ()
{//freopen("test.txt","r",stdin);
    while(scanf("%d %d %d %d", &N, &B, &H, &W)!=EOF){
        int cost = inf;
        for(int i = 0; i < H; i++){
            int P, k ;
            scanf("%d",&P);
            for(int j = 0; j < W; j++){
                scanf("%d",&k);
                if(k >= N && N*P < cost) cost = N*P;
            }
        }
        if(cost <= B) printf("%d\n",cost);
        else{
            printf("stay home\n");
        }
    }
    return 0;

}
