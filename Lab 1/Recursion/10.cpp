int minimumBracketAddHelper(const string &s, size_t index, int open, int close) {
    if (index == s.size()) {
        return open + close;
    }

    if (s[index] == '(') {
        return minimumBracketAddHelper(s, index + 1, open + 1, close);
    } 
    else {
        if (open > 0) {
            return minimumBracketAddHelper(s, index + 1, open - 1, close);
        } else {
            return minimumBracketAddHelper(s, index + 1, open, close + 1);
        }
    }
}

int mininumBracketAdd(string s) {
    return minimumBracketAddHelper(s, 0, 0, 0);
}