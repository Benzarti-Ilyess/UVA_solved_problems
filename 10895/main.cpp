#include <iostream>
#include <vector>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int m,n,r,p;
while(scanf("%d %d",&m,&n)!=EOF)
{int k=0;
vector <vector<int>> v(1000,vector<int>(1000,0));
vector <vector<int>> vi(1000,vector<int>(1000,0));
for(int i=0;i<m;i++)
{
scanf("%d",&r);
vector<int> rp(r);
for(int j=0;j<rp.size();j++)
{
scanf("%d",&p);
rp[j]=p;
}
for(int j=0;j<rp.size();j++)
{
scanf("%d",&p);
v[i][rp[j]-1]=p;
}

}
/*for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
cout<<v[i][j]<<" ";


}
cout<<endl;
}
cout<<endl;
cout<<endl;*/
     /*for ( int i = 0; i < m; i++ ) {
        for ( int j = i + 1; j < n; j++ ) {
            int tmp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = tmp;
        }
    }*/
     for (int i = 0; i<m; i++)
   for (int j = 0; j<n; j++)
     vi[j][i] =v[i][j];

   /*for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
cout<<vi[i][j]<<" ";


}
cout<<endl;
}
cout<<endl;
cout<<endl;
*/
printf("%d %d\n",n,m);
for(int i=0;i<n;i++)
{k=0;
vector<int> tp,tv;
for(int j=0;j<m;j++)
{
if(vi[i][j])
{k++;
tp.push_back(j);
tv.push_back(vi[i][j]);
}
}

if(k==0)
{
printf("0\n\n");
}
else
{
printf("%d",k);
for(int j=0;j<tp.size();j++)
{
printf(" %d",tp[j]+1);
}
printf("\n");
for(int j=0;j<tv.size()-1;j++)
{
printf("%d ",tv[j]);
}
printf("%d",tv[k-1]);
printf("\n");

}




}





}


return 0;}
