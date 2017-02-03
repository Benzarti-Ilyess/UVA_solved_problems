#include <iostream>
#include <vector>
using namespace std;
int count_squares(const vector< vector<char> >&big_square,
  const vector< vector<char> >&small_square)
{
  int count = 0;
  size_t N = big_square.size(), n = small_square.size();
  for (size_t i = 0; i < N - n + 1; i++)
    for (size_t j = 0; j < N - n + 1; j++) {
      size_t k, l;
      for (k = 0; k < n; k++) {
        for (l = 0; l < n; l++)
          if (big_square[i + k][j + l] != small_square[k][l])
            break;
        if (l < n)
          break;
      }
      if (k == n && l == n)
        count++;
    }
  return count;
}

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int N,n;
char c;
while(scanf("%d %d",&N,&n),(N||n))
{ vector<int> counts(4,0);
vector <vector<char> > V(N,vector<char>(N, '0'));
vector <vector<char> > v(n,vector<char>(n, '0'));
for(int i=0;i<N;i++)
{ for(int j=0;j<N;j++)
{cin>>c;
V[i][j]=c;}}

for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{cin>>c;
v[i][j]=c;
}}
counts[0]=count_squares(V,v);
for(int k=1;k<=3;k++)
{
// Transpose the v
    for ( int i = 0; i < n; i++ ) {
        for ( int j = i + 1; j < n; j++ ) {
            char tmp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = tmp;
        }
    }

 // Swap the columns
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n/2; j++ ) {
            char tmp = v[i][j];
            v[i][j] = v[i][n-1-j];
            v[i][n-1-j] = tmp;
        }
    }

counts[k]=count_squares(V,v);

}
for(int i=0;i<3;i++)
cout<<counts[i]<<" ";
cout<<counts[3]<<endl;
}


    return 0;
}
