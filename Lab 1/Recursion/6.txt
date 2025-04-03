string repeat(const string& str, int times) {
    if (times == 0) return "";  
    return str + repeat(str, times - 1);  
}

int parseNumber(const string& s, string::size_type& index) {
    if (index >= s.size() || !isdigit(s[index])) {
        return 0;  
    }
    int digit = s[index] - '0';
    index++;
    int nextPart = parseNumber(s, index);
    return digit + 10 * nextPart;
}

string expandRecursive(const string& s, string::size_type& index) {
    string result = "";
    if (index >= s.size()) {
        return result;
    }
    char current = s[index];
    if (isdigit(current)) {
        int num = parseNumber(s, index);
        index++;  
        string subResult = expandRecursive(s, index);
        index++;
        return result + repeat(subResult, num) + expandRecursive(s, index);
    } 
    else if (current == ')') {
        return result;
    } 
    else {
        index++;
        return result + current + expandRecursive(s, index);
    }
}

string expand(string s) {
    string::size_type index = 0;
    return expandRecursive(s, index);
}