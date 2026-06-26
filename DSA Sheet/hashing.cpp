#include <bits/stdc++.h>
using namespace std;

void countFrequency(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto it : freq)
    {
        cout << it.first << " : " << it.second << endl;
    }
}

void maxMinFrequency(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int maxFreq = 0, minFreq = n;
    int maxEle = -1, minEle = -1;
    for (auto it : freq)
    {
        int element = it.first;
        int count = it.second;
        if (count > maxFreq)
        {
            maxFreq = count;
            maxEle = element;
        }
        if (count < minFreq)
        {
            minFreq = count;
            minEle = element;
        }
    }
    cout << "Max Element is: " << maxEle << endl;
    cout << "Min Element is: " << minEle << endl;
}

/*Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].*/
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int,int>loserMap;
    for(auto &match:matches){
        int w=match[0];
        int l=match[1];
        loserMap[w]+=0;
        loserMap[l]++;
    }
    vector<vector<int>>result(2);
    for(auto it:loserMap){
        if(it.second==0){
            result[0].push_back(it.first);
        }else if(it.second==1){
            result[1].push_back(it.first);
        }
    }
    return result;
}

/*Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.*/
bool uniqueOccurrences(vector<int>& arr) {
    vector<int>vec(2001,0);
    for(int x:arr){
        vec[x+1000]++;
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<vec.size();i++){
        if(vec[i]==0) continue;
        if(vec[i]==vec[i-1]){
            return false;
        }
    }
    return true;
}

/*Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation: 'a' maps to "dog".
'b' maps to "cat".*/
bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    string word;
    vector<string>words;
    while(ss>>word){
        words.push_back(word);
    }
    if(pattern.size()!=words.size()) return false;
    unordered_map<char,string>charToWord;
    unordered_map<string,char>wordToChar;
    for(int i=0;i<pattern.size();i++){
        char ch=pattern[i];
        string word=words[i];
        if(charToWord.count(ch) && charToWord[ch]!=word){
            return false;
        }
        if(wordToChar.count(word) && wordToChar[word]!=ch){
            return false;
        }
        charToWord[ch]=word;
        wordToChar[word]=ch;
    }
    return true;
}
int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, size);
    maxMinFrequency(arr, size);
    return 0;
}