// Problem: Find the Index of the First Occurrence in a String
// Platform: LeetCode
// Topic: Strings
// Time Complexity: O(n*m)
// Space Complexity: O(1)
int strStr(char* haystack, char* needle) {
    int i,j;
    for( i=0;haystack[i]!='\0';i++){
        for(j=0;needle[j]!='\0';j++){
            if(haystack[i+j]!=needle[j]){
                break;
            }    
        }
        if(needle[j]=='\0'){
          return i;
        }  
    }
   return -1; 
}
