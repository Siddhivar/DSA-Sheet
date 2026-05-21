#include<bits/stdc++.h>
using namespace std;

/*Input: txt = "forxxorfxdofr", pat = "for"
Output: 3
Explanation: for, orf and ofr appears in the txt, hence answer is 3.*/
int search(string &pat, string &txt) {
    int n=txt.size();
    int k=pat.size();
    vector<int>countPat(26,0), countWindow(26,0);
    for(char c:pat){
        countPat[c-'a']++;
    }
    int result=0;
    for(int i=0;i<n;i++){
        countWindow[txt[i]-'a']++;
        if(i>=k){
            countWindow[txt[i-k]-'a']--;
        }
        if(countWindow==countPat){
            result++;
        }
    }
    return result;
}
/*Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".*/
vector<int> findAnagrams(string s, string p) {
    int n=s.size();
    int k=p.size();
    vector<int>countS(26,0), countP(26,0);
    for(char c:p){
        countP[c-'a']++;
    }
    vector<int>result;
    for(int i=0;i<n;i++){
        countS[s[i]-'a']++;
        if(i>=k){
            countS[s[i-k]-'a']--;
        }
        if(countS==countP){
            result.push_back(i+1-k);
        }
    }
    return result;
}
/*Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.*/
int minSubArrayLen(int target, vector<int>& nums) {
    int start=0, sum=0;
    int minlen=INT_MAX;
    for(int end=0;end<nums.size();end++){
        sum+=nums[end];
        while(sum>=target){
            minlen=min(minlen,end-start+1);
            sum-=nums[start];
            start++;
        }
    }
    if(minlen==INT_MAX){
        minlen=0;
    }
    return minlen;
}
/*Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.*/
vector<int> firstNegInt(vector<int>& arr, int k) {
    deque<int>dq;
    vector<int>result;
    for(int i=0;i<arr.size();i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        if(arr[i]<0){
            dq.push_back(i);
        }
        if(i>=k-1){
            if(!dq.empty()){
                result.push_back(arr[dq.front()]);
            }else{
                result.push_back(0);
            }
        }
    }
    return result;
}
/*Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int>dq;
    vector<int>result;
    for(int i=0;i<nums.size();i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[i]>nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
/*Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.*/
string minWindow(string s, string t) {
    unordered_map<char, int>need, window;
    int left=0, start=0;
    for(char c:t){
        need[c]++;
    }
    int have=0;
    int required=need.size();
    int minlen=INT_MAX;
    for(int right=0;right<s.size();right++){
        char c=s[right];
        window[c]++;
        if(need.count(c) && need[c]==window[c]){
            have++;
        }
        while(have==required){
            if(right-left+1 < minlen){
                minlen=right-left+1;
                start=left;
            }
            char leftchar=s[left];
            window[leftchar]--;
            if(need.count(leftchar) && window[leftchar]<need[leftchar]){
                have--;
            }
            left++;
        }
    }
    if(minlen==INT_MAX){
        return "";
    }
    return s.substr(start, minlen);
}
/*Input: nums = [1,2,3,1], k = 3
Output: true*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int>window;
    for(int i=0;i<nums.size();i++){
        if(window.count(nums[i])){
            return true;
        }
        window.insert(nums[i]);
        if(window.size()>k){
            window.erase(nums[i-k]);
        }
    }
    return false;
}
/*Input: nums = [1,2,3,1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.*/
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int>seen;
    for(int n:nums){
        if(seen.count(n)) return true;
        seen.insert(n);
    }
    return false;
}
/*Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].*/
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long count=0;
    int lastmin=-1, lastmax=-1, lastinvalid=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<minK || nums[i]>maxK){
            lastinvalid=i;
        }
        if(nums[i]==minK) lastmin=i;
        if(nums[i]==maxK) lastmax=i;
        int validstart=min(lastmin, lastmax);
        if(validstart>lastinvalid){
            count+=validstart-lastinvalid;
        }
    }
    return count;
}
/*Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.*/
bool isVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int maxVowels(string s, int k) {
    int count=0;
    int maxcount=0;
    for(int i=0;i<s.size();i++){
        if(isVowel(s[i])) count++;
        if(i>=k && isVowel(s[i-k])){
            count--;
        }
        if(i>=k-1){
            maxcount=max(maxcount, count);
        }
    }
    return maxcount;
}
/*Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]*/
//Using Prefix Sum
vector<int> getAverages(vector<int>& nums, int k) {
    int n=nums.size();
    if(k==0) return nums;
    vector<int>result(n,-1);
    if(n<2*k+1) return result;
    vector<long long>PrefixSum(n,0);
    PrefixSum[0]=nums[0];
    for(int i=1;i<n;i++){
        PrefixSum[i]=PrefixSum[i-1]+nums[i];
    }
    int s=(2*k)+1;
    for(int i=k;i<n-k;i++){
        int left_idx=i-k;
        int right_idx=i+k;
        long long sum=PrefixSum[right_idx];
        if(left_idx>0){
            sum-=PrefixSum[left_idx-1];
        }
        int avg=sum/s;
        result[i]=avg;
    }
    return result;
}
//Using Sliding Window
vector<int> getAverages(vector<int>& nums, int k) {
    int n=nums.size();
    if(k==0) return nums;
    vector<int>result(n,-1);
    int windowsize=2*k+1;
    if(n<windowsize) return result;
    long long sum=0;
    for(int i=0;i<windowsize;i++){
        sum+=nums[i];
    }
    result[k]=sum/windowsize;
    for(int i=windowsize;i<n;i++){
        sum+=nums[i];
        sum-=nums[i-windowsize];
        result[i-k]=sum/windowsize;
    }
    return result;
}
/*Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.*/
int longestSubarray(vector<int>& nums) {
    int zerocount=0;
    int maxlen=0;
    int left=0;
    for(int r=0;r<nums.size();r++){
        if(nums[r]==0) zerocount++;
        while(zerocount>1){
            if(nums[left]==0){
                zerocount--;
            }
            left++;
        }
        maxlen=max(maxlen, r-left);
    } 
    return maxlen;
}
/*Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.*/
int maxConsecutiveAnswers(string answerKey, int k) {
    int n=answerKey.size();
    int left=0;
    int maxlen=0;
    int countT=0, countF=0;
    for(int right=0;right<n;right++){
        if(answerKey[right]=='T') countT++;
        else countF++;
        while(min(countT,countF)>k){
            if(answerKey[left]=='T')countT--;
            else countF--;
            left++;
        }
        maxlen=max(maxlen, right-left+1);
    }
    return maxlen;
}
/*Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/
int longestOnes(vector<int>& nums, int k) {
    int left=0, zerocount=0;
    int maxlen=0;
    for(int right=0;right<nums.size();right++){
        if(nums[right]==0) zerocount++;
        while(zerocount>k){
            if(nums[left]==0) zerocount--;
            left++;
        }
        maxlen=max(maxlen, right-left+1);
    }
    return maxlen;
}
/*Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.*/
int maxFrequency(vector<int>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    int left=0;
    int maxlen=0;
    long long sum=0;
    for(int right=0;right<n;right++){
        sum+=nums[right];
        while((long long)nums[right]*(right-left+1)-sum>k){
            sum-=nums[left];
            left++;
        }
        maxlen=max(maxlen, right-left+1);
    }
    return maxlen;
}
int main(){
    return 0;
}