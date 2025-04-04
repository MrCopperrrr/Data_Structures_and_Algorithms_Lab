string reverseSentenceHelper(const string &s, size_t start) {
    size_t spacePos = s.find(' ', start);
    if (spacePos == string::npos) {
        return s.substr(start);
    }

    string restReversed = reverseSentenceHelper(s, spacePos + 1);

    return restReversed + " " + s.substr(start, spacePos - start);
}

string reverseSentence(string s) {
    return reverseSentenceHelper(s, 0);
}