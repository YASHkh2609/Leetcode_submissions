/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int n=numsSize;
    *returnSize=numsSize;
    int *ans=(int*)malloc(sizeof(int)*(*returnSize));
    int prefix_prod[n];
    int suffix_prod[n];
    prefix_prod[0]=1;
    for(int i=1;i<n;i++){
        prefix_prod[i]=prefix_prod[i-1]*nums[i-1];
    }
    suffix_prod[n-1]=1;
    for(int i=n-2;i>=0;i--){
        suffix_prod[i]=suffix_prod[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++){
        ans[i]=prefix_prod[i]*suffix_prod[i];
    }
    return ans;
}