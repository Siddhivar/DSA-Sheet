#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end){
    if (start >= end){
        return;
    }
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1);
}

bool isPalindrome(int x) {
    if(x<0) return false;
    int temp=x;
    long long rev=0;
    while(temp>0){
        int rem=temp%10;
        rev=rev*10+rem;
        temp=temp/10;
    }
    return rev==x;
}
bool checkPalindrome(string s, int start, int end){
    if (start >= end)
        return true;
    if (s[start] != s[end]){
        return false;
    }
    return checkPalindrome(s, start + 1, end - 1);
}

// Time complexity -> O(2^n) exponential, SC-> O(n)

int findFibonacci(int n)
{
    if (n <= 1)
        return n;
    return findFibonacci(n - 1) + findFibonacci(n - 2);
}
// Time Complexity -> O(n),  SC -> O(1)

vector<int> findFibonacci2(int n)
{
    vector<int> result;
    if (n == 0)
    {
        result.push_back(0);
        return result;
    }
    if (n == 1)
    {
        result.push_back(0);
        result.push_back(1);
        return result;
    }
    int last = 1;
    int seclast = 0;
    result.push_back(seclast);
    result.push_back(last);

    for (int i = 2; i <= n; i++)
    {
        int curr = last + seclast;
        result.push_back(curr);
        seclast = last;
        last = curr;
    }
    return result;
}

int largestElement(int arr[], int n)
{
    int maxEle = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxEle)
        {
            maxEle = arr[i];
        }
    }
    return maxEle;
}

int secondLargestElement(int arr[], int n)
{
    if (n < 2)
        return -1;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    if (secondLargest == INT_MIN)
        return -1;
    return secondLargest;
}

bool checkArrayIsSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

bool checkArrayIsSorted2(int arr[], int n, int index)
{
    if (index == n)
        return true;
    if (arr[index] < arr[index - 1])
        return false;
    return checkArrayIsSorted2(arr, n, index + 1);
}

/*Input: num = 9669
Output: 9969*/
int maximum69Number (int num) {
    int temp=num;
    int pos=-1;
    int place=1;
    while(temp){
        if(temp%10==6){
            pos=place;
        }
        temp/=10;
        place*=10;
    }
    if(pos!=-1){
        num+=3*pos;
    }
    return num;
}
/*Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].*/
vector<int> leftRightDifference(vector<int>& nums) {
    int totalSum=0;
    for(int x:nums){
        totalSum+=x;
    }
    vector<int>result;
    int curr=0;
    for(int x:nums){
        int left=curr;
        curr+=x;
        int right=totalSum-curr;
        result.push_back(abs(right-left));
    }
    return result;
}

