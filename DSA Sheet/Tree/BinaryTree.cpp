#include <bits/stdc++.h>
using namespace std;

//BFS
vector<int> rightSideView(TreeNode* root) {
    vector<int>result;
    if(!root) return result;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        TreeNode* curr=NULL;
        while(n--){
            curr=q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        result.push_back(curr->val);
    }
    return result;
}

//DFS
void preOrder(TreeNode* root, int level, vector<int>&result){
    if(!root) return;
    if(result.size()<level){
        result.push_back(root->val);
    }
    preOrder(root->right, level+1, result);
    preOrder(root->left, level+1, result);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int>result;
    if(!root) return result;
    preOrder(root,1,result);
    return result;
}

/*Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]*/
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx){
    if(start>end) return NULL;
    int rootVal=preorder[idx];
    int i=start;
    for(;i<=end;i++){
        if(inorder[i]==rootVal) break;
    }
    idx++;
    TreeNode* root=new TreeNode(rootVal);
    root->left=solve(preorder,inorder,start,i-1,idx);
    root->right=solve(preorder,inorder,i+1,end,idx);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=preorder.size();
    int idx=0;
    return solve(preorder, inorder, 0,n-1,idx);
}

/*Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]*/
TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int& idx){
    if(start>end) return NULL;
    int rootVal=postorder[idx];
    int i=start;
    for(;i<=end;i++){
        if(inorder[i]==rootVal) break;
    }
    idx--;
    TreeNode* newRoot=new TreeNode(rootVal);
    newRoot->right=solve(inorder,postorder,i+1,end,idx);
    newRoot->left=solve(inorder,postorder,start,i-1,idx);
    return newRoot;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=inorder.size();
    int idx=n-1;
    return solve(inorder, postorder, 0,n-1, idx);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL) return NULL;
    if(root==p|| root==q) return root;
    TreeNode* left=lowestCommonAncestor(root->left, p, q);
    TreeNode* right=lowestCommonAncestor(root->right, p, q);
    if(left!=NULL && right!=NULL) return root;
    if(left!=NULL) return left;
    return right;
}

//BFS
bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    bool seenNull=false;
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr==NULL){
            seenNull=true;
        }else{
            if(seenNull==true){
                return false;
            }else{
                q.push(curr->left);
                q.push(curr->right);
            }
        } 
    }
    return true;
}
//DFS
int countNodes(TreeNode* root){
    if(root==NULL) return 0;
    return 1 + countNodes(root->left)+countNodes(root->right);
}
bool dfs(TreeNode* root, int idx, int totalNodes){
    if(root==NULL) return true;
    if(idx>totalNodes) return false;
    return dfs(root->left,2*idx, totalNodes) && dfs(root->right,2*idx+1, totalNodes);
}
bool isCompleteTree(TreeNode* root) {
    int totalNodes=countNodes(root);
    int i=1;
    return dfs(root, 1,totalNodes);
}

/*Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]] */
vector<TreeNode*>result;
TreeNode* deleteNodes(TreeNode* root, unordered_set<int>&st){
    if(root==NULL) return NULL;
    root->left=deleteNodes(root->left,st);
    root->right=deleteNodes(root->right,st);
    if(st.count(root->val)){
        if(root->left) result.push_back(root->left);
        if(root->right) result.push_back(root->right);
        return NULL;
    }
    return root;
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    unordered_set<int>st(to_delete.begin(),to_delete.end());
    root=deleteNodes(root,st);
    if(root) result.push_back(root);
    return result;   
}

map<int,vector<int>>mp;
int height{TreeNode* root}{
    if(root==NULL) return -1;
    int LH=height(root->left);
    int RH=height(root->right);
    int h=1+max(LH, RH);
    mp[h].push_back(root->val);
    return h;
}
vector<vector<int>>findLeaves(TreeNode* root){
    vector<vector<int>>result;
    height(root);
    for(auto it:mp){
        result.push_back(it.second);
    }
    return result;
}

/*Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.*/
TreeNode* pruneTree(TreeNode* root) {
    if(root==NULL) return NULL;
    root->left=pruneTree(root->left);
    root->right=pruneTree(root->right);
    if(root->left==NULL && root->right==NULL && root->val==0) return NULL;
    return root;
}

//Path Sum I
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL){
        return targetSum==root->val;
    }
    int remaining=targetSum-root->val;
    return hasPathSum(root->left,remaining)|| hasPathSum(root->right,remaining);
}

//Path Sum II
vector<vector<int>>result;
void fill(TreeNode* root, int sum, vector<int>temp, int targetSum){
    if(!root) return;
    sum+=root->val;
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        if(sum==targetSum){
            result.push_back(temp);
        }
        return;
    }
    fill(root->left, sum, temp, targetSum);
    fill(root->right, sum, temp, targetSum);
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    int sum=0;
    vector<int>temp;
    fill(root,sum,temp, targetSum);
    return result;
}

