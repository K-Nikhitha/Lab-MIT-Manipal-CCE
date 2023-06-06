#include<iostream>
#include<stack>
using namespace std;

void PostfixEval(string postfix)
{
  stack<int> st;
  for (int i=0; postfix[i] !='\0'; i++)
  {
    char c = postfix[i];
    if(c >= '0' && c <= '9')
    {
      st.push(c-'0');
    }
    else
    {
      int v1 = st.top();
      st.pop();
      int v2 = st.top();
      st.pop();
      if(c=='+')
        st.push(v2+v1);
      else if(c=='-')
        st.push(v2-v1);
      else if(c=='*')
        st.push(v2*v1);
      else if(c=='/')
        st.push(v2/v1);
    }
  }
  cout<<"Evaluated Result: "<<st.top()<<endl;
}

int main()
{
  string postfix;
  cout<<"Enter Postfix Expression: ";
  cin>>postfix;
  PostfixEval(postfix);
  return 0;
}
