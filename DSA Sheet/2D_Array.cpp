#include <bits/stdc++.h>
using namespace std;
/*1.Transpose
2.Reverse*/
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>result;
    int left=0, right=matrix[0].size()-1;
    int top=0, down=matrix.size()-1;
    while(top<=down && left<=right){
        //left to right
        for(int i=left;i<=right;i++){
            result.push_back(matrix[top][i]);
        }
        top++;
        //from top to down
        for(int i=top;i<=down;i++){
            result.push_back(matrix[i][right]);
        }
        right--;
        // right to left
        if(top<=down){
            for(int i=right;i>=left;i--){
                result.push_back(matrix[down][i]);
            }
        }
        down--;
        //down to top
        if(left<=right){
            for(int i=down;i>=top;i--){
                result.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return result;
}
/*
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
Keep remember if the diagonal is top to bottom then [i-j] is same
and if the diagonal is bottom to top then [i+j] is same
*/
vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m=mat[0].size();
    int n=mat.size();
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i-j].push_back(mat[i][j]);
        }
    }
    for(auto &it:mp){
        sort(it.second.begin(), it.second.end());
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            mat[i][j]=mp[i-j].back();
            mp[i-j].pop_back();
        }
    }
    return mat;
}
/*Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]*/
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    vector<int>result;
    map<int, vector<int>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i+j].push_back(mat[i][j]);
        }
    }
    bool flip=true;
    for(auto &it:mp){
        if(flip){
            reverse(it.second.begin(), it.second.end());
        }
        for(int &num:it.second){
            result.push_back(num);
        }
        flip=!flip;
    }
    return result;
}
/*Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3*/
int countOverlaps(vector<vector<int>>A, vector<vector<int>>B, int row, int col){
    int n=A.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int bi=i+row;
            int bj=j+col;
            if(bi<0 ||bi>=n ||bj<0 ||bj>=n) continue;
            if(A[i][j]==1 && B[bi][bj]==1){
                count++;
            }
        }
    }
    return count;
}
int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int n=img1.size();
    int maxOverlap=0;
    for(int rowOff=-n+1; rowOff<n; rowOff++){
        for(int colOff=-n+1; colOff<n; colOff++){
            int count=countOverlaps(img1, img2, rowOff, colOff);
            maxOverlap=max(count, maxOverlap);
        }
    }
    return maxOverlap;
}
/*Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.*/
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=matrix[i-1][j-1]) return false;
        }
    }
    return true;
}
/*Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]
Explanation: This example is shown in the photo.
Ball b0 is dropped at column 0 and falls out of the box at column 1.
Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.*/
vector<int> findBall(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    vector<int>result;
    for(int ball=0;ball<c;ball++){
        int row=0;
        int col=ball;
        bool stuck=false;
        while(row<r && col<c){
            if(grid[row][col]==1){
                if( col==c-1 || grid[row][col+1]==-1){
                    stuck=true;
                    break;
                }
                col++;
            }else{
                if(col==0 || grid[row][col-1]==1){
                    stuck=true;
                    break;
                }
                col--;
            }
            row++;
        }
        if(stuck) result.push_back(-1);
        else result.push_back(col);    
    }
    return result;
}
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0;i<9;i++){
        vector<int>freq(9,0);
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                int num=board[i][j]-'1';
                freq[num]++;
                if(freq[num]>1) return false;
            }             
        }
    }
    for(int i=0;i<9;i++){
        vector<int>freq(9,0);
        for(int j=0;j<9;j++){
            if(board[j][i]!='.'){
                int num=board[j][i]-'1';
                freq[num]++;
                if(freq[num]>1) return false;
            }             
        }
    }
    for(int row=0;row<9;row+=3){
        for(int col=0;col<9;col+=3){
            vector<int>freq(9,0);
            for(int i=row;i<row+3;i++){
                for(int j=col;j<col+3;j++){
                    if(board[i][j]!='.'){
                        int num=board[i][j]-'1';
                        freq[num]++;
                        if(freq[num]>1) return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){

}