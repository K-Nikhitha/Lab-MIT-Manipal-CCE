
#include<iostream>
#include<stack>
using namespace std;

int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void InfixToPostfix(string infix)
{

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
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    cout <<"Postfix Expression: "<<postfix<<endl;
}
int main()
{
    string infix;
    cout<<"Enter Infix Expression:";
    cin>>infix;
    InfixToPostfix(infix);
    return 0;
}
