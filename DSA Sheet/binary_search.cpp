#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int start = 0;
    int last = nums.size() - 1;
    int mid = start + (last - start) / 2;
    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}
// First index i where arr[i]>=x
int lowerBound(vector<int> &nums, int target)
{
    int start = 0;
    int last = nums.size() - 1;
    int lowerBound = nums.size();
    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            lowerBound = mid;
            last = mid - 1;
        }
    }
    return lowerBound;
}
// First index i where arr[i]>x
int upperBound(vector<int> &nums, int target)
{
    int start = 0;
    int last = nums.size() - 1;
    int lowerBound = nums.size();
    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        if (nums[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            lowerBound = mid;
            last = mid - 1;
        }
    }
    return lowerBound;
}
void FloorAndCeil(vector<int> &nums, int target)
{
    int n = nums.size();
    int idx = lowerBound(nums, target);
    int floorval = -1;
    int ceilval = -1;
    if (idx < n)
    {
        ceilval = nums[idx];
    }
    if (idx < n && nums[idx] == target)
    {
        floorval = nums[idx];
    }
    else if (idx > 0)
    {
        floorval = nums[idx - 1];
    }
    cout << floorval << " " << ceilval << endl;
}
int countOccurrences(vector<int> &arr, int target)
{
    int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

    if (first == arr.size() || arr[first] != target)
        return 0;

    return last - first;
}
//If arr has no duplicate elements
//1️⃣ Find mid
//2️⃣ Check which half is sorted
//3️⃣ Check if target lies in that sorted half
//4️⃣ Move accordingly
int searchElement(vector<int> &arr, int target)
{
    int s = 0;
    int l = arr.size() - 1;
    while (s <= l)
    {
        int mid = s + (l - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[s] <= arr[mid])
        {
            // left half sorted
            if (target > arr[s] && target < arr[mid])
            {
                l = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        // right half sorted
        else
        {
            if (target > arr[mid] && target < arr[l])
            {
                s = mid + 1;
            }
            else
            {
                l = mid - 1;
            }
        }
    }
    return -1;
}
//If arr has duplicate elements
//Find mid
//If nums[left] == nums[mid] == nums[right] → shrink both sides
//Otherwise, one half must be sorted
int searchElement2(vector<int> &arr, int target)
{
    int s = 0;
    int l = arr.size() - 1;
    while (s <= l)
    {
        int mid = s + (l - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[s] == arr[mid] && arr[mid]==arr[l])
        {
            s++;
            l--;
        }
        if (arr[s] <= arr[mid])
        {
            // left half sorted
            if (target >= arr[s] && target < arr[mid])
            {
                l = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        // right half sorted
        else
        {
            if (target > arr[mid] && target <= arr[l])
            {
                s = mid + 1;
            }
            else
            {
                l = mid - 1;
            }
        }
    }
    return -1;
}
int findMin(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right]){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return nums[left];
}
int findMinEleIdx(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right]){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}
int findRotatedTime(vector<int>&nums){
    int smallestIdx=findMinEleIdx(nums);
    return smallestIdx;
}
//Before single → pairs start at even index
//After single → pairs start at odd index
int singleNonDuplicate(vector<int>& arr) {
    int left=0;
    int right=arr.size()-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                left=mid+1;
            }else{
                right=mid;
            }
        }else{
            if(arr[mid]==arr[mid-1]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
    }
    return arr[left];
}
int findPeak(vector<int>nums){
    int l=0;
    int r=nums.size()-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(nums[mid]<nums[mid+1]){
            l=mid+1;
        }else{
            r-mid;
        }
    }
    return l;
}
/*Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.*/
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<int>result;
    vector<int>prefixSum(n);
    prefixSum[0]=nums[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    for(int q:queries){
        int idx= upper_bound(prefixSum.begin(), prefixSum.end(),q)-prefixSum.begin();
        result.push_back(idx);
    }
    return result;
}
int main()
{
    vector<int> nums = {3,4,5,1,2};
    int target = 1;
    // cout<<"Lower Bound: "<<lowerBound(nums,target)<<endl;
    // cout<<"Upper Bound: "<<upperBound(nums,target)<<endl;
    // FloorAndCeil(nums,target);
    // cout << countOccurrences(nums, target) << endl;

    cout<<findRotatedTime(nums);
    return 0;
}