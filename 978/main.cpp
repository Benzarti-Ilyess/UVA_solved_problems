#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int tc,b,sg,sb,x,val,minimal;
scanf("%d",&tc);
while(tc--)
{

multiset<int> mg,mb;
multiset<int>::iterator it1,it2;
multiset<int>::reverse_iterator it;
scanf("%d %d %d",&b,&sg,&sb);
for(int i=0;i<sg;i++)
{
scanf("%d",&x);
mg.insert(x);
}
for(int i=0;i<sb;i++)
{
scanf("%d",&x);
mb.insert(x);
}
while(mg.size()>0 && mb.size()>0)
{
vector<int> storeg,storeb;
for(int i=0;i<b;i++)
{
it1=mb.end();
it2=mg.end();
it1--;
it2--;
if(*it1>*it2)
{
val=*it1-*it2;
mb.erase(it1);
mg.erase(it2);
storeb.push_back(val);

}
else if(*it1<*it2)
{
val=*it2-*it1;
mg.erase(it2);
mb.erase(it1);
storeg.push_back(val);

}
else
{
mb.erase(it1);
mg.erase(it2);

}

if(mb.empty() || mg.empty())
break;
}
for(int i=0;i<storeb.size();i++)
mb.insert(storeb[i]);
for(int i=0;i<storeg.size();i++)
mg.insert(storeg[i]);




}
/*for(it=mg.begin();it!=mg.end();it++)
cout<<*it<<" ";
cout<<endl;
for(it=mb.begin();it!=mb.end();it++)
cout<<*it<<" ";
cout<<endl;*/
if(mg.empty() && mb.empty())
cout<<"green and blue died"<<endl;
else if(mg.size()>0)
{ cout<<"green wins"<<endl;
for(it=mg.rbegin();it!=mg.rend();it++)
cout<<*it<<endl;
}
else if(mb.size()>0)
{ cout<<"blue wins"<<endl;
for(it=mb.rbegin();it!=mb.rend();it++)
cout<<*it<<endl;
}
if(tc>0)
cout<<endl;


}

    return 0;
}
