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
   void book_flight();
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
void flight::book_flight()
{
     int s_index,d_index,ind_flag=0;
     string source,destination;
     
     cout<<"ENTER THE SOURCE CITY\n";
     cin>>source;
     
  
     cout<<"ENTER THE DESTINATION CITY\n";
     cin>>destination;
     
     for(int i=0;i<no_of_cities;i++)
       {
          if(cities[i]==source)
            s_index=i;
          else  if(cities[i]==destination)
            d_index=i;
       }

     /*cout<<"DATA REGARDING DIRECT FLIGHTS IS GIVEN BELOW\n\n";
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
        }*/
        
    
                    if(connect[s_index][d_index]==1)
                       {
                         cout<<"DIRECT FLIGHT AVAILABLE!!!!\n";
                         cout<<"Source- "<<source<<" Destination-"<<destination<<endl;
                         cout<<"Time of Flight -"<<tof[s_index][d_index]<<"hr(s)"<<endl;
                       }
                    else
                      {
                         for(int i=0;i<no_of_cities;i++)
                             {
                                 if(connect[s_index][i]==1)
                                    {
                                       for(int k=0;k<no_of_cities;k++)
                                           {
                                             if(connect[i][k]==1 && k!=s_index && cities[k]==destination)
                                               {
                                                  ind_flag=1;
                                                  cout<<"INDIRECT FLIGHT AVAILABLE!!!\n";
                                                  cout<<cities[s_index]<<" - "<<cities[i]<<" - "<<cities[d_index]<<endl;
                                                  cout<<"Time of Flight- "<<tof[s_index][i]+tof[i][k]<<"hr(s)"<<endl;
                                               }
                                           }
                                    }
                               }
                      }
                      
                    if(ind_flag==0)
                      cout<<"NO FLIGHTS AVAILABLE\n";
     cout<<"\n";               
    
}
int main()
{
    int ch,l=0;
    flight f;
    while(l==0)
       {
                  cout<<"1.ENTER THE CONNECTIVITY DATA\n";
                  cout<<"2.BOOK FLIGHT\n";
                  cout<<"3.EXIT\n";
                  cout<<"ENTER YOUR CHOICE\n";
                  cin>>ch;
                  
                  switch(ch)
                    {
                        case 1: f.enter_data();
                                break;
                        case 2: f.book_flight();
                                break;
                        case 3: l=1;
                     }
       }
 }
