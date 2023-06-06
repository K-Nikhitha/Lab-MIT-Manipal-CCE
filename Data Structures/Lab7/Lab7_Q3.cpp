#include <iostream>
using namespace std;

class bst
{
    public:
	bst *lchild;
	int data;
	bst *rchild;
	bst(int ele=0)
	{
		lchild=NULL;
		rchild=NULL;
		data=ele;
	}
	void insert(int);
  bst* del(bst*, int);
  void display(bst *);
};
bst *root=NULL;

void bst::insert(int ele)
{	bst *temp=new bst(ele);
	if(root==NULL){root=temp;return;}
	else
	{	bst *curr=root,*prev=NULL;
		while(curr)
		{
			prev=curr;
			if(temp->data<curr->data)	curr=curr->lchild;
			else if(temp->data>curr->data)	curr=curr->rchild;
			else
			{	cout<<"Insertion is not possible";
				return;
			}
		} 
		if(temp->data>prev->data)
			prev->rchild=temp;
		else if(temp->data<prev->data)
			prev->lchild=temp;
	}
	return;
}
void bst::display(bst *ptr)
{
	if(ptr)
  {
		display(ptr->lchild);
		cout<<" "<<ptr->data;
		display(ptr->rchild);
	}
}
bst* del(bst* root,int ele)
{
  if(root==NULL)
      return root;
  if(ele>root->data)
      root->rchild=del(root->rchild,ele);
  else if(ele<root->data)
      root->lchild=del(root->lchild,ele);
  else{
      bst *temp;
      if(root->lchild==NULL){
          temp=root->rchild;
          delete root;
          return temp;
      }
      else if(root->rchild==NULL){
          temp= root->lchild;
          delete root;
          return temp;
      }
      else{
          temp=root;
          while(temp && temp->lchild){
              temp=temp->lchild;
          }
          root->data=temp->data;
          root->rchild=del(root->rchild, temp->data);
        }
    }
}
int main()
{
  bst b;
  int ch;
  char rep = 'y';
  while(rep=='Y' || rep =='y')
  {
    cout<<"Enter Choice: \n";
    cout<<"1. Insert Element\n";
    cout<<"2.Delete Element\n";
    cout<<"3. Display BST\n";
    cout<<">>";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        cout<<"Enter element to be inserted: ";
        int ele;
        cin>>ele;
        b.insert(ele);
        break;
      }
      case 2:
      {
        cout<<"Enter element to be deleted: ";
        int ele;
        cin>>ele;
        b.del(root, ele);
        break;
      }
      case 3:
      {
        b.display(root);
        cout<<endl;
        break;
      }
      default:
        cout<<"Invalid Choice.";
    }
    cout<<"Continue? [Y/N]:";
    cin>>rep;
  }
  return 0;
}
