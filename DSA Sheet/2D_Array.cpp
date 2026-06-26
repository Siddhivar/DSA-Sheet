#include <bits/stdc++.h>
using namespace std;

//Pascal Triangle
vector<vector<int>> generate(int numRows) {
    vector<vector<int>>result(numRows);
    for(int i=0;i<numRows;i++){
        result[i]=vector<int>(i+1,1);
        for(int j=1;j<i;j++){
            result[i][j]=result[i-1][j]+result[i-1][j-1];
        }
    }
    return result;
}

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
//Spiral Matrix I
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

/* Spiral Matrix II
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]*/
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>result(n, vector<int>(n));
    int left=0,right=n-1;
    int top=0,down=n-1;
    int val=1;
    while(top<=down && left<=right){
        for(int i=left;i<=right;i++){
            result[top][i]=val++;
        }
        top++;
        for(int i=top;i<=down;i++){
            result[i][right]=val++;
        }
        right--;
        if(top<=down){
            for(int i=right;i>=left;i--){
                result[down][i]=val++;
            }
            down--;
        }
        if(left<=right){
            for(int i=down;i>=top;i--){
                result[i][left]=val++;
            }
            left++;
        }
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
//SC->O(1)
void setZeroes(vector<vector<int>>& matrix) {
    int r=matrix.size();
    int c=matrix[0].size();
    bool firstCol=false;
    for(int i=0;i<r;i++){
        if(matrix[i][0]==0){
            firstCol=true;
        }
        for(int j=1;j<c;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=1;j--){
            if(matrix[i][0]==0||matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
        if(firstCol){
            matrix[i][0]=0;
        }
    }
}

/*Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).*/
bool dfs(vector<vector<int>>& grid,int i, int j){
    int m=grid.size();
    int n=grid[0].size();
    if(i<0 || i>=m || j<0 || j>=n) return false;
    if(grid[i][j]==1) return true;
    grid[i][j]=1;
    bool up=dfs(grid,i-1,j);
    bool down=dfs(grid,i+1,j);
    bool left=dfs(grid,i,j-1);
    bool right=dfs(grid,i,j+1);
    return (up && down && left && right);
}
int closedIsland(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                if(dfs(grid,i,j)){
                    ans++;
                }
            }
        }
    }
    return ans;
}

/*Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.*/
void dfs(vector<vector<int>>& grid, int i, int j){
    int m=grid.size();
    int n=grid[0].size();
    if(i<0 || i>=m || j<0 || j>=n) return;
    if(grid[i][j]==0) return;
    grid[i][j]=0;
    dfs(grid,i-1,j);
    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);

}
int numEnclaves(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    for(int i=0;i<m;i++){
        if(grid[i][0]==1){
            dfs(grid,i,0);
        }
        if(grid[i][n-1]==1){
            dfs(grid,i,n-1);
        }
    }
    for(int j=0;j<n;j++){
        if(grid[0][j]==1){
            dfs(grid,0,j);
        }
        if(grid[m-1][j]==1){
            dfs(grid,m-1,j);
        }
    }
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
int main(){

}