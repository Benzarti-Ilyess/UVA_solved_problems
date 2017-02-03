#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct info
{
string department,title,firstname,lastname,homeadress,homephone,workphone,campusbox;


};
bool cmp(info a,info b)
{
return a.lastname<b.lastname;


}
int main()
{
//freopen("test.txt","r",stdin);
//freopen("answer.txt","w",stdout);
int numbofdepartments;
scanf("%d",&numbofdepartments);
cin.ignore();
vector<info> v;
while(numbofdepartments--)
{ string ligne;
string field;
getline(cin,field);

while(getline(cin,ligne) && ligne!="")
{
info inf;
inf.department=field;
int k=0;
for(int i=0;ligne[i]!=',';i++)
{
inf.title+=ligne[i];
k=i;
}
for(int i=k+2;ligne[i]!=',';i++)
{
inf.firstname+=ligne[i];
k=i;
}
for(int i=k+2;ligne[i]!=',';i++)
{
inf.lastname+=ligne[i];
k=i;
}
for(int i=k+2;ligne[i]!=',';i++)
{
inf.homeadress+=ligne[i];
k=i;
}
for(int i=k+2;ligne[i]!=',';i++)
{
inf.homephone+=ligne[i];
k=i;
}
for(int i=k+2;ligne[i]!=',';i++)
{
inf.workphone+=ligne[i];
k=i;
}
for(int i=k+2;i<ligne.length();i++)
{
inf.campusbox+=ligne[i];
}

v.push_back(inf);


}



}
sort(v.begin(),v.end(),cmp);
for(int i=0;i<v.size();i++)
{ printf("----------------------------------------\n");
cout<<v[i].title<<" "<<v[i].firstname<<" "<<v[i].lastname<<endl;
cout<<v[i].homeadress<<endl;
cout<<"Department: "<<v[i].department<<endl;
cout<<"Home Phone: "<<v[i].homephone<<endl;
cout<<"Work Phone: "<<v[i].workphone<<endl;
cout<<"Campus Box: "<<v[i].campusbox<<endl;



}




    return 0;
}
