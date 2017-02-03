#include <iostream>

using namespace std;

int main()
{
int N;
int c=0;
while(scanf("%d",&N),N)
{if(c)
printf("\n");
c++;
int found=0;
for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
int abcde = fghij * N; // this way, abcde and fghij are at most 5 digits
int tmp, used = (fghij < 10000); // if digit f=0, then we have to flag it
tmp = abcde; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
tmp = fghij; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
if (used == (1<<10) - 1)
{// if all digits are used, print it
printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
found=1;
}
}
if(!found)
printf("There are no solutions for %d.\n",N);


}
    return 0;
}