int removeDuplicates(int arr[], int n)
{
    if (n <= 1)
        return n;
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

void LeftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

void RotateByK(vector<int> &arr, int n, int k, string direction)
{
    if (direction == "left")
    {
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }
    else
    {
        reverse(arr.begin(), arr.begin() + n - k);
        reverse(arr.end() - k, arr.end());
        reverse(arr.begin(), arr.end());
    }
}

void MoveZerosAtEnd(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int LinearSearch(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}
// Using Set
vector<int> findUnion(vector<int> arr1, vector<int> arr2)
{
    set<int> s;
    for (int i = 0; i < arr1.size(); i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        s.insert(arr2[i]);
    }
    vector<int> unionArr(s.begin(), s.end());
    return unionArr;
}
//Using two pointer approach
vector<int> findUnion2(vector<int> arr1, vector<int> arr2)
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            if (result.empty() || result.back() != arr1[i])
            {
                result.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (result.empty() || result.back() != arr2[j])
            {
                result.push_back(arr2[j]);
            }
            j++;
        }
        else
        {
            if (result.empty() || result.back() != arr2[j])
            {
                result.push_back(arr2[j]);
            }
            j++;
            i++;
        }
    }
    while (i < arr1.size())
    {
        if (result.empty() || result.back() != arr1[i])
        {
            result.push_back(arr1[i]);
        }
        i++;
    }
    while (j < arr2.size())
    {
        if (result.empty() || result.back() != arr2[j])
        {
            result.push_back(arr2[j]);
        }
        j++;
    }
    return result;
}
int findMissing(vector<int>arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    int n=arr.size()+1;
    int totalSum=n*(n+1)/2;
    int missingElement=totalSum-sum;
    return missingElement;
}
int countMaxOnes(vector<int>arr){
    int maxCount=0;
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
            maxCount=max(count,maxCount);
        }else{
            count=0;
        }
    }
    return maxCount;
}
//Only works Every element appears exactly twice Except one element which appears once
int findUnique(vector<int>arr){
    int unique=0;
    for(int i=0;i<arr.size();i++){
        unique=unique^arr[i];
    }
    return unique;
}
//Trapping Rainwater Problem
int trap(vector<int>& height) {
    int left=0,right=height.size()-1;
    int leftmax=0, rightmax=0;
    int water=0;
    while(left<right){
        if(height[left]<height[right]){
            if(height[left]>=leftmax){
                leftmax=height[left];
            }else{
                water+=leftmax-height[left];
            }
            left++;
        }else{
            if(height[right]>=rightmax){
                rightmax=height[right];
            }else{
                water+=rightmax-height[right];
            }
            right--;
        }
    }
    return water;
}
/*Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].*/
vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0, j=numbers.size()-1;
    vector<int>result;
    while(i<j){
        if(numbers[i]+numbers[j]==target){
            result.push_back(i+1);
            result.push_back(j+1);
            break;
        }else if(numbers[i]+numbers[j]>target){
            j--;
        }else{
            i++;
        }
    }
    return result;
}
/*Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>result;
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size()-2;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        int j=i+1,k=nums.size()-1;
        while(j<k){
            if(nums[i]+nums[j]+nums[k]==0){
                result.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;
            }else if(nums[i]+nums[j]+nums[k]<0){
                j++;
            }else{
                k--;
            }
        }
    }
    return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>>result;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1,l=n-1;
            while(k<l){
                long long sum=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    result.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }else if(sum<target){
                    k++;
                }else{
                    l--;
                }
            }
        }
    }
    return result;
}
/*Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int mindiff=INT_MAX;
    int result=0;
    for(int i=0;i<nums.size()-2;i++){
        int j=i+1, k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(abs(sum-target)<mindiff){
                mindiff=abs(sum-target);
                result=sum;
            } 
            if(sum<target){
                j++;
            }else if(sum>target){
                k--;
            }else{
                return sum;
            }             
        }
    }
    return result;
}
/*Input: n = 5
Output: [1, 2, 0]
Explanation: 5! = 1*2*3*4*5 = 120
Since factorial grows very fast so we just cant store ans in int or even long long will fail.
So, we have to store it in vector*/
vector<int> factorial(int n) {
    vector<int>result;
    result.push_back(1);
    for(int x=2;x<=n;x++){
        int carry=0;
        for(int i=0;i<result.size();i++){
            int val=result[i]*x+carry;
            result[i]=val%10;
            carry=val/10;
        }
        while(carry>0){
            result.push_back(carry%10);
            carry=carry/10;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    int i=n-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i>=0){
        int j=n-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1, nums.end());
}
/*Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, 
the max area of water (blue section) the container can contain is 49.*/
int maxArea(vector<int>& height) {
    int n=height.size();
    int i=0,j=n-1;
    int maxArea=0;
    while(i<j){
        int minH =min(height[i], height[j]);
        maxArea=max(minH *(j-i),maxArea);
        if(height[i]<height[j]) i++;
        else j--;
    }
    return maxArea;
}
/* Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/
void sortColors(vector<int>& nums) {
    int i=0,j=0,k=nums.size()-1;
    while(j<=k){
        if(nums[j]==0){
            swap(nums[i],nums[j]);
            i++;
            j++;
        }else if(nums[j]==1){
            j++;
        }else{
            swap(nums[j],nums[k]);
            k--;
        }
    }
}
/*Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].*/
vector<int> findOriginalArray(vector<int>& changed) {
    int n=changed.size();
    if(n%2!=0) return {};
    sort(changed.begin(), changed.end());
    unordered_map<int,int>mp;
    for(int num:changed){
        mp[num]++;
    }
    vector<int>result;
    for(int num:changed){
        if(mp[num]==0) continue;
        if(num==0){
            if(mp[num]<2) return {};
        }else{
            if(mp.find(2*num)==mp.end() || mp[2*num]==0) return {};
        }
        result.push_back(num);
        mp[num]--;
        mp[2*num]--;
    }
    return result;
}
/*Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.*/
vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int evensum=0;
    for(int num:nums){
        if(num%2==0){
            evensum+=num;
        }
    }
    vector<int>result;
    for(auto q:queries){
        int val=q[0];
        int idx=q[1];
        if(nums[idx]%2==0){
            evensum-=nums[idx];
        }
        nums[idx]+=val;
        if(nums[idx]%2==0){
            evensum+=nums[idx];
        }
        result.push_back(evensum);
    }
    return result;
}
/*Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11*/
int pivotIndex(vector<int>& nums) {
    int sum=0;
    for(int num:nums){
        sum+=num;
    }
    int leftsum=0;
    int rightsum=sum;
    for(int i=0;i<nums.size();i++){
        if(i>0) leftsum+=nums[i-1];
        rightsum-=nums[i];
        if(leftsum==rightsum){
            return i;
        }
    }
    return -1;
}
/*Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.*/
bool increasingTriplet(vector<int>& nums) {
    int first=INT_MAX;
    int second=INT_MAX;
    for(int num:nums){
        if(num<=first){
            first=num;
        }else if(num<=second){
            second=num;
        }else{
            return true;
        }
    }
    return false;
}
/*Input: nums = [2,1,2]
Output: 5
Explanation: sum of two sides is > third side
if we found a<b<c then just check a+b>c */
int largestPerimeter(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    for(int i=n-3;i>=0;i--){
        if((nums[i]+nums[i+1]) > nums[i+2]){
            return (nums[i]+nums[i+1]+nums[i+2]);
        }
    }
    return 0;
}
/*Input: nums = [1,2,2,4]
Output: [2,3]*/
vector<int> findErrorNums(vector<int>& nums) {
    vector<int>result;
    int missing=-1,duplicate=-1;
    for(int i=0;i<nums.size();i++){
        int idx=abs(nums[i])-1;
        if(nums[idx]<0){
            duplicate=abs(nums[i]);
        }else{
            nums[idx]*=-1;
        }
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            missing=i+1;
        }
    }
    result.push_back(duplicate);
    result.push_back(missing);
    return result;
}
/*Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.*/
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int rem=sum%k;
        if(mp.find(rem)!=mp.end()){
            if(i-mp[rem]>=2) return true;
        }else{
            mp[rem]=i;
        }
        
    }
    return false;
}
/*Input: nums = [2,5,3,9,5,3]
Output: 3
Explanation:
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.*/
int minimumAverageDifference(vector<int>& nums) {
    int n=nums.size();
    long long  sum=0;
    for(int num:nums){
        sum+=num;
    }
    int minDiff=INT_MAX;
    long long leftsum=0;
    int idx=-1;
    for(int i=0;i<n;i++){
        leftsum+=nums[i];
        long long leftavg=leftsum/(i+1);
        long long rightavg=0;
        if(i!=n-1){
            rightavg=(sum-leftsum)/(n-i-1);
        }
        int diff=abs(leftavg- rightavg);
        if(diff<minDiff){
            minDiff=diff;
            idx=i;
        }
    }
    return idx;
}
/*Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.*/
int maxSum(vector<int>&nums){
    int sum=nums[0];
    int maxsum=nums[0];
    for(int i=1;i<nums.size();i++){
        sum=max(sum+nums[i], nums[i]);
        maxsum=max(sum,maxsum);
    }
    return maxsum;
}
int minSum(vector<int>&nums){
    int sum=nums[0];
    int minsum=nums[0];
    for(int i=1;i<nums.size();i++){
        sum=min(sum+nums[i], nums[i]);
        minsum=min(sum,minsum);
    }
    return minsum;
}
int maxSubarraySumCircular(vector<int>& nums) {
    int totalsum=0;
    for(int i=0;i<nums.size();i++){
        totalsum+=nums[i];
    }
    int minsum=minSum(nums);
    int maxsum=maxSum(nums);
    int circularsum=totalsum-minsum;
    if(maxsum>0){
        return max(maxsum, circularsum);
    }
    return maxsum;
}
/*Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]*/
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int rem=sum%k;
        if(rem<0) rem+=k;
        if(mp.find(rem)!=mp.end()){
            count+=mp[rem];
        }
        mp[rem]++;
    }
    return count;
}
int findJudge(int n, vector<vector<int>>& trust) {
    vector<int>score(n+1,0);
    for(auto &t:trust){
        score[t[0]]--;
        score[t[1]]++;
    }
    for(int i=1;i<=n;i++){
        if(score[i]==n-1){
            return i;
        }
    }
    return -1;
}

