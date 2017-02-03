#include <iostream>
#include<set>
#include<string>
#include <map>
#include <vector>
using namespace std;
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
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
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
    std::ios::sync_with_stdio(false);//accelerate cin and cout
    int tc;
    cin>>tc;
    while(tc--)
    {
        UnionFind ufds(100000);
        int f;
        map<string,int> m;
        cin>>f;
        string friend1,friend2;
        int c=1;
        while(f--)
        {
            cin>>friend1>>friend2;
            if(!m[friend1])
            {
                m[friend1]=c;
                c++;
            }
            if(!m[friend2])
            {
                m[friend2]=c;
                c++;
            }
            ufds.unionSet(m[friend1],m[friend2]);
            cout<<ufds.sizeOfSet(m[friend1])<<endl;
        }



    }
    return 0;
}
