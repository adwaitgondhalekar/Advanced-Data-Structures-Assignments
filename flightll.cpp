#include<iostream>
#define max 100
using namespace std;

class node
{
   public:
   string name;
   float fuel;
   float time;
   node *next;
};

class flight
{
   node *cities[max];
   int no_of_cities;
   public:
   flight()
   {
      for(int i=0;i<max;i++)
         cities[i]=NULL;
   }
   void accept_data();
   void display();
};

void flight::accept_data()
{
    string c_name;
    node *curr,*prev;
    cout<<"ENTER THE TOTAL NUMBER OF CITIES\n";
    cin>>no_of_cities;
    
    for(int i=0;i<no_of_cities;i++)
       {
           cout<<"ENTER THE NAME OF CITY "<<(i+1)<<":";
           cin>>c_name;
           
           cities[i]=new node;
           cities[i]->name=c_name;
           cities[i]->next=NULL;
           cities[i]->fuel=0;
           cities[i]->time=0;
       }
     char connect;
     
     for(int i=0;i<no_of_cities;i++)
        {
           prev=cities[i];
           for(int j=0;j<no_of_cities;j++)
              {
                 
                 if(i!=j)
                  {
                     cout<<"CONNECTIVITY OF "<<cities[i]->name<<" With -"<<cities[j]->name<<"(y/n)?\n";
                     cin>>connect;
                     
                     if(connect=='y')
                      {   
                           curr=new node;
                           curr->name=(cities[j]->name);
                           curr->next=NULL;
                         
                           cout<<"ENTER THE TIME OF FLIGHT\n";
                           cin>>curr->time;
                          
                           cout<<"ENTER THE FUEL REQUIRED\n";
                           cin>>curr->fuel;  
                          
                           prev->next=curr;
                           prev=curr;
                      }
                  }
             }
         }
         
}

void flight::display()
{
   
    cout<<"THE DIRECT FLIGHTS AVAILABLE ARE\n";
   
    
    for(int i=0;i<no_of_cities;i++)
       {
           node *curr=cities[i];
           cout<<cities[i]->name<<":"<<endl;
           if(curr->next!=NULL)
            {
             curr=curr->next;
             while(curr!=NULL)
                { 
                   cout<<"\t"<<curr->name<<endl;
                   cout<<"\tTime of flight:-"<<curr->time<<"hr(s)"<<endl;
                   curr=curr->next;
                }
            }
           else
             cout<<"NO DIRECT FLIGHTS FROM THIS CITY\n";
             
       }
       
    cout<<"THE INDIRECT FLIGHTS AVAILABLE ARE\n";
    
    for(int i=0;i<no_of_cities;i++)
      {
         node *curr=cities[i];
         cout<<cities[i]->name<<":"<<endl;
         if(curr->next!=NULL)
           {
             curr=curr->next;
             while(curr!=NULL)
              {
                             for(int j=0;j<no_of_cities;j++)
                              {
                               
                                 node *curr1=cities[j];
                               if(cities[j]->name==curr->name)
                                 {
                       
                                    if(curr1->next!=NULL)
                                      {
                                        curr1=curr1->next;
                                        while(curr1!=NULL)
                                         { 
                                            if(curr1->name!=cities[i]->name)
                                              {
                                               cout<<"\t"<<cities[j]->name<<"-";
                                               cout<<"\t"<<curr1->name<<endl;
                                               cout<<"\tTime of flight:-"<<(curr->time + curr1->time)<<"hr(s)"<<endl;
                                               curr1=curr1->next;
                                              }
                                              else
                                              curr1=curr1->next;
                                         }
                                     }
                                 }
                             }
                curr=curr->next;
               }
            }
           else
           cout<<"NO CONNECTIVITY\n";
       }
    
    
}
int main()
{
   
     int l=0,ch;
     flight obj;
     
     while(l==0)
       {
           cout<<"1.ENTER THE CONNECTIVITY DATA\n";
           cout<<"2.DISPLAY CONNECTIVITY DATA\n";
           cout<<"3.EXIT\n";
           cout<<"ENTER YOUR CHOICE\n";
           cin>>ch;
           
           switch(ch)
              {
                  case 1:  obj.accept_data();
                           break;
                  case 2:  obj.display();
                           cout<<"\n";
                           break;
                  case 3:  l=1;
              }
       }
}   
          
                        
                         
                         
                     
