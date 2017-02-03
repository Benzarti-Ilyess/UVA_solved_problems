#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    int n,command,x;
    while(scanf("%d",&n)!=EOF)
    {
        bool is_stack=true,is_queue=true,is_priority_queue=true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while(n--)
        {
            scanf("%d %d",&command,&x);
            switch(command)
            {
            case 1:
                if(is_stack)
                    s.push(x);
                if(is_queue)
                    q.push(x);
                if(is_priority_queue)
                    pq.push(x);
                break;
            case 2:
                if(is_stack)
                {
                    if(s.empty() || s.top()!=x)
                        is_stack=false;
                    else
                        s.pop();
                }
                if(is_queue)
                {
                    if(q.empty() || q.front()!=x)
                        is_queue=false;
                    else
                        q.pop();
                }
                if(is_priority_queue)
                {
                    if(pq.empty() || pq.top()!=x)
                        is_priority_queue=false;
                    else
                        pq.pop();
                }
                break;



            }
        }
        if(is_stack && !is_queue && !is_priority_queue)
        printf("stack\n");
        else if(!is_stack && is_queue && !is_priority_queue)
        printf("queue\n");
        else if(!is_stack && !is_queue && is_priority_queue)
        printf("priority queue\n");
        else if(!is_stack && !is_queue && !is_priority_queue)
        printf("impossible\n");
        else
        printf("not sure\n");


    }
    return 0;
}
