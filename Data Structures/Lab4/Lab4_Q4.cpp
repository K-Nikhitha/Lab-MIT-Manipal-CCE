#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string reverseString(string infix)
{
  string rev;
  for(int i=infix.length()-1; i>=0; i--)
    rev += infix[i];
  return rev;
}
string InfixToPostfix(string infix)
{
  infix = '(' + infix + ')';
  stack<char> st;
  string postfix;
  for(int i = 0; i < infix.length(); i++)
  {
      char c = infix[i];
      if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
          postfix += c;
      else if(c == '(')
          st.push('(');
      else if(c == ')') {
          while(st.top() != '(')
          {
              postfix += st.top();
              st.pop();
          }
          st.pop();
      }
      else
      {
          while(!st.empty() && precedence(infix[i]) <= precedence(st.top()))
          {
              postfix += st.top();
              st.pop();
          }
          st.push(c);
      }
  }
  return postfix;
}

void InfixToPrefix(string infix)
{
  infix = reverseString(infix);
  for (int i = 0; i < infix.length(); i++)
  {
    if (infix[i] == '(')
    {
      infix[i] = ')';
      i++;
    }
    else if (infix[i] == ')')
    {
      infix[i] = '(';
      i++;
    }
  }
  string postfix = InfixToPostfix(infix);
  string prefix = reverseString(postfix);
  cout<<"Prefix Expression: "<<prefix<<endl;
}
int main()
{
  string infix;
  cout<<"Enter Infix Expression: ";
  cin>>infix;
  InfixToPrefix(infix);
  return 0;
}
