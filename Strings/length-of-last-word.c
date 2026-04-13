// Problem: Length of Last Word
// Platform: LeetCode
// Language: C
// Time Complexity: O(n)
// Space Complexity: O(1)

int lengthOfLastWord(char* s) {
    int count=0;
    int n=strlen(s);
    int i=n-1;
      while(i>=0 && s[i]==' '){
          i--;
        }
    while(i>=0 && s[i]!=' '){
          count+=1;
          i--;
        }
    return count;
}
