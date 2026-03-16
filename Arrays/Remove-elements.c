// Problem: Remove Element
// Platform: LeetCode
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
int removeElement(int* nums, int numsSize, int val) {
    int i=0;
    for(int j=0;j<numsSize;j++){
        if(nums[j]!=val){
           nums[i]=nums[j];
           i++;
        }   
    }
    return i;
}
