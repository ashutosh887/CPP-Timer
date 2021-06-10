#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>

using namespace std;

int hr=0;
int mins=0;
int sec=0;

void display_clock(){
    system("cls");
    system("COLOR A0");

    cout<<setfill(' ')<<setw(57)<<"TIMER \n"<<endl;
    cout<<setfill(' ')<<setw(65)<<"***************************"<<endl;
    cout<<setfill(' ')<<setw(40)<<"| "<<hr<<" hr";
    cout<<"|"<<setfill(' ')<<setw(5)<<mins<<" min";
    cout<<"|"<<setfill(' ')<<setw(5)<<sec<<" sec"<<"|"<<endl;
    cout<<setfill(' ')<<setw(65)<<"***************************"<<endl;
}

void timer(int time_h,int time_m,int time_s)
{
    while(true)
    {
        display_clock();
        sleep(1);
        sec++;

        if(sec==61){
        mins++;
        sec=1;
    }

        if(mins==60)
        {
            hr++;
            mins=0;
        }

        if(sec==time_s)
        {
            if(mins==time_m)
            {
                if(hr==time_h)
                {
                system("cls");
                system("color 47");
                cout<<setfill(' ')<<setw(57)<<"STOP!!!! \n"<<"\a"<<endl;

                break;
                }
            }
        }
    }
}

int main()
{
    system("color E0");

    string ans;
    int time_h,time_m,time_s;

    cout<<"...Set Your Timer...\n"<<endl;

    cout<<"Enter the Hours, Minutes and Seconds for which you want to Set the Timer...\n"<<endl;
    cout<<"\t* Enter the Hours => \t";
    cin>>time_h;
    cout<<"\t* Minutes (00-59) => \t";
    cin>>time_m;
    cout<<"\t* Seconds (00-59) => \t";
    cin>>time_s;

    cout<<"\nYou want to Set the Timer for \t"<<time_h<<" Hours "<<time_m<<" Minutes "<<time_s<<" Seconds \n"<<endl;

    cout<<"\nPress Key Y to Start the Timer ";
    cin>>ans;


    if(ans=="Y" || ans=="y")
    {
        timer(time_h,time_m,time_s);
    }
    else
        cout<<"Invalid Input!!";

    return 0;
}

