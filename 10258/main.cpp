#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
struct state
{
    int contestant=0;
    int problem=0;
    int time=0;
    char L='0';
};
struct output
{
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
   //freopen("test.txt","r",stdin);
    //freopen("answer.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    cin.ignore();
    string line;
    getline(cin,line);
    while(tc--)
    {
        vector<state> v;
        vector<state>::iterator iti;
        vector <output> vout;
        vector <output>::iterator ito;
        state inputstate;
        output outputstate;
        int k=0;
        while(getline(cin,line) && line!="" )
        {
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
        vector <vector<int>> problemsolved(10,vector<int>(101,0));
        vector <vector<int>> problemwrong(10,vector<int>(101,0));
//for(int i=0;i<vout.size();i++)
//problemsolved[0][i]=vout[i].contestant;
        /*for(int i=0;i<101;i++)
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

                    if(iti->L=='C' && !problemsolved[iti->problem][iti->contestant])
                    {
                        ito->numbofproblemssolved++;
                        ito->penalty+=iti->time;
                        problemsolved[iti->problem][iti->contestant]=true;


                    }
                    else if(iti->L=='I' && !problemsolved[iti->problem][iti->contestant])
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



        for(int i=0; i<vout.size(); i++)
            cout<<vout[i].contestant<<" "<<vout[i].numbofproblemssolved<<" "<<vout[i].penalty<<endl;
        if(tc)
        cout<<endl;


        /*for(int i=0;i<v.size();i++)
        cout<<v[i].contestant<<" "<<v[i].problem<<" "<<v[i].time<<" "<<v[i].L<<endl;
        */

    }


    return 0;
}
