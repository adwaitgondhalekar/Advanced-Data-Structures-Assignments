#include<iostream>
#define max 26
using namespace std;

class node
{
   public:
   string word;
   string meaning;
   node *next;
};

class dictionary
{
  public:
  node *alphabet[max];
  dictionary()
  {
     for(int i=0;i<max;i++)
      {
         alphabet[i]=NULL;
      }
  }
  int hashing(string key);
  void insert(string key,string meaning,int home_address);
  void display();
  node* search(string word);
};

int dictionary::hashing(string key)
{
  
   char f_letter = key[0];
   
   if(f_letter>=65 && f_letter<=90)
      f_letter+=32;
      
   int home_address = f_letter%97;
   
   while(home_address>=max)
    {
       home_address%=max;
    }
    
    return home_address;
}
node* dictionary::search(string word)
{
  node *temp;
  int h = hashing(word);
  temp=alphabet[h];
  
  while(temp!=NULL)
  {
     if(temp->word==word)
       return temp;
     else
       temp=temp->next;
  }
  
  return NULL;
}
  

void dictionary::insert(string key,string meaning,int home_address)
{
  int flag=0;
  int h = home_address;
  node *newword,*temp,*prev=NULL;
  if(alphabet[h]==NULL)
   {
       alphabet[h]= new node;
       alphabet[h]->word=key;
       alphabet[h]->meaning=meaning;
       alphabet[h]->next=NULL;
   }
  else
  {
      temp=alphabet[h];
      newword = new node;
      newword->word=key;
      newword->meaning=meaning;
      newword->next=NULL;
      
      while(temp!=NULL)
       {
           if(newword->word>temp->word)
            {
               prev=temp;
               temp=temp->next;
               flag=1;
            }
            else
            {
                node *temp1=temp;
                if(prev!=NULL)
                {
                prev->next=newword;
                newword->next=temp1;
                }
                else
                {
                   alphabet[h]=newword;
                   alphabet[h]->next=temp1;
                }
                break;
                
            }
       }
       if(flag==1)
       prev->next=newword;
    }
}

void dictionary::display()
{
   node *temp;
    for(int i=0;i<max;i++)
     {
        temp=alphabet[i];
        while(temp!=NULL)
         {
            cout<<"WORD :"<<temp->word<<endl;
            cout<<"MEANING "<<temp->meaning<<endl;
            cout<<"\n";
            temp=temp->next;
         }
     }
}
int main()
{
  
   dictionary obj;
   
   int ch,l=0;
   
   while(l==0)
    {
          cout<<"1.ADD WORD\n";
          cout<<"2.SEARCH\n";
          cout<<"3.UPDATE MEANING\n";
          cout<<"4.DISPLAY\n";
          cout<<"5.EXIT\n";
          cout<<"ENTER YOUR CHOICE\n";
          cin>>ch;
          
          switch(ch)
            {
                 case 1: {
                            string w;
                            string m;
                            
                            cout<<"ENTER WORD\n";
                            cin>>w;
                            node *found = obj.search(w);
                            if(found==NULL)
                            {
                            cout<<"ENTER MEANING\n";
                            cin.ignore();
                            getline(cin,m);
                           
                            
                            int ha = obj.hashing(w);
                            obj.insert(w,m,ha);
                            }
                            else
                            cout<<"WORD ALREADY EXISTS\n";
                            
                          }
                          break;
                          
                 case 2:{
                           string s_word;
                           cout<<"ENTER WORD\n";
                           cin>>s_word;
                           node *found=obj.search(s_word);
                           if(found!=NULL)
                           {
                              cout<<"WORD FOUND\n";
                              cout<<"WORD :"<<found->word<<endl;
                              cout<<"MEANING :"<<found->meaning<<endl;
                              cout<<"\n";
                           }
                           else
                           cout<<"WORD NOT FOUND\n";
                         }
                         break;
                 case 3:
                        {
                           string s_word,m;
                           cout<<"ENTER WORD\n";
                           cin>>s_word;
                           node *found=obj.search(s_word);
                           if(found!=NULL)
                           {
                              cout<<"WORD FOUND\n";
                              cout<<"WORD :"<<found->word<<endl;
                              cout<<"MEANING :"<<found->meaning<<endl;
                              cout<<"\n";
                              
                              cout<<"ENTER NEW MEANING\n";
                              cin.ignore();
                              getline(cin,m);
                              
                              found->meaning=m;
                              
                              cout<<"MEANING SUCCESSFULLY UPDATED\n";
                           }
                           else
                           cout<<"WORD NOT FOUND\n";
                        
                        }
                 case 4:  obj.display();
                          break;
                          
                 case 5:  l=1;
            }
       }
 }
            
        
       
               
          
      
      
      

  
