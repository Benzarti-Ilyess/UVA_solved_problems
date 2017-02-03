#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int n,coach;
while(scanf("%d",&n),n)
{
vector<int> B(n,0);
while(scanf("%d",&coach),coach)
{B[0]=coach;
for(int i=1;i<n;i++)
scanf("%d",&B[i]);
stack<int> station;
int currentcoach=1;
int target=0;
while(currentcoach<=n)
{
station.push(currentcoach);

while(!station.empty() && B[target]==station.top())
{
station.pop();
target++;
if(target>=n)
break;

}
currentcoach++;




}
if(station.empty())
printf("Yes\n");
else
printf("No\n");




}
printf("\n");





}
    return 0;
}


