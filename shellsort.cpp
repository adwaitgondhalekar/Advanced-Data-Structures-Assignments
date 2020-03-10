#include<iostream>
using namespace std;


int main()
{

   int n;
   cout<<"ENTER THE NUMBER OF ELEMENTS\n";
   cin>>n;
   int num[n];
   for(int i=0;i<n;i++)
      {
         cout<<"ENTER NUMBER\n";
         cin>>num[i];
      }

   cout<<"SORTED ARRAY IS\n";
   
   for(int gap=n/2;gap>=1;gap=gap/2)
      {
       for(int j=gap;j<n;j++)
          {
             for(int i=j-gap;i>=0;i=i-gap)
               {
                  if(num[i+gap]>num[i])
                   break;
                  else
                   {
                      int temp=num[i];
                      num[i]=num[i+gap];
                     num[i+gap]=temp;
                   }
              }
           }
        }
     for(int i=0;i<n;i++)
         {
            cout<<num[i]<<"\t";
         }
}

