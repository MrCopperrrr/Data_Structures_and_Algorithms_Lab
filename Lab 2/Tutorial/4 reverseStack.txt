void reverseStack(stack<int> & st) {
    queue<int> q;
    
    while (!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    while (!q.empty()){
        st.push(q.front());
        q.pop();
    }
}