#include<iostream>
#include<string>
#define max 100
using namespace std;

class TreeNode
{
   public:
   string keyword;
   string meaning[max];
   int no_of_meaning;
   int update;
   TreeNode *left;
   TreeNode *right;
};

class Dictionary
{

   public:
   TreeNode *root;
   string s_word;
   int ctr=1;
   string mean;
   Dictionary()
   {
      root=NULL;
   }
   void create(string root_word);
   void insert(string new_word);
   void inordertraversal(TreeNode *temp);
   TreeNode* search(TreeNode *temp);
   void update_meaning(TreeNode *temp);   
};
void Dictionary::update_meaning(TreeNode *temp)
{
   int update;
   string newmean;
  
            cout<<"TOTAL MEANINGS OF THIS KEYWORD:"<<(temp->no_of_meaning)<<endl;
            cout<<"ENTER WHICH MEANING YOU WANT TO UPDATE\n";
            cin>>update;
            
            cout<<"ENTER THE NEW MEANING\n";
            cin.ignore();
            getline(cin,newmean);
            for(int i=0;i<temp->no_of_meaning;i++)
               {
                   if(i==update-1)
                     temp->meaning[i]=newmean;
               }
            cout<<"MEANING SUCCESSFULLY UPDATED\n";
   
     
}    

TreeNode* Dictionary::search(TreeNode *temp)
{
   if(temp!=NULL)
     {
        if(temp->keyword==s_word)
          {
            cout<<temp->keyword<<" : "<<endl;
           
         for(int i=0;i<temp->no_of_meaning;i++)
            {
               cout<<"\t"<<(i+1)<<">>"<<temp->meaning[i]<<endl;
               cout<<"\n";
            }
            cout<<"\n\n";
            return temp;
          }
          else if(s_word>temp->keyword)
            search(temp->right);
          else
            search(temp->left);
     }
     else
      return NULL;
}

void Dictionary::create(string root_word)
{
    //string mean;
    root=new TreeNode;
    root->right=NULL;
    root->left=NULL;
    //cout<<"ENTER THE KEYWORD AS ROOT\n";
    //cin>>root->keyword;
    root->keyword=root_word;
    
    cout<<"ENTER NUMBER OF MEANINGS OF THIS KEYWORD\n";
    cin>>root->no_of_meaning;
    
    for(int i=0;i<root->no_of_meaning;i++)
       {
          cout<<"ENTER MEANING "<<i+1<<":";
          cin.ignore();
          getline(cin,mean);
          root->meaning[i]=mean;
          cout<<"\n";
       }
    
    cout<<"ROOT NODE HAS BEEN SUCCESSFULLY CREATED\n";
}

void Dictionary::insert(string new_word)
{
   
   //string mean;
   if(root==NULL)
    {
       create(new_word);
       return;
    }
    
    TreeNode *temp,*newnode;
    temp=root;
    
    
    newnode=new TreeNode;
    newnode->right=NULL;
    newnode->left=NULL;
    
    //cout<<"ENTER THE KEYWORD\n";
    //cin>>newnode->keyword;'
    newnode->keyword=new_word;
    
    cout<<"ENTER THE NO OF MEANINGS OF THIS KEYWORD\n";
    cin>>newnode->no_of_meaning;
    
    for(int i=0;i<newnode->no_of_meaning;i++)
      {
         cout<<"ENTER MEANING "<<i+1<<":";
         cin.ignore();
          getline(cin,mean);
          newnode->meaning[i]=mean;
          cout<<"\n";
      }
      while(temp!=NULL)
         {
             if(newnode->keyword>temp->keyword)
               {
                    if(temp->right==NULL)
                      {
                      temp->right=newnode;
                      return;
                      }
                      else
                      temp=temp->right;
               }
            else
               {
                    if(temp->left==NULL)
                     {
                       temp->left=newnode;
                       return;
                     }
                     else
                     temp=temp->left;
               }
         }
}        

void Dictionary::inordertraversal(TreeNode *temp)
{
    //ctr=1;
    if(temp!=NULL)
      {
         
         inordertraversal(temp->left);
         cout<<"("<<ctr++<<")"<<temp->keyword<<" : "<<endl;
         //ctr++;
         for(int i=0;i<temp->no_of_meaning;i++)
            {
               cout<<"\t"<<(i+1)<<">>"<<temp->meaning[i]<<endl;
               cout<<"\n";
            }
            cout<<"\n\n";
         inordertraversal(temp->right);
      }
}
int main()
{

    int l=0,ch;
    Dictionary obj;
     
    while(l==0)
       {
             cout<<"1.ADD KEYWORD\n";
             cout<<"2.DISPLAY\n";
             cout<<"3.UPDATE MEANING\n";
             cout<<"4.EXIT\n";
             cout<<"ENTER YOUR CHOICE\n";
             cin>>ch;
             
             
             switch(ch)
                {
                     case 1:  {
                     
                              cout<<"ENTER THE KEYWORD TO BE ADDED\n";
                              cin>>obj.s_word;
                              TreeNode *sresult=obj.search(obj.root);
                              
                              if(sresult==NULL)
                                 obj.insert(obj.s_word);
                              else
                                 cout<<"ENTERED KEYWORD ALREADY EXISTS IN THE DICTIONARY\n";
                              
                              break;
                              }
                      
                     case 2:    obj.ctr=1;
                                obj.inordertraversal(obj.root);
                              break;
                           
                     case 3:
                              {
                                cout<<"ENTER THE KEYWORD WHOSE MEANING YOU WANT TO CHANGE\n";
                                cin>>obj.s_word;
                                TreeNode *sresult=obj.search(obj.root);
                               
                                
                                if(sresult==NULL)
                                  cout<<"SEARCHED KEYWORD DOES NOT EXIST\n";
                                else
                                  obj.update_meaning(sresult);
                              }
                              break;
                     case 4:    l=1;
                }
      }
}
               
               
            
      
     
