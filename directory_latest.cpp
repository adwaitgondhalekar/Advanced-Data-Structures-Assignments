#include<iostream>
#include<iomanip>
#include<cmath>
#define max 26
using namespace std;

class phonebook
{
  
    public:
    string name[max];
    long int number[max];
    
    phonebook()
    {
       for(int i=0;i<max;i++)
        {
            name[i]="";
            number[i]=0;
        }
    }
    
    int division_hashing(string key);
    int multiplication_hashing(string key);
    void collision_handler(int home_address,string name,long int num);
    void display();
    void search(string s_name);
    
    
};

void phonebook::search(string s_name)
{
   int ch=0;
   cout<<"WHICH HASHING IS USED (DIVISION/MULTIPLICATION) ?\n";
   cin>>ch;
   
   if(ch==1)
   {
   int ha = division_hashing(s_name);
   
   int flag=0;
   
   if(name[ha]==s_name)
     {
        cout<<"CONTACT FOUND\n";
        cout<<"NAME:- "<<name[ha]<<endl;
        cout<<"NUMBER:- "<<number[ha]<<endl;
        cout<<"INDEX:- "<<ha<<endl;
        flag=1;
     }
    else
     {
       do
       {
        ha=ha+1;
        ha=ha%max;
        
        if(name[ha]==s_name)
          {
             cout<<"CONTACT FOUND\n";
             cout<<"NAME:- "<<name[ha]<<endl;
             cout<<"NUMBER:- "<<number[ha]<<endl;
             cout<<"INDEX:- "<<ha<<endl;
             flag=1;
             break;
          }
       }
       while(ha!=division_hashing(s_name));
     }
     
     if(flag==0)
       cout<<"CONTACT NOT FOUND\n";
   }
   else
   {
      int ha = multiplication_hashing(s_name);
   
   int flag=0;
   
   if(name[ha]==s_name)
     {
        cout<<"CONTACT FOUND\n";
        cout<<"NAME:- "<<name[ha]<<endl;
        cout<<"NUMBER:- "<<number[ha]<<endl;
        cout<<"INDEX:- "<<ha<<endl;
        flag=1;
     }
    else
     {
       do
       {
        ha=ha+1;
        ha=ha%max;
        
        if(name[ha]==s_name)
          {
             cout<<"CONTACT FOUND\n";
             cout<<"NAME:- "<<name[ha]<<endl;
             cout<<"NUMBER:- "<<number[ha]<<endl;
             cout<<"INDEX:- "<<ha<<endl;
             flag=1;
             break;
          }
       }
       while(ha!=multiplication_hashing(s_name));
     }
     
     if(flag==0)
       cout<<"CONTACT NOT FOUND\n";
   
   }
}

int phonebook::division_hashing(string key)
{

   char f_letter = key[0];
   
   if(f_letter>=65 && f_letter<=90)
      f_letter+=32;
      
   int home_address = f_letter%97;
   
   while(home_address>=max)
   {
      home_address=home_address%max;
   }
   
   return home_address;
}

int phonebook::multiplication_hashing(string key)
{
   char f_letter = key[0];
   
   if(f_letter>=65 && f_letter<=90)
     f_letter+=32;
     
   float a = 0.7;
   float temp = f_letter*a;
   //cout<<temp<<endl;
   int quotient = (int)temp;
   //cout<<quotient<<endl;
   float fractional = temp-quotient;
   //cout<<fractional<<endl;
   
   int home_address =floor( 29 * fractional);
   
   
   while(home_address>=max)
   {
     home_address = home_address%max;
   }
   
   cout<<home_address<<endl;
   
   return home_address;
} 
   
void phonebook::collision_handler(int home_address,string uname,long int num)
{
    string t_name;
    long int t_num;
   
    if(name[home_address]=="")
      {
          name[home_address]=uname;
          number[home_address]=num;
      }
    else
      {
           int i=home_address;
           int act_homeaddress= division_hashing(name[home_address]);
           
           if(act_homeaddress!=home_address)
           {
            t_name=name[home_address];
              t_num=number[home_address];
              name[home_address]=uname;
              number[home_address]=num;
              uname=t_name;
              num=t_num;
           }
              while(name[i]!="")
             {
                i=i+1;
                i%=max;
             }
          
             name[i]=uname;
             number[i]=num;
           
        
       }
}

void phonebook::display()
{
     for(int i=0;i<max;i++)
     cout<<setw(10)<<i<<setw(20)<<name[i]<<setw(20)<<number[i]<<endl;
}              
              

int main()
{
    int ch,l=0;
    
    phonebook obj;
    
    while(l==0)
       {
                cout<<"1.POPULATE PHONEBOOK USING DIVISION HASHING METHOD\n";
                cout<<"2.POPULATE PHONEBOOK USING MULTIPLICATION HASHING METHOD\n";
                cout<<"3.SEARCH\n";
                cout<<"4.DISPLAY\n";
                cout<<"5.EXIT\n";
                cout<<"ENTER YOUR CHOICE\n";
                cin>>ch;
                
                switch(ch)
                  {
                        case 1: {
                                   int total;
                                   cout<<"HOW MANY NUMBERS YOU WANT TO ENTER?\n";
                                   cin>>total;
                                   
                                   for(int i=0;i<total;i++)
                                   {
                                   string n;
                                   long int num;
                                   cout<<"ENTER NAME\n";
                                   cin>>n;
                                   cout<<"ENTER TELEPHONE NUMBER\n";
                                   cin>>num;
                                   
                                   int home_addr = obj.division_hashing(n);
                                   obj.collision_handler(home_addr,n,num);
                                   }
                                 }
                                 break;
                                 
                        case 2: {
                                   int total;
                                   cout<<"HOW MANY NUMBERS YOU WANT TO ENTER?\n";
                                   cin>>total;
                                   
                                   for(int i=0;i<total;i++)
                                   {
                                   string n;
                                   long int num;
                                   cout<<"ENTER NAME\n";
                                   cin>>n;
                                   cout<<"ENTER TELEPHONE NUMBER\n";
                                   cin>>num;
                                   
                                   int home_addr = obj.multiplication_hashing(n);
                                   obj.collision_handler(home_addr,n,num);
                                   }
                                 
                                }
                                break;
                        case 3: 
                               {
                                  string s_name;
                                  cout<<"ENTER NAME TO SEARCH\n";
                                  cin>>s_name;
                                  
                                  obj.search(s_name);
                               }
                               break;
                                
                        case 4:  
                                 cout<<setw(10)<<"INDEX"<<setw(20)<<"NAME"<<setw(20)<<"NUMBER"<<endl;
                                 obj.display();
                                 break;
                                 
                        case 5: l=1;
                                break;
                   }
           }
  }
                                   
                                   