/*Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)*/
int numSubseq(vector<int>& nums, int target) {
    const int MOD=1e9+7;
    sort(nums.begin(),nums.end());
    vector<long long>pow2(nums.size());
    pow2[0]=1;
    for(int i=1;i<nums.size();i++){
        pow2[i]=(pow2[i-1]*2)%MOD;
    }
    int l=0;
    int r=nums.size()-1;
    long long subseq=0;
    while(l<=r){
        if(nums[l]+nums[r]<=target){
            subseq=(subseq+pow2[r-l])%MOD;
            l++;
        }else{
            r--;
        }
    }
    return int(subseq);
}

/*Input: nums = [1,2,1,3]
Output: 2
Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).*/
int numberOfGoodPartitions(vector<int>& nums) {
    int n=nums.size();
    const int MOD=1e9+7;
    unordered_map<int,int>last;
    for(int i=0;i<n;i++){
        last[nums[i]]=i;
    }
    int end=0;
    int group=0;
    for(int i=0;i<n;i++){
        end=max(end,last[nums[i]]);
        if(i==end){
            group++;
        }
    }
    long long ans=1;
    for(int i=0;i<group-1;i++){
        ans=(ans*2)%MOD;
    }
    return (int)ans;
}

/*Input: arr = [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: arr = [3, 2, 4, 1]
After 1st flip (k = 4): arr = [1, 4, 2, 3]
After 2nd flip (k = 2): arr = [4, 1, 2, 3]
After 3rd flip (k = 4): arr = [3, 2, 1, 4]
After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.*/
vector<int> pancakeSort(vector<int>& arr) {
    int n=arr.size();
    vector<int>ans;
    for(int size=n;size>1;size--){
        int maxIdx=0;
        for(int i=1;i<size;i++){
            if(arr[i]>arr[maxIdx]){
                maxIdx=i;
            }
        }
        if (maxIdx==size-1) continue;
        reverse(arr.begin(),arr.begin()+maxIdx+1);
        ans.push_back(maxIdx+1);
        reverse(arr.begin(),arr.begin()+size);
        ans.push_back(size);
    }
    return ans;
}

