//Problem: Two Sum
//Language: C
//Approach: Rrute Force
//Time Complexity: O(n^2)
//Space Comlexity: O(1)

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int result[2];
    *returnSize=2;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
               result[0]=i;
               result[1]=j;
               return result;
            }  
        }
    }
return result;
}
