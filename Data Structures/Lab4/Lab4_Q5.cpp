#include<iostream>
#include<stack>
#include<string>
using namespace std;

void PrefixEval(string prefix)
{
  stack<int> st;
  for (int i=prefix.length()-1; i>=0; i--)
  {
    char c = prefix[i];
    if(c >= '0' && c <= '9')
    {
      st.push(c-'0');
    }
    else
    {
      int v1=st.top();
      st.pop();
      int v2=st.top();
      st.pop();
      if(c=='+')
        st.push(v1+v2);
      else if(c=='-')
        st.push(v1-v2);
      else if(c=='*')
        st.push(v1*v2);
      else if(c=='/')
        st.push(v1/v2);
    }
  }
  cout<<"Evaluated Result: "<<st.top()<<endl;
}
int main()
{
  string prefix;
  cout<<"Enter Prefix Expression: ";
  cin>>prefix;
  PrefixEval(prefix);
  return 0;
}