/*Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I*/
string convert(string s, int numRows) {
    if(numRows==1 || numRows>s.size()){
        return s;
    }
    vector<string>rows(numRows);
    int currRow=0;
    bool goingDown=true;
    for(char ch:s){
        rows[currRow]+=ch;
        if(currRow==0){
            goingDown=true;
        }else if(currRow==numRows-1){
            goingDown=false;
        }
        if(goingDown){
            currRow+=1;
        }else{
            currRow-=1;
        }
    }
    string ans;
    for(string &row:rows){
        ans+=row;
    }
    return ans;
}

/*Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.*/
long long zeroFilledSubarray(vector<int>& nums) {
    long long ans=0;
    long long curr=0;
    for(int x:nums){
        if(x==0){
            curr++;
            ans+=curr;
        }else{
            curr=0;
        }
    }
    return ans;
}

/*Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.*/
int maxWidthRamp(vector<int>& nums) {
    int n=nums.size();
    vector<int>maxRight(n);
    maxRight[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--){
        maxRight[i]=max(nums[i],maxRight[i+1]);
    }
    int i=0;
    int j=0;
    int maxRamp=0;
    while(i<n && j<n){
        if(nums[i]<=maxRight[j]){
            maxRamp=max(maxRamp,j-i);
            j++;
        }else{
            i++;
        }
    }
    return maxRamp;
}
int main()
{
    vector<int>arr={4,1,2,1,2};
    cout<<"Unique Element is: "<< findUnique(arr)<<endl;
    return 0;
}