void printHailstone(int number)
{
    cout << number;
    if(number==1) return;
    
    if(number % 2 ==0){
        cout << " ";
        printHailstone(number / 2);
    }
    if(number % 2 == 1){
        cout <<" ";
        printHailstone(3 * number + 1);
    }
        
}