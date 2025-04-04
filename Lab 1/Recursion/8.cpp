int myArrayToInt(char *str, int n) 
{ 
    if(n == 0) return 0;
    return (myArrayToInt(str, n-1) * 10 + str[n-1]-'0');
    
}