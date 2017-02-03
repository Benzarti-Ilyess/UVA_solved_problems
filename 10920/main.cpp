#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void spiralPrint(int m, int n,int num,vector< vector<int> >&a)
{
    int i,j, k = 0, l = 0;
	//int a[m][n];
	int x=m;
	int y=n;
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
	if(x%2==0){
		while (k < m && l < n)
		{
			/* Print the first row from the remaining rows */
			for (i = l; i < n; ++i)
			{
				//printf("%d ", a[k][i]);
				a[k][i]=num;num--;
			}
			k++;

			/* Print the last column from the remaining columns */
			for (i = k; i < m; ++i)
			{
				//printf("%d ", a[i][n-1]);
				a[i][n-1]=num;--num;
			}
			n--;

			/* Print the last row from the remaining rows */
			if ( k < m)
			{
				for (i = n-1; i >= l; --i)
				{
				  //  printf("%d ", a[m-1][i]);
					a[m-1][i]=num;--num;
				}
				m--;
			}

			/* Print the first column from the remaining columns */
			if (l < n)
			{
				for (i = m-1; i >= k; --i)
				{
					//printf("%d ", a[i][l]);
					a[i][l]=num;--num;
				}
				l++;
			}
		}
	}
	else
	{
		while (k < m && l < n)
		{
			/* Print the last row from the remaining rows */
			if (k < m && l < n)
			{
				for (i = n-1; i >= l; --i)
				{
				  //  printf("%d ", a[m-1][i]);
					a[m-1][i]=num;--num;
				}
				m--;
			}
			/* Print the first column from the remaining columns */
			if (k < m && l < n)
			{
				for (i = m-1; i >= k; --i)
				{
					//printf("%d ", a[i][l]);
					a[i][l]=num;--num;
				}
				l++;
			}

			/* Print the first row from the remaining rows */
			if (k < m && l < n)
			{
				for (i = l; i < n; ++i)
				{
					//printf("%d ", a[k][i]);
					a[k][i]=num;num--;
				}
				k++;
			}
			/* Print the last column from the remaining columns */
			if (k < m && l < n){
				for (i = k; i < m; ++i)
				{
					//printf("%d ", a[i][n-1]);
					a[i][n-1]=num;--num;
				}
				n--;
			}

		}

	}
	/*for(i=0;i<x;++i){
		for(j=0;j<y;++j){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
}

int main()
{
int sz,p;
while(scanf("%d %d",&sz),(sz||p))
{
int line=-1,column=-1;
vector <vector<int> > a(sz,vector<int>(sz, 0));

spiralPrint(sz,sz,sz*sz,a);
/*for(int i=0;i<sz;++i){
		for(int j=0;j<sz;++j){
			printf("%d ",a[i][j]);
		}
		printf("\n");}*/
for(int i=0;i<sz;i++)
{
for(int j=0;j<sz;j++)
{
if(a[i][j]==p)
{line=i;
column=j;
break;
}

}
if(line!=-1 && column!=-1)
{
break;
}
}
cout<<line<<" "<<column<<endl;



}

return 0;
}
