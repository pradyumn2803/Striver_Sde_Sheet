#include<stack>
bool isValidParenthesis(string expression)
{
    stack<char> st;
    
    for(int i=0;i<expression.size();i++)
    {
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
        {
            st.push(expression[i]);
        }
        
        else
        {
            if(st.empty()) return 0;
            
            char c=st.top();
            if(c=='(' && expression[i]==')' || c=='{' && expression[i]=='}' || c=='[' && expression[i]==']' )
            {
                st.pop();
            }
            else 
            {
                return 0;
            }
        }
    }
    if(!st.empty()) return 0;
    return 1;
}