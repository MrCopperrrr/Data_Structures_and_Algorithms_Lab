void printArray(int n)
{
    if( n>0){
        printArray(n-1);
        cout<<", ";
    }
    cout <<n;
}