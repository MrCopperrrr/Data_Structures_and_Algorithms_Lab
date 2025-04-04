vector<int> stock_span(const vector<int>& ns) {
    int n = ns.size();
    if (n == 0) return vector<int>();
    
    vector<int> spans(n);
    stack<int> st;  // Stack lưu chỉ số các ngày có giá lớn hơn
    
    // Xử lý ngày đầu tiên
    spans[0] = 1;
    st.push(0);
    
    for (int i = 1; i < n; i++) {
        // Pop các giá nhỏ hơn hoặc bằng giá hiện tại
        // Chú ý: đổi <= thành < để xử lý đúng với các giá bằng nhau
        while (!st.empty() && ns[st.top()] < ns[i]) {
            st.pop();
        }
        
        // Nếu stack rỗng hoặc giá trị top lớn hơn giá trị hiện tại
        if (st.empty()) {
            spans[i] = i + 1;  // Tất cả các ngày trước đều nhỏ hơn
        } else if (ns[st.top()] == ns[i]) {
            // Nếu giá bằng nhau, span sẽ là khoảng cách đến phần tử lớn hơn gần nhất
            spans[i] = i - st.top();
        } else {
            // Giá trị top lớn hơn giá trị hiện tại
            spans[i] = i - st.top();
        }
        
        // Push chỉ số hiện tại vào stack
        st.push(i);
    }
    
    return spans;
}