/*Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5] */
TreeNode* add(TreeNode* root, int val, int depth, int curr){
    if(root==NULL) return NULL;
    if(curr==depth-1){
        TreeNode* leftTemp=root->left;
        TreeNode* rightTemp=root->right;
        root->left=new TreeNode(val);
        root->right=new TreeNode(val);
        root->left->left=leftTemp;
        root->right->right=rightTemp;
    }
    add(root->left, val, depth, curr+1);
    add(root->right, val, depth, curr+1);
    return root;
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth==1){
        TreeNode* newRoot=new TreeNode(val);
        newRoot->left=root;
        return newRoot;
    }
    int currDepth=1;
    add(root,val,depth, currDepth);
    return root;
}
//it takes less than O(n) => O(log n)^2
int getLeftHeight(TreeNode* root){
    TreeNode* temp=root;
    int lh=0;
    while(temp){
        temp=temp->left;
        lh++;
    }
    return lh;
}
int getRightHeight(TreeNode* root){
    TreeNode* temp=root;
    int rh=0;
    while(temp){
        temp=temp->right;
        rh++;
    }
    return rh;
}
int countNodes(TreeNode* root) {
    int lh=getLeftHeight(root);
    int rh=getRightHeight(root);
    if(lh==rh){
        return (pow(2,lh)-1);
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

//Leaf Similar Trees
void findLeaves(TreeNode* root, vector<int>&result){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        result.push_back(root->val);
    }
    findLeaves(root->left, result);
    findLeaves(root->right, result);
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int>res1,res2;
    findLeaves(root1, res1);
    findLeaves(root2, res2);
    return res1==res2;
}

/*Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.*/
int findMaxDiff(TreeNode* root, int minV, int maxV){
    if(root==NULL){
        return abs(maxV-minV);
    }
    minV=min(minV, root->val);
    maxV=max(maxV, root->val);
    int l=findMaxDiff(root->left, minV, maxV);
    int r=findMaxDiff(root->right, minV, maxV);
    return max(l,r);
}
int maxAncestorDiff(TreeNode* root) {
    return findMaxDiff(root, root->val, root->val);
}

/*Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)*/
long long Sum;
long long maxPro;
long long totalSum(TreeNode* root){
    if(root==NULL) return 0;
    long long leftSum=totalSum(root->left);
    long long rightSum=totalSum(root->right);
    return root->val+leftSum+rightSum;
}
long long findMaxPro(TreeNode* root){
    if(root==NULL) return 0;
    long long leftSum=findMaxPro(root->left);
    long long rightSum=findMaxPro(root->right);
    long long subtreeSum=root->val+leftSum+rightSum;
    long long remainingTreeSum=Sum-subtreeSum;
    maxPro=max(maxPro,subtreeSum*remainingTreeSum);
    return subtreeSum;
}
int maxProduct(TreeNode* root) {
    if(root==NULL) return 0;
    Sum= totalSum(root);
    maxPro=0;
    findMaxPro(root);
    return maxPro % (1000000007);
}

/*Input: p = [1,2,3], q = [1,2,3]
Output: true*/
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p||!q||p->val!=q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Find Duplicate Subtrees
string getSubtreeString(TreeNode* root, unordered_map<string,int>&mp, vector<TreeNode*>&result){
    if(root==NULL) return "N";
    string s=to_string(root->val)+","+getSubtreeString(root->left,mp,result)+","+                   getSubtreeString(root->right,mp,result);
    if(mp[s]==1){
        result.push_back(root);
    }
    mp[s]++;
    return s;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int>mp;
    vector<TreeNode*>result;
    getSubtreeString(root,mp,result);
    return result;
}

/*Input: root = [1,2,2,3,4,4,3]
Output: true*/
bool isMirror(TreeNode* left, TreeNode* right){
    if(!left && !right) return true;
    if(!left||!right||left->val!=right->val) return false;
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isMirror(root->left,root->right);
}

/*Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.*/
int findSum(TreeNode* root, int temp){
    if(root==NULL) return 0;
    temp=temp*10+root->val;
    if(root->left==NULL && root->right==NULL) return temp;
    int l=findSum(root->left,temp);
    int r=findSum(root->right,temp);
    return l+r;
}
int sumNumbers(TreeNode* root) {
    int temp=0;
    return findSum(root,temp);
}

/*Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.*/
TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*>mp;
    unordered_set<int>childNodes;
    for(auto &d:descriptions){
        int parent=d[0];
        int child=d[1];
        int isLeft=d[2];
        if(mp.find(parent)==mp.end()){
            mp[parent]=new TreeNode(parent);
        }
        if(mp.find(child)==mp.end()){
            mp[child]=new TreeNode(child);
        }
        if(isLeft==1){
            mp[parent]->left=mp[child];
        }else{
            mp[parent]->right=mp[child];
        }
        childNodes.insert(child);
    }
    for(auto &d:descriptions){
        int parent=d[0];
        if(childNodes.find(parent)==childNodes.end()){
            return mp[parent];
        }
    }
    return nullptr;
}

/*Input: root = [5,3,6,2,4,null,7], k = 9
Output: true */
unordered_set<int>elem;
bool dfs(TreeNode* root, int k){
    if(root==nullptr) return false;
    if(elem.count(k-root->val)){
        return true;
    }
    elem.insert(root->val);
    return dfs(root->left, k) ||dfs(root->right,k);

}
bool findTarget(TreeNode* root, int k) {
    return dfs(root,k);
}
int main(){
    return 0;
}