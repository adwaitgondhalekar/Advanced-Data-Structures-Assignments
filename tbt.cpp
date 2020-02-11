#include<iostream>
using namespace std;

class TreeNode
{
  public:
  int data;
  TreeNode *right,*left;
  int lbit,rbit;
};

class tbt
{
   public:
   TreeNode *head;
   TreeNode *root;
   tbt()
   {
       head=new TreeNode;
       head->data=0;
       head->right=head;
       head->left=head;
       head->lbit=0;
       head->rbit=1;
       root=NULL;
   }
   
   void create();
   void inorder_traversal();
   void preorder_traversal();
   
};

void tbt::create()
{
   char ch='y';
   TreeNode *temp,*curr;
   do
   {
      curr=new TreeNode;
      cout<<"ENTER NODE DATA\n";
      cin>>curr->data;
      curr->lbit=1;
      curr->rbit=1;
      if(root==NULL)
      {
         root=curr;
         head->left=root;
         root->left=head;
         root->right=head;
      }
      else
      {
         temp=root;
         while(1)
         {
            if(curr->data<temp->data)
              {
                 if(temp->lbit==1)
                   {
                       curr->left=temp->left;
                       temp->left=curr;
                       temp->lbit=0;
                       curr->right=temp;
                       break;
                   }
                   else
                      temp=temp->left;
              }
              else
              {
                 if(temp->rbit==1)
                   {
                     curr->right=temp->right;
                     temp->right=curr;
                     temp->rbit=0;
                     curr->left=temp;
                     break;
                   }
                   else
                    temp=temp->right;
              }
         }
      }
    cout<<"DO YOU WANT TO ADD MORE DATA?(Y/N)\n";
    cin>>ch;
  }
  while(ch=='y');
}
void tbt::inorder_traversal()
{


    int flag=0;
    TreeNode *temp=root;
 
    while(temp!=head)
    {
        if(temp->lbit==0 && flag==0)
          temp=temp->left;
        else
          {
             cout<<temp->data<<"\t";
             if(temp->rbit==0)
               {
                  temp=temp->right;
                  flag=0;
               }
             else
               {
                  temp=temp->right;
                  flag=1; 
               } 
          }
   }
}
void tbt::preorder_traversal()
{
   TreeNode *temp=root;
   int flag=0;

   while(temp!=head)
   {
      if(flag==0)
        cout<<temp->data<<"\t";
      if(temp->lbit==0&&flag==0)
        temp=temp->left;

      else
       {
           if(temp->rbit==0)
           {
              temp=temp->right;
              flag=0;
           }
          else
           {
             temp=temp->right;
             flag=1;
           }
       }
   }
  cout<<endl;
}

int main()
{
       tbt obj;
       int ch,l=0;
       while(l==0)
         {
                cout<<"1.ADD NODE\n";
                cout<<"2.INORDER TRAVERSAL\n";
                cout<<"3.PREORDER TRAVERSAL\n";
                cout<<"4.EXIT\n";
                cout<<"ENTER YOUR CHOICE\n";
                cin>>ch;
              
                switch(ch)
                {
                    case 1:  obj.create();
                             break;
                    case 2:
                             obj.inorder_traversal();
                             cout<<"\n";
                             break;
                    case 3:  
                             obj.preorder_traversal();
                             break;
                    case 4:
                             l=1;
                } 
         }
}


    

   
