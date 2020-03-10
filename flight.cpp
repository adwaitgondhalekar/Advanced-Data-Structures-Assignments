#include<iostream>
#include<iomanip>
#define max 100
using namespace std;

class flight
{
   int connect[max][max];
   float tof[max][max];
   float fuel[max][max];
   string cities[max];
   int no_of_cities;
   public:
   
   flight()
   {
      for(int i=0;i<max;i++)
         {
            for(int j=0;j<max;j++)
             {
             tof[i][j]=0;
             fuel[i][j]=0;
             connect[i][j]=0;
             }
         }
         no_of_cities=0;
   }
   void enter_data();
   void display();
};

void flight::enter_data()
{ 
   char conn;
   cout<<"ENTER THE NUMBER OF CITIES\n";
   cin>>no_of_cities;
   
   for(int i=0;i<no_of_cities;i++)
   {
       cout<<"ENTER THE NAME OF CITY"<<(i+1)<<":";
       cin>>cities[i];
       cout<<"\n";
   }
   
   cout<<"ENTER THE CONNECTIVITY DETAILS\n";
   for(int i=0;i<no_of_cities;i++)
      {
         for(int j=0;j<no_of_cities;j++)
            {
                if(i==j)
                continue;
                else
                {
                cout<<"CONNECTIVITY OF "<<cities[i]<<" WITH-"<<cities[j]<<endl;
                cin>>conn;
                if(conn=='y')
                  {
                   connect[i][j]=1;
                   cout<<"ENTER THE TOTAL FUEL REQUIRED(IN LITRES)\n";
                   cin>>fuel[i][j];
                   cout<<"ENTER THE TIME OF FLIGHT\n";
                   cin>>tof[i][j];
                  }
                }
            }
      } 
}
void flight::display()
{

     cout<<"DATA REGARDING DIRECT FLIGHTS IS GIVEN BELOW\n\n";
     for(int i=0;i<no_of_cities;i++)
        {
           cout<<cities[i]<<":"<<endl;
           for(int j=0;j<no_of_cities;j++)
               {
                   if(connect[i][j]==1)
                      cout<<"\t"<<cities[j]<<endl;
               }
        }
     cout<<"THE DATA OF VIA FLIGHTS IS GIVEN BELOW\n\n";
     for(int i=0;i<no_of_cities;i++)
        {
           cout<<cities[i]<<":"<<endl;
            for(int j=0;j<no_of_cities;j++)
               {
                  if(connect[i][j]==1)
                    {
                       for(int k=0;k<no_of_cities;k++)
                          {
                             
                             if(connect[j][k]==1 && k!=i)
                              {
                               cout<<"\t"<<cities[j]<<"-";
                               cout<<cities[k]<<endl;
                              }
                              
                          }
                    }
               }
        }
        
     cout<<"\n";               
    
}
int main()
{
    int ch,l=0;
    flight f;
    while(l==0)
       {
                  cout<<"1.ENTER THE CONNECTIVITY DATA\n";
                  cout<<"2.DISPLAY ALL THE CONNECTIVITY DATA\n";
                  cout<<"3.EXIT\n";
                  cout<<"ENTER YOUR CHOICE\n";
                  cin>>ch;
                  
                  switch(ch)
                    {
                        case 1: f.enter_data();
                                break;
                        case 2: f.display();
                                break;
                        case 3: l=1;
                     }
       }
 }
