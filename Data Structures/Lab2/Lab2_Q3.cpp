#include<iostream>
using namespace std;
int n=20;
class Stack
{
  int top;
  int s[20];
public:
  Stack()
  {
    top=-1;
  }
  void push(int rem);
  void display();
};
void Stack :: push(int rem)
{
  if (top==n-1)
  {
    cout<<"Stack Overflow \n";
  }
  else
  {
    top+=1;
    s[top]=rem;
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
    for(int i=top; i>=0; i--)
      cout<<s[i];
  }
}
void convert_dec(int num, int b)
{
  Stack s;
  while(num > 0)
  {
    int rem = num % b;
      num = num / b;
      s.push(rem);
  }
  s.display();
}
int main()
{
   int num,b;
   char rep='y';
   while(rep=='y' || rep=='Y')
   {
       cout<<"Enter Decimal Number: ";
       cin>>num;
       cout<<"Enter Base:";
       cin>>b;
       convert_dec(num,b);
       cout<<endl<<"Continue ? [Y/N]: ";
       cin>>rep;
   }
   return 0;
}
