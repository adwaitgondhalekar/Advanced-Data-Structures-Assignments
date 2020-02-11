#include"stack.cpp"
class TreeNode
{
   public:
   char var;
   TreeNode *right;
   TreeNode *left;
};

class exp_tree
{
   
   public:
   char exp[100];
   TreeNode *root;
   exp_tree()
   {
     root=NULL;
   }
   void construct_exptree();
   void inorder_traversal(TreeNode *temp);
};

void exp_tree::construct_exptree()
{
    stack<TreeNode*>s;
    TreeNode *p,*op1,*op2;
    int i=0;
    while(exp[i]!='\0')
    {
       if(exp[i]>=97 && exp[i]<=122)
         {
             p=new TreeNode;
             p->left=NULL;
             p->right=NULL;
             p->var=exp[i];
             s.push(p);
         }
       else
         {
           if(!(s.is_empty()))
           {
            op2=s.pop();
            op1=s.pop();
            p=new TreeNode;
            p->left=op1;
            p->right=op2;
            p->var=exp[i];
            s.push(p);
           }
          else
            {
              cout<<"empty stack\n";
              break;
            }
         }
       i++;
    }
    if(s.top==0)
    root=s.pop();
    else
    cout<<"EXPRESSION IS NOT CORRECT!!\n";
}
void exp_tree::inorder_traversal(TreeNode *temp)
{
   //TreeNode *temp=root;
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
     cout<<temp->var;
     temp=temp->right;
     }
}
int main()
{
    exp_tree obj;
    int ch,l=0;
    while(l==0)
    {
           cout<<"1.ENTER A POSTFIX EXPRESSION\n";
           cout<<"2.DISPLAY\n";
           cout<<"3.EXIT\n";
           cout<<"ENTER YOUR CHOICE\n";
           cin>>ch;
     
           switch(ch)
           {
              case 1: cout<<"EXPRESSION:";
                      cin>>obj.exp;
                      obj.construct_exptree();
                      break;

              case 2:
                      obj.inorder_traversal(obj.root);
                      cout<<"\n";
                      break;

              case 3: l=1;
           } 
}
}   
   
             
   
   
