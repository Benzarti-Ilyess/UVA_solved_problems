#include<cstdio>
#include<bitset>

using namespace std;

long convert_endian(long x){
    bitset<32> b(x);
    long ret = 0;
    for (int j=0; j<32; j++) if (b[j]) ret |= 1<<(3-j/8)*8+(j%8);
    return ret;
}

int main(){
    long x;
    while(scanf("%ld", &x)==1) printf("%ld converts to %ld\n",
        x, convert_endian(x));
    return 0;
}
