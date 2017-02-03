#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    int n,x;
    while(scanf("%d",&n),n)
    {
        vector<int> v;
        priority_queue<int,vector<int>,greater<int>> pq;
        int total=0,cost=0;
        while(n--)
        {
            scanf("%d",&x);
            pq.push(x);
        }
        while(pq.size()>1)
        {
            total=pq.top();
            pq.pop();
            total+=pq.top();
            pq.pop();
            cost+=total;
            pq.push(total);

        }
        printf("%d\n",cost);



    }
    return 0;
}
