// class Solution {
// private:
//     void Merge(vector<int>&nums, int l, int mid, int r){
//         vector<int>temp;
//         int left=0;
//         int right =mid+1;

//         while(left<=mid && right<=r){
//             if(nums[left]<=nums[right]){
//                 temp.push_back(nums[left]);
//                 left++;
//             }
//             else{
//                 temp.push_back(nums[right]);
//                 right++;
//             }
//         }
//         while(left<=mid){
//             temp.push_back(nums[left]);
//             left++;
//         }
//         while(right<=r){
//             temp.push_back(nums[right]);
//             right++;
//         }

//         for(int i=l;i<=r;i++){
//             nums[i]=temp[i-l];
//         }
//     }
//     void mergeSort(vector<int>&nums, int l, int r){
//         if(l<r){
//             int mid = (l+r)/2;
//             mergeSort(nums, l, mid);
//             mergeSort(nums, mid+1, r);
//             Merge(nums, l, mid, r);
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         int n=nums.size();
//         mergeSort(nums, 0, n-1);    
//         return nums;    
//     }
// };

void merge(vector<int>& array, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> left_part(n1), right_part(n2);

    for (int i = 0; i < n1; ++i)
        left_part[i] = array[low + i];
    for (int i = 0; i < n2; ++i)
        right_part[i] = array[mid + 1 + i];

    int p1 = 0, p2 = 0, write_ind = low;
    while (p1 < n1 && p2 < n2) {
        if (left_part[p1] <= right_part[p2]) {
            array[write_ind] = left_part[p1++];
        } else {
            array[write_ind] = right_part[p2++];
        }
        ++write_ind;
    }

    while (p1 < n1)
        array[write_ind++] = left_part[p1++];

    while (p2 < n2)
        array[write_ind++] = right_part[p2++];
}

void merge_sort(vector<int>& array, int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);
    merge(array, low, mid, high);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};