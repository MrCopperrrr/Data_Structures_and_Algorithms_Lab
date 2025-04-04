bool isPalindrome(string str, int start, int end){
    if(start>=end)
    return true;
    if(str[start]==' ')
    return isPalindrome(str, start+1, end);
    if(str[end]==' ')
    return isPalindrome(str, start, end-1);
    if(str[start]!=str[end])
    return false;
    return isPalindrome(str, start+1, end-1);
}
bool isPalindrome(string str) 
{ 
    return isPalindrome(str, 0, str.length() - 1);
}