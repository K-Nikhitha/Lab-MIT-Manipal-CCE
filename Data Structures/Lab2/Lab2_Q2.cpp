#include<iostream>
using namespace std;
int n=20;
class Stack
{
  int top;
  char s[20];
public:
  Stack()
  {
    top=-1;
  }
  void push(char c);
  char pop();
};
void Stack :: push(char c)
{
  if (top==n-1)
  {
    cout<<"Stack Overflow \n";
  }
  else
  {
    top+=1;
    s[top]=c;
  }
}
char Stack :: pop()
{
  if(top==-1)
  {
    cout<<"Stack Underflow \n";
  }
  else
  {
    char temp= s[top];
    top-=1;
    return temp;
  }
}
int main()
{
  Stack s;
  char arr[20],c;
  int len=0,f=0;
  char rep='y';
  while(rep=='y' || rep=='Y')
  {
      cout<<"Enter String to check if it is a Palindrome: ";
      cin>>arr;
      for(int i=0; arr[i] != '\0'; i++)
        len+=1;
      for(int i=0; i<len; i++)
        {
            s.push(arr[i]);
      }
      for(int i = 0; i<len; i++)
        {
            if(s.pop()!= arr[i])
            {
                f++;
            }
        }
        if (f==0)
            {
                cout<<"Palindrome String. \n";
            }
        else
            cout<<"Not a Palindrome String. \n";
        cout<<"Continue ? [Y/N]: ";
        cin>>rep;
  }
  return 0;
}
