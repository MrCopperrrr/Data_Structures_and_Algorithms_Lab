bool isDigit(char c) {
    if ('0' <= c && c <= '9') return true;
    return false;
}

int evaluatePostfix(string expr){
    stack<int> stack;
    int len = expr.size();

    for (int i = 0; i < len; i++) {
        if (expr[i] == ' ') {
            continue;  
        } else if (isDigit(expr[i])) {
            int num = 0;

            while (isDigit(expr[i])) {
                num = num * 10 + (int)(expr[i] - '0');
                i++;
            }
            i--;  
            stack.push(num);
        } else {
            int val1 = stack.top(); stack.pop();
            int val2 = stack.top(); stack.pop();

            switch (expr[i]) {
                case '+':
                    stack.push(val2 + val1);
                    break;
                case '-':
                    stack.push(val2 - val1);
                    break;
                case '*':
                    stack.push(val2 * val1);
                    break;
                case '/':
                    stack.push(val2 / val1);
                    break;
            }
        }
    }
    return stack.top();
}
