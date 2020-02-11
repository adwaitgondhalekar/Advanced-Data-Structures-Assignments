
#include"stack.cpp"


class TreeNode
{
    public:
    int data;
    TreeNode *right;
    TreeNode *left;


};

class Tree
{
public:
    TreeNode *root;
    int key,lh=0,rh=0;
    int tot_count=0,leaf_count=0;
    Tree()
    {
        root=NULL;

    }
    void create();
    void insertnode();
    void inordertraversal(TreeNode *temp);
    void preordertraversal(TreeNode *temp);
    void postordertraversal(TreeNode *temp);
    void inordernonrecursive();
    void preordernonrecursive();
    void postordernonrecursive();
    void NodeCount(TreeNode *temp);
    int Search(TreeNode *temp);
    int height(TreeNode *temp);
    int max_data(TreeNode *temp);
    int min_data(TreeNode *temp);


};
int Tree::height(TreeNode *temp)
{

    if(temp==NULL)
      return 0;
      
    if(temp->right==NULL && temp->left==NULL)
      return 0;
      
    else
    {
      lh=height(temp->left);
      rh=height(temp->right);
    }
    if(lh>rh)
      return lh+1;
    else
      return rh+1;
}
void Tree::postordernonrecursive()
{
   TreeNode *temp=root;
   stack<TreeNode*>s;
   stack<char>s1;
   
   char flag;
      while(1)
      {
        while(temp!=NULL)
          {
            s.push(temp);
            s1.push('L');
            temp=temp->left;
          }
        if(s.is_empty()) return;
        
        else
        {
           temp=s.pop();
           flag=s1.pop();
           if(flag=='R')
             {
                cout<<temp->data<<"\t";
                temp=NULL;
             }
           else
             {
               s.push(temp);
               s1.push('R');
               temp=temp->right;
             }
         }
      }
  }
  
void Tree::preordernonrecursive()
{
   TreeNode *temp=root;
   stack<TreeNode*>s;
   while(1)
     {
         while(temp!=NULL)
            {
                cout<<temp->data<<"\t";
                s.push(temp);
                temp=temp->left;
            }
            if(s.is_empty()) return;
            
            temp=s.pop();
            temp=temp->right;
     }
}

void Tree::inordernonrecursive()
{
   TreeNode *temp=root;
   stack<TreeNode*>s;
   while(1)
     {
        while(temp!=NULL)
        {
         s.push(temp);
         temp=temp->left;
        }
     
     if(s.is_empty()) return;
     
     temp=s.pop();
     cout<<temp->data<<"\t";
     temp=temp->right;
     }
}
int Tree::Search(TreeNode *temp)
{
   if(temp!=NULL)
     {
       
       if(key==temp->data)
         return 1;
       else if(key>temp->data)
         Search(temp->right);
       else
         Search(temp->left);
     }
   else
      return 0;
}
  
void Tree::create()
{
    int d;
    cout<<"ENTER THE DATA OF THE ROOT NODE\n";
    cin>>d;

    root=new TreeNode;
    root->left=NULL;
    root->right=NULL;
    root->data=d;
    cout<<"THE ROOT NODE HAS BEEN SUCCESSFULLY CREATED\n";
}

void Tree::insertnode()
{
    TreeNode *temp,*p;
    int insdata;

    if(root==NULL)
    {
        create();
        return;
    }

    cout<<"ENTER DATA TO BE INSERTED\n";
    cin>>insdata;

    temp=root;
    p=new TreeNode;
    p->data=insdata;
    p->right=NULL;
    p->left=NULL;

    while(1)
    {
        if(p->data<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=p;
                return;

            }
            else
                temp=temp->left;
        }
        else if(p->data>temp->data)
        {
            if(temp->right==NULL)
            {
                temp->right=p;
                return;
            }
            else
                temp=temp->right;
        }
    }


}
void Tree::inordertraversal(TreeNode *temp)
{
    if(temp!=NULL)
    {
        inordertraversal(temp->left);
        cout<<temp->data<<"\t";
        inordertraversal(temp->right);
    }


}

