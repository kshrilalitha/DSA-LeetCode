//problem: Palindrome Number
//Language: C
//Approach: Reverse the number
//Time Complexity: O(log n)
bool isPalindrome(int x) {
    if(x<0)
     return false;
    int original=x;
    long reverse=0;
    while(x>0){
        int num=x%10;
        reverse=reverse*10+num;
        x=x/10;
    } 
    if(original==reverse)
       return true;
    else
       return false;   
}
