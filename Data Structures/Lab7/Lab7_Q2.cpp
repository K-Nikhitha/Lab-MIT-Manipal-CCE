#include <iostream>
using namespace std;

class bst
{
	bst *lchild;
	int data;
	bst *rchild;
public:
	bst(int ele=0)
	{
		lchild=NULL;
		rchild=NULL;
		data=ele;
	}
	void insert(int);
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
	if(ptr){
		display(ptr->lchild);
		cout<<" "<<ptr->data;
		display(ptr->rchild);
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
    cout<<"2. Display BST\n";
    cout<<">>";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        cout<<"Enter element: ";
        int ele;
        cin>>ele;
        b.insert(ele);
        break;
      }
      case 2:
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
