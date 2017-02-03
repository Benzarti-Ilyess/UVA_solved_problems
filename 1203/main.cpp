#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
char Register[10];
int Q_num,period;
priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> > pq;
while(scanf("%s",Register),strcmp(Register,"#"))
{
scanf("%d %d",&Q_num,&period);
pq.push(pair<int,pair<int,int>>(period,pair<int,int>(Q_num,period)));





}
/*while(!pq.empty())
{
cout<<pq.top().first<<" "<<pq.top().second<<endl;
pq.pop();

}*/
int k,val;
scanf("%d",&k);
for(int i=0;i<k;i++)
{ pair<int,pair<int,int>> pt=pq.top();
pq.pop();
printf("%d\n",pt.second.first);
pt.first+=pt.second.second;
pq.push(pt);



}
    return 0;
}
