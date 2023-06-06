#include<iostream>
#include<stack>
using namespace std;
void PostfixToInfix(string postfix)
{
  stack<string> st;
  for(int i=0; postfix[i]!='\0'; i++)
  {
    char c = postfix[i];
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      string s(1, c);
      st.push(s);
    }
    else
    {
      string op1 = st.top();
      st.pop();
      string op2 = st.top();
      st.pop();
      st.push("("+op2+postfix[i]+op1+")");
    }
  }
  cout<<"Infix Expression: "<<st.top();
}
int main()
{
  string postfix;
  cout<<"Enter Postfix Expression: ";
  cin>>postfix;
  PostfixToInfix(postfix);
  return 0;
}