void Tree::preordertraversal(TreeNode *temp)
{
   
   if(temp!=NULL)
     {
          cout<<temp->data<<"\t";
          preordertraversal(temp->left);
          preordertraversal(temp->right);
     }
}

void Tree::postordertraversal(TreeNode *temp)
{
   if(temp!=NULL)
     {
         postordertraversal(temp->left);
         postordertraversal(temp->right);
         cout<<temp->data<<"\t";
     }
}
void Tree::NodeCount(TreeNode *temp)
{
    

   if(temp!=NULL)
     {
         tot_count++;
         if(temp->right==NULL&&temp->left==NULL)
         leaf_count++;
         NodeCount(temp->left);
         NodeCount(temp->right);
     }
}

int Tree::min_data(TreeNode *temp)
{

   if(temp->left==NULL)
     return temp->data;
   else
     min_data(temp->left);    

}

int Tree::max_data(TreeNode *temp)
{
   if(temp->right==NULL)
     return temp->data;
   else
     max_data(temp->right);    
}   
                


int main()
{
    int l=0,ch;

    Tree obj;

    while(l==0)
    {
           cout<<"1.INSERT NODE\n";
           cout<<"2.INORDER(RECURSIVE)\n";
           cout<<"3.PREORDER(RECURSIVE)\n";
           cout<<"4.POSTORDER(RECURSIVE)\n";
           cout<<"5.INORDER(NON RECURSIVE)\n";
           cout<<"6.PREORDER(NON RECURSIVE)\n";
           cout<<"7.POSTORDER(NON RECURSIVE)\n";
           cout<<"8.SEARCH\n";
           cout<<"9.NODE COUNT\n";
           cout<<"10.HEIGHT OF TREE\n";
           cout<<"11.MAX NODE\n";
           cout<<"12.MIN NODE\n";        
           cout<<"13.EXIT\n";
           cout<<"ENTER CHOICE\n";
           cin>>ch;


           switch(ch)
           {
               case 1: obj.insertnode();
                       break;

               case 2:
                       obj.inordertraversal(obj.root);
                       cout<<"\n";
                       break;
               case 3:
                       obj.preordertraversal(obj.root);
                       cout<<"\n";
                       break;
               case 4:  
                       obj.postordertraversal(obj.root);
                       cout<<"\n";
                       break;
               case 5:
                       obj.inordernonrecursive();
                       cout<<"\n";
                       break;
               case 6: 
                       obj.preordernonrecursive();
                       cout<<"\n";
                       break;
               case 7: 
                       obj.postordernonrecursive();
                       cout<<"\n";
                       break;
                       
               case 8:
                      {
                        
                        cout<<"ENTER THE NUMBER TO BE SEARCHED\n";
                        cin>>obj.key;
                        int search_result=obj.Search(obj.root);
                        if(search_result==1)
                          cout<<"ELEMENT FOUND\n";
                        else
                          cout<<"ELEMENT NOT FOUND\n";
                       }
                       break;
               case 9:
                       { 
                       obj.NodeCount(obj.root);
                       cout<<"TOTAL NODES:"<<obj.tot_count<<endl;
                       cout<<"LEAF NODES:"<<obj.leaf_count<<endl;
                       break;
                       }
               case 10:{
                       int h=obj.height(obj.root);
                       cout<<"HEIGHT OF TREE="<<h+1<<endl;
                       break;
                       }
               case 11:{
                        
                        int max_node=obj.max_data(obj.root);
                        cout<<"MAX NODE:-"<<max_node<<endl;
                        break;
                       }
               case 12:{
                         
                         int min_node=obj.min_data(obj.root);
                         cout<<"MIN NODE:-"<<min_node<<endl;
                         break;
                       }
               case 13: l=1;

           }
    }
}
