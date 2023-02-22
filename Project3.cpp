#include<iostream>
#include<fstream>
using namespace std;
string name, branch;
double roll, semester;
int i,c=0,size;
main()
{
    ofstream f;
    ifstream g;
    f.open("Exam.txt",ios::app);

    int ch;
    string id,password,q[10],op1[10],op2[10],op3[10],op4[10],ans[10];
    cout<<"Enter 1 for TEACHER, 2 for STUDENT:";
    cin>>ch;
    
    if(ch==1)
    {
        cout<<"Enter ID and password:";
        cin>>id>>password;

        if(id=="SEED"&&password=="IT")
        {
            cout<<"Press 1 for question, 2 for pass and 3 for fail:";
            cin>>ch;

            if(ch==1)
            {
                ofstream f;
                int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
                f.open("Exam.txt");
                cout<<"Enter number of questions:";
                cin>>size;
                for(i=1;i<=size;i++)
                {
                    cout<<"Enter question number "<<i<<" :";
                    cin>>q[i];
                    cout<<"Enter the option 1:";
                    cin>>op1[i];
                    cout<<"Enter the option 2:";
                    cin>>op2[i];
                    cout<<"Enter the option 3:";
                    cin>>op3[i];
                    cout<<"Enter the option 4:";
                    cin>>op4[i];
                    cout<<"Enter answer:";
                    cin>>ans[i];
                    f<<q[i]<<" "<<op1[i]<<" "<<op2[i]<<" "<<op3[i]<<" "<<op4[i]<<" "<<ans[i]<<endl;
                }
                f.close();
            }
            

            if(ch==2)
            {
                ifstream x;
                x.open("Result.txt");
                while(1)
                {
                    x>>name>>roll>>branch>>semester>>c;
                    if(x.eof())
                    break;
                    if(c>=6)
                    {
                        cout<<name<<"\t"<<roll<<"\t"<<branch<<"\t"<<semester<<endl;
                    }
                }
                x.close();
            }

            else if(ch==3)
            {
                ifstream y;
                y.open("Result.txt");
                while(1)
                {
                    y>>name>>roll>>branch>>semester>>c;
                    if(y.eof())
                    break;
                    if(c<6)
                    {
                        cout<<name<<"\t"<<roll<<"\t"<<branch<<"\t"<<semester<<endl;
                    }
                }
                y.close();
            }
        }
        else
            {
                cout<<"INVALID ID, PASSWORD";
            }
    }

    else if(ch==2){

        //code1
                cout<<"Enter name, roll number, branch, semester:";
                cin>>name>>roll>>branch>>semester;
                ifstream g;
                cout<<"Student Section"<<endl;
                g.open("Exam.txt");
                while(1)
                { 
                    g>>q[i]>>op1[i]>>op2[i]>>op3[i]>>op4[i]>>ans[i];
                    if(g.eof())
                    {
                        break;
                    }        
                    string Ans;
                    cout<<"Question:"<<q[i]<<endl;
                    cout<<"1)"<<op1[i]<<endl;
                    cout<<"2)"<<op2[i]<<endl;
                    cout<<"3)"<<op3[i]<<endl;
                    cout<<"4)"<<op4[i]<<endl;
                    cout<<"Enter your answer:";
                    cin>>Ans;

                    if(Ans==ans[i])
                    {
                        c=c+1 ;
                    }
                }
                cout<<"Marks="<<c<<" out of "<<size;
                g.close();
                //code2
                ofstream z;
                z.open("Result.txt",ios::app);
                z<<name<<"\t"<<roll<<"\t"<<branch<<"\t"<<semester<<"\t"<<c<<endl;
                z.close();
    }

}