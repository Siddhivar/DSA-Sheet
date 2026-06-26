#include <bits/stdc++.h>
using namespace std;

/*Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.*/
int bagOfTokensScore(vector<int>& tokens, int power) {
    int n=tokens.size();
    int maxScore=0;
    sort(tokens.begin(), tokens.end());
    int i=0,j=n-1;
    int score=0;
    while(i<=j){
        if(power>=tokens[i]){
            power-=tokens[i];
            score++;
            i++;
            maxScore=max(maxScore,score);
        }else if(score>0){
            power+=tokens[j];
            score--;
            j--;
        }else{
            return maxScore;
        }
    }
    return maxScore;
}

/* each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time,
provided the sum of the weight of those people is at most limit.*/
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(),people.end());
    int i=0,j=people.size()-1;
    int boats=0;
    while(i<=j){
        if(people[i]+people[j]<=limit){
            i++;
            j--;
        }else{
            j--;
        }
        boats++;
    }
    return boats;
}

/*Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.*/
string breakPalindrome(string palindrome) {
    int s=palindrome.size();
    if(s==1){
        return "";
    }
    for(int i=0;i<s/2;i++){
        if(palindrome[i]!='a'){
            palindrome[i]='a';
            return palindrome;
        }
    }
    palindrome[s-1]='b';
    return palindrome;
}
/*multiply the number on display by 2, or
subtract 1 from the number on display.*/
int brokenCalc(int startValue, int target) {
    int operations=0;
    while(target>startValue){
        if(target%2==0){
            target/=2;
        }else{
            target++;
        }
        operations++;
    }
    return operations+(startValue-target);
}

/*Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.*/
int minCost(string colors, vector<int>& neededTime) {
    int n=colors.size();
    int totalTime=0;
    for(int t:neededTime){
        totalTime+=t;
    }
    int keep=0;
    int i=0;
    while(i<n){
        char ballon=colors[i];
        int time=0;
        while(i<n && colors[i]==ballon){
            time=max(time,neededTime[i]);
            i++;
        }
        keep+=time;
    }
    return totalTime-keep;
}

/*Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
Output: 3
Explanation:
Place 1 rock in bag 0 and 1 rock in bag 1.
The number of rocks in each bag are now [2,3,4,4].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that there may be other ways of placing the rocks that result in an answer of 3.*/
int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n=capacity.size();
    int fullCapacity=0;
    vector<int>gap;
    for(int i=0;i<n;i++){
        gap.push_back(capacity[i]-rocks[i]);
    }
    sort(gap.begin(),gap.end());
    for(int i=0;i<gap.size();i++){
        if(gap[i]==0){
            fullCapacity++;
        }else{
            if(additionalRocks>=gap[i]){
                additionalRocks-=gap[i];
                fullCapacity++;
            }else{
                break;
            }
        }
    }
    return fullCapacity;
}

/*Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.*/
int minimumRounds(vector<int>& tasks) {
    unordered_map<int,int>mp;
    for(int t:tasks){
        mp[t]++;
    }
    int rounds=0;
    for(auto it:mp){
        int count=it.second;
        if(count==1) return -1;
        if(count%3==0){
            rounds+=count/3;
        }else{
            rounds+=(count/3)+1;
        }
    }
    return rounds;
}
int main(){
    return 0;
}