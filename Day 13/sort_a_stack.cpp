void mergestack(stack<int> &st,int element)
{
    if(st.empty() || element>st.top()) 
    {
        st.push(element);
        return ;
    }

    int temp=st.top();
    st.pop();
    mergestack(st,element);
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    if(st.empty()) return ;
    
    int temp=st.top();
    st.pop();
    sortStack(st);
    mergestack(st,temp);
}