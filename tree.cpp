#include<iostream>
using namespace std;

class TreeNode
{
  public:
   int data;
   TreeNode *left;
    TreeNode *right;
};

class Tree
{
   public:
   TreeNode *root;
   int total;
   
   Tree()
   {
      root=NULL;
   }
   void create();
   void insert();
   void pretraverse(TreeNode *temp);
   void count(TreeNode* temp);
   };


void Tree::count(TreeNode *temp)
{
   if(temp!=NULL)
    {
        total++;
        count(temp->left);
        count(temp->right);
    }
}
       
void Tree::pretraverse(TreeNode *temp)
{
   //temp=root;
   if(temp!=NULL)
     {
         cout<<temp->data<<"\t";
         pretraverse(temp->left);
         pretraverse(temp->right);
     }
}   

void Tree::create()
{
   
    int root_data;
    cout<<"ENTER THE DATA OF THE ROOT NODE\n";
    cin>>root_data;

    root=new TreeNode;
    root->left=NULL;
    root->right=NULL;
    root->data=root_data;
    cout<<"THE TREE HAS BEEN SUCCESSFULLY CREATED\n";
  
}

void Tree::insert()
{
    TreeNode *curr,*temp;
    char ch;int insdata;
    if(root==NULL)
     {
      create();
      return;
     }
    cout<<"ENTER DATA TO BE INSERTED\n";
     cin>>insdata;
   
    curr=new TreeNode;
    curr->right=NULL;
    curr->left=NULL;
    curr->data=insdata;
    temp=root;
    while(temp!=NULL)
     {
        cout<<"ENTER THE POSITION (LEFT/RIGHT) FOR THE DATA:- "<<insdata<<"wrt to "<<temp->data<<endl;
        cin>>ch;
        if(ch=='r')
        {   
           if(temp->right==NULL)
            {
             temp->right=curr;
             return;
             }
           else
             temp=temp->right;
        }
        else if(ch=='l')
        {
           if(temp->left==NULL)
            {
             temp->left=curr;
             return;
            }
           else
             temp=temp->left;
        }
     }
}



int main()
{
  
    int ch,l=1;
    Tree obj;
    while(l==1) 
        { 
              cout<<"\n";
              cout<<"1.INSERT NODE\n";
              cout<<"2.DISPLAY\n";  
              cout<<"3.TOTAL NODES\n";
              cout<<"4.EXIT\n";
              cout<<"ENTER CHOICE\n";
              cin>>ch;
       
              switch(ch)
              {
                  case 1: 
                           
                            obj.insert();
                         
                         break;
                  case 2:  
                          obj.pretraverse(obj.root);
                          break;
                  case 3: obj.count(obj.root);
                          cout<<"TOTAL NODES:-"<<obj.total<<endl;
                          break;
                  case 4: l=0;
              }
          }
 }
                           
        
   
     

     
    
   
    
