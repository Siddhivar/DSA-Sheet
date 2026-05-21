#include <bits/stdc++.h>
using namespace std;
/*Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].*/
int findMinArrowShots(vector<vector<int>>& points) {
    int n=points.size();
    sort(points.begin(), points.end());
    vector<int>prev=points[0];
    int count=1;
    for(int i=1;i<n;i++){
        int currStartPoint=points[i][0];
        int currEndPoint=points[i][1];
        int prevStartPoint=prev[0];
        int prevEndPoint=prev[1];
        if(currStartPoint>prevEndPoint){
            count++;
            prev=points[i];
        }else{
            prev[0]=max(prevStartPoint, currStartPoint);
            prev[1]=min(prevEndPoint,currEndPoint);
        }
    }
    return count;
}

/*Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].*/
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int n=intervals.size();
    int i=0;
    while(i<n){
        if(intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
        }else if(intervals[i][0]>newInterval[1]) {
            break;
        }else{
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
        }
        i++;
    }
    result.push_back(newInterval);
    while(i<n){
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}