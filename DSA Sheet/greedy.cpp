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
int main(){
    return 0;
}