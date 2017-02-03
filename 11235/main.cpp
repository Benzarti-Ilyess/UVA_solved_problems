#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

class SegmentTree           // the segment tree is stored like a heap array
{
private:
    vi st, A;            // recall that vi is: typedef vector<int> vi;
    int n;
    int left (int p)
    {
        return p << 1;    // same as binary heap operations
    }
    int right(int p)
    {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R)                             // O(n log n)
    {
        if (L == R)                            // as L == R, either one is fine
            st[p] = L;                                         // store the index
        else                                  // recursively compute the values
        {
            build(left(p) , L              , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R          );
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j)                    // O(log n)
    {
        if (i >  R || j <  L) return -1; // current segment outside query range
        if (L >= i && R <= j) return st[p];               // inside query range

        // compute the min position in the left and right part of the interval
        int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
        int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

        if (p1 == -1) return p2;   // if we try to access segment outside query
        if (p2 == -1) return p1;                               // same as above
        return (A[p1] >= A[p2]) ? p1 : p2;
    }          // as as in build routine

    int update_point(int p, int L, int R, int idx, int new_value)
    {
        // this update code is still preliminary, i == j
        // must be able to update range in the future!
        int i = idx, j = idx;

        // if the current interval does not intersect
        // the update interval, return this st node value!
        if (i > R || j < L)
            return st[p];

        // if the current interval is included in the update range,
        // update that st[node]
        if (L == i && R == j)
        {
            A[i] = new_value; // update the underlying array
            return st[p] = L; // this index
        }

        // compute the minimum pition in the
        // left and right part of the interval
        int p1, p2;
        p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
        p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

        // return the pition where the overall minimum is
        return st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vi &_A)
    {
        A = _A;
        n = (int)A.size();              // copy content for local usage
        st.assign(4 * n, 0);            // create large enough vector of zeroes
        build(1, 0, n - 1);                                  // recursive build
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j);    // overloading
    }

    int update_point(int idx, int new_value)
    {
        return update_point(1, 0, n - 1, idx, new_value);
    }
};
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    int n,q,a,l,r;
    while(scanf("%d %d",&n,&q),n)
    {
        vector<int> v,v1;
        map<int,int> m;
        map<int,pair<int,int>> m1;
        int number=0,first=0;
        scanf("%d",&a);
        v.push_back(a);
        m[a]++;
        number=a;
        for(int i=1; i<n; i++)
        {
            scanf("%d",&a);
            if(a!=number)
            {
                m1[number]=make_pair(first,i-1);
                first=i;
                number=a;
            }
            v.push_back(a);
            m[a]++;

        }
        m1[number]=make_pair(first,n-1);

        for(int i=0; i<v.size(); i++)
            v1.push_back(m[v[i]]);
        SegmentTree st(v1);
        while(q--)
        {
            scanf("%d %d",&l,&r);
            l--;
            r--;
            if(v[l]==v[r])
            printf("%d\n",r-l+1);
            else if(r-l==0)
                printf("1\n");
            else
            {

                int freqinterval1=-1,freqinterval2=-1,freqinterval3=-1,maxi=-1;
                freqinterval1=m1[v[l]].second-l+1;
                freqinterval3=r-m1[v[r]].first+1;
                if(m1[v[l]].second+1 < m1[v[r]].first-1)
                    freqinterval2=v1[st.rmq(m1[v[l]].second+1,m1[v[r]].first-1)];
                maxi=max(freqinterval3, freqinterval1);
                maxi=max(maxi,freqinterval2);
                printf("%d\n",maxi);



            }
        }
    }


    return 0;
}
