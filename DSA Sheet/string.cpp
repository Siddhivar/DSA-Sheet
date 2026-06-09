#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    string result="";
    int balance=0;
    for(char c:s){
        if(c=='('){
            if(balance>0){
                result+=c;
            }
            balance++;
        }else{
            balance--;
            if(balance>0){
                result+=c;
            }
        }
    }
    return result;
}
/*Input: s = "leetcode"
Output: "leotcede"*/
string reverseVowels(string s) {
    int i=0, j=s.length()-1;
    string vowels="aeiouAEIOU";
    while(i<=j){
        while(i<j && vowels.find(s[i])==string::npos){
            i++;
        }
        while(i<j && vowels.find(s[j])==string::npos){
            j--;
        }
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}

/*Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]*/
int removeDuplicates(vector<int>& nums) {
    int i=0;
    for(int j=1;j<nums.size();j++){
        if(nums[j]!=nums[i]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;
}

/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.*/
bool isPalindrome(string s, int l, int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
bool validPalindrome(string s) {
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1);
        }
    }
    return true;
}

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string>words;
    while(ss>>word){
        words.push_back(word);
    }
    string result="";
    for(int i=words.size()-1;i>=0;i--){
        result+=words[i];
        if(i!=0){
            result+=" ";
        }
    }
    return result;
}
string largestOddNumber(string num) {
    string ans="";
    int idx=-1;
    for(int i=num.size()-1;i>=0;i--){
        if(int(num[i])%2!=0 ){
            idx=i;
            break;
        }
    }
    return num.substr(0,idx+1);
}
string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end());
    string a=strs[0];
    string b=strs[strs.size()-1];
    int len=min(a.size(),b.size());
    int i=0;
    while(i<len && a[i]==b[i]){
        i++;
    }
    return a.substr(0,i);
}
bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size()) return false;
    unordered_map<char,int>m1,m2;
    for(int i=0;i<s.size();i++){
        if(m1.find(s[i])==m1.end()){
            m1[s[i]]=i;
        }
        if(m2.find(t[i])==m2.end()){
            m2[t[i]]=i;
        }
        if(m1[s[i]]!=m2[t[i]]) return false;
    }
    return true;
}
bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return false;
    string newstr=goal+goal;
    return (newstr.find(s)!=string::npos);
}
bool isAnagram(string s, string t) {
    unordered_map<char,int>freq;
    for(char ch:s){
        freq[ch]++;
    }
    for(char ch:t){
        freq[ch]--;
    }
    for(auto x:freq){
        if(x.second!=0){
            return false;
        }
    }
    return true;
}
string frequencySort(string s) {
    string ans="";
    vector<pair<char,int>>newvec;
    unordered_map<char,int>freq;
    for(char ch:s){
        freq[ch]++;
    }
    for(auto x:freq){
        newvec.push_back(x);
    }
    sort(newvec.begin(),newvec.end(),[](pair<char,int>a,pair<char,int>b){
        return a.second>b.second;
    });
    for(int i=0;i<newvec.size();i++){
        while(newvec[i].second--){
            ans+=newvec[i].first;
        }
    }
    return ans;
}
int maxDepth(string s) {
    int count=0,maxcount=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            count++;
        }
        if(s[i]==')'){
            count--;
        }
        maxcount=max(count,maxcount);
    }
    return maxcount;
}
/*Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

So first we are implementing using sorting
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>result;
    if(strs.empty()) return result;
    unordered_map<string, vector<string>>mp;
    for(int i=0;i<strs.size();i++){
        string temp=strs[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(strs[i]);
    }
    for(auto it:mp){
        result.push_back(it.second);
    }
    return result;
}
//Without Sorting
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>result;
    if(strs.empty()) return result;
    unordered_map<string, vector<string>>mp;
    for(string s:strs){
        vector<char>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        string key="";
        for(int i=0;i<26;i++){
            key+="%";
            key+=to_string(freq[i]);
        }
        mp[key].push_back(s);
    }
    for(auto it:mp){
        result.push_back(it.second);
    }
    return result;
}
/*Input: chars = ["a","a","b","b","c","c","c"]
Output: 6
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3". */
int compress(vector<char>& chars) {
    int n=chars.size();
    int i=0;
    int idx=0;
    while(i<n){
        char curr=chars[i];
        int count=0;
        while(i<n && chars[i]==curr){
            i++;
            count++;
        }
        chars[idx++]=curr;
        if(count>1){
            string cnt=to_string(count);
            for(char c:cnt){
                chars[idx++]=c;
            }
        }
    }
    return idx;
}
bool checkIfPangram(string sentence) {
    vector<int>alpha(26,0);
    for(char s:sentence){
        alpha[s-'a']++;
    }
    for(int i=0;i<26;i++){
        if(alpha[i]==0){
            return false;
        }
    }
    return true;
}
/*Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"*/
string countAndSay(int n) {
    if(n==1) return "1";
    string say=countAndSay(n-1);
    string result="";
    for(int i=0;i<say.length();i++){
        char ch=say[i];
        int count=1;
        while(i<say.length()-1 && say[i]==say[i+1]){
            count++;
            i++;
        }
        result+=to_string(count);
        result+=ch;
    }
    return result;;
}
/*Input: num = 3749
Output: "MMMDCCXLIX"
Explanation:
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places*/
string intToRoman(int num) {
    static vector<int>values={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    static vector<string>symbols={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string result;
    for(int i=0;i<13;i++){
        if(num==0) break;
        int times=num/values[i];
        while(times--){
            result+=symbols[i];
        }
        num=num%values[i];
    }
    return result;
}
/*Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.*/
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string concat1="", concat2="";
    for(string w:word1){
        concat1+=w;
    }
    for(string w:word2){
        concat2+=w;
    }
    return concat1==concat2;
}
/*Input: s = "cba", k = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".

If k=1 -> brute force
if k>1 -> sort the string and return it
*/
string orderlyQueue(string s, int k) {
    if(k>1){
        sort(s.begin(),s.end());
        return s;
    } 
    string result=s;
    for(int i=1;i<=s.length()-1;i++){
        string temp=s.substr(i)+s.substr(0,i);
        result=min(result,temp);
    }
    return result; 
}
/*Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".*/
string makeGood(string s) {
    string result;
    for(char ch:s){
        if(!result.empty() && abs(result.back()-ch)==32){
            result.pop_back();
        }else{
            result.push_back(ch);
        }
    }
    return result;
}
/*Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.*/
bool halvesAreAlike(string s) {
    int n=s.length();
    int count=0;
    string vowels="aeiouAEIOU";
    for(int i=0;i<n/2;i++){
        if(vowels.find(s[i])!= string::npos) count++;
        if(vowels.find(s[i+n/2])!= string::npos) count--;
    }
    return count==0;
}
/*Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"*/
bool closeStrings(string word1, string word2) {
    if(word1.length()!=word2.length()) return false;
    vector<int>freq1(26,0);
    vector<int>freq2(26,0);
    for(char ch:word1){ 
        freq1[ch-'a']++;
    }
    for(char ch:word2){
        freq2[ch-'a']++;
    }
    for(int i=0;i<26;i++){
        if((freq1[i]==0 && freq2[i]!=0) || (freq1[i]!=0 && freq2[i]==0)) return false;
    }
    sort(freq1.begin(),freq1.end());
    sort(freq2.begin(), freq2.end());
    return freq1==freq2;
}
/*All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".*/
bool detectCapitalUse(string word) {
    int n=word.size();
    int capitalCount=0;
    for(char w:word){
        if(isupper(w)) capitalCount++;
    }
    return (capitalCount==n)||(capitalCount==0)||(capitalCount==1 && isupper(word[0]));
}
/*Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.*/
int minDeletionSize(vector<string>& strs) {
    int count=0;
    for(int i=0;i<strs[0].length();i++){
        for(int j=1;j<strs.size();j++){
            if(strs[j][i]<strs[j-1][i]){
                count++;
                break;
            }
        }
    }
    return count;
}

/*Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.*/
int removePairs(string& s, char first, char sec, int gain){
    string temp="";
    int result=0;
    for(char ch:s){
        if(!temp.empty() && ch==sec && temp.back()==first ){
            temp.pop_back();
            result+=gain;
        }else temp.push_back(ch);
    }
    s=temp;
    return result;
}
int maximumGain(string s, int x, int y) {
    int result=0;
    if(x>y){
        result+=removePairs(s,'a','b',x);
        result+=removePairs(s,'b','a',y);
    }else{
        result+=removePairs(s,'b','a',y);
        result+=removePairs(s,'a','b',x);
    }
    return result;
}
int main(){
    
}