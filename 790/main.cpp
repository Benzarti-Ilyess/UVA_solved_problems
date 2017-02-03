#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int timecount(string time)
{ int hours,minuts,countm;
    hours=time[0]-'0';
    minuts=(time[2]-'0')*10+time[3]-'0';
countm=hours*60+minuts;
return countm;

}
struct state
{
    int contestant=0;
    char problem=0;
    string time;
    char L='0';
};
struct output
{   //int ranking=0;
    int contestant=0;
    int numbofproblemssolved=0;
    int penalty=0;
};
bool cmp(output a,output b)
{
    if(a.numbofproblemssolved==b.numbofproblemssolved && a.penalty==b.penalty)
        return a.contestant<b.contestant;
    else if(a.numbofproblemssolved!=b.numbofproblemssolved)
        return a.numbofproblemssolved>b.numbofproblemssolved;
    else if(a.numbofproblemssolved==b.numbofproblemssolved)
        return a.penalty<b.penalty;

}

int main()
{
   freopen("test.txt","r",stdin);
    freopen("answer.txt","w",stdout);
    string line;
     vector <output> vout;
     vector <output>::iterator ito;
     vector<state> v;
        vector<state>::iterator iti;
        int k=0;
        int tc;
        scanf("%d",&tc);
        cin.ignore();
        getline(cin,line);
        while(tc--)
  {
  getline(cin,line);

  while(getline(cin,line) && line!="")

    {



        state inputstate;
        output outputstate;
            stringstream ss(line);
            ss>>inputstate.contestant>>inputstate.problem>>inputstate.time>>inputstate.L;
            v.push_back(inputstate);
            bool found=false;
            for(int i=0; i<vout.size(); i++)
            {
                if(inputstate.contestant==vout[i].contestant)
                {
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                vout.push_back(outputstate);
                vout[k].contestant=inputstate.contestant;
                k++;
            }




        }
        /*for(int i=0;i<vout.size();i++)
        cout<<vout[i].contestant<<" "<<vout[i].numbofproblemssolved<<" "<<vout[i].penalty<<endl;*/
        vector <vector<int>> problemsolved(100,vector<int>(300,0));
        vector <vector<int>> problemwrong(100,vector<int>(300,0));
for(int i=0;i<vout.size();i++)
problemsolved[0][i]=vout[i].contestant;
       /* for(int i=0;i<30;i++)
        {for(int j=0;j<vout.size();j++)
        {cout<<problemsolved[i][j]<<" ";
        }
        cout<<endl;
        }*/
        for(iti=v.begin(); iti!=v.end(); iti++)
        {
            for(ito=vout.begin(); ito!=vout.end(); ito++)
            {
                if(ito->contestant==iti->contestant)
                {

                    if(iti->L=='Y' && !problemsolved[iti->problem][iti->contestant])
                    {
                        ito->numbofproblemssolved++;
                        ito->penalty+=timecount(iti->time);
                        problemsolved[iti->problem][iti->contestant]=true;


                    }
                    else if(iti->L=='N' && !problemsolved[iti->problem][iti->contestant])
                    {
                        problemwrong[iti->problem][iti->contestant]++;
                    }
                    if(problemwrong[iti->problem][iti->contestant] && problemsolved[iti->problem][iti->contestant])
                    {
                        ito->penalty+=20;
                        problemwrong[iti->problem][iti->contestant]=0;
                    }

                }
            }


        }
        sort(vout.begin(),vout.end(),cmp);
printf("RANK TEAM PRO/SOLVED TIME\n");

int ranking=1;
        for(int i=0; i<vout.size(); i++)
       {if(vout[i].numbofproblemssolved)
        cout<<"   "<<ranking<<"   "<<vout[i].contestant<<"    "<<vout[i].numbofproblemssolved<<"          "<<vout[i].penalty<<endl;
        else
         cout<<"   "<<ranking<<"   "<<vout[i].contestant<<endl;



        if(!(vout[i].penalty==vout[i+1].penalty && vout[i].numbofproblemssolved==vout[i+1].numbofproblemssolved))
        ranking++;
        }

        /*for(int i=0;i<v.size();i++)
        cout<<v[i].contestant<<" "<<v[i].problem<<" "<<v[i].time<<" "<<v[i].L<<endl;
        */
cout<<endl;
}


    return 0;
}
