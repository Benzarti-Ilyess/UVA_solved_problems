#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
typedef vector<int> vi;
class UnionFind                                                // OOP style
{
private:
    vi p, rank, setSize;                       // remember: vi is vector<int>
    int numSets;
public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};
int main()
{ std::ios::sync_with_stdio(false);//accelerate cin and cout
    //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    int tc,numberofcomputers,node1,node2;
    cin>>tc;
    char c,temp;
    while(tc--)
    {
        int correct=0,notcorrect=0;
        cin>>numberofcomputers;
        UnionFind ufds(numberofcomputers+1);
        string s;
        getline(cin,s);
        while(getline(cin,s) && s!="")
        {sscanf(s.c_str(),"%c %d %d",&c,&node1,&node2);
            if(c=='c')
            {
                ufds.unionSet(node1,node2);

            }
            else if(c=='q')
            {
                if(ufds.isSameSet(node1,node2))
                    correct++;
                else
                    notcorrect++;
            }


        }






        //printf("%d,%d\n\n",correct,notcorrect);
    cout<<correct<<","<<notcorrect<<endl;
    if(tc)
    cout<<endl;


    }
    return 0;
}
