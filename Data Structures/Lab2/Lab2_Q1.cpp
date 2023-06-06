#include<iostream>
using namespace std;
int n;
class Stack
{
  int top, s[20];
public:
  Stack()
  {
    top=-1;
  }
  void push();
  void pop();
  void display();
};
void Stack :: push()
{
  if (top==n-1)
  {
    cout<<"Stack Overflow \n";
  }
  else
  {
    top+=1;
    cout<<"Enter the element to be inserted: ";
    cin>>s[top];
  }
}
void Stack :: pop()
{
  if(top==-1)
  {
    cout<<"Stack Underflow \n";
  }
  else
  {
    cout<<" The element "<<s[top]<<" is deleted. \n";
    top-=1;
  }
}
void Stack :: display()
{
  if (top==-1)
  {
    cout<<"Stack is Empty. \n";
  }
  else
  {
    cout<<"The elements in the stack are: ";
    for(int i=top; i>=0; i--)
    {
      cout<<"\n"<<s[i];
    }
    cout<<endl;
  }
}
int main()
{
  Stack s;
  int ch;
  cout<<"Enter the size of the stack: ";
  cin>>n;
  char rep='y';
  while(rep=='y' || rep=='Y')
  {
    cout<<"Enter Choice: \n 1.Push \n 2.Pop \n 3.Display \n >>";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        s.push();
        break;
      }
      case 2:
      {
        s.pop();
        break;
      }
      case 3:
      {
        s.display();
        break;
      }
      default:
        {
            cout<<"Invalid Choice."<<endl;
        }
    }
    cout<<"Continue ? [Y/N]: ";
    cin>>rep;
  }
  return 0;
}
