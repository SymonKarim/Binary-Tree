/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrderBottomFaster(TreeNode* root) {
         queue<TreeNode*>q;
         vector<vector<int>> ans;
         if(root == NULL) return ans;
         vector<int>v;
       
        q.push(root);
      
        while(!q.empty()){
         int size = q.size();
         while(size--){
             TreeNode* temp = q.front();q.pop();
             v.push_back(temp->val);

             if(temp->left) q.push(temp->left);
             if(temp->right) q.push(temp->right);
         }
         ans.push_back(v);
         v.clear();
        }
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
         vector<vector<int>> ans;
         if(root == NULL) return ans;
         vector<int>v;
       
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
          if(temp!=NULL)  v.push_back(temp->val);
            if(temp == NULL){
                 ans.push_back(v);
                 v.clear();
             if(!q.empty()){
                 q.push(NULL);   
             }
            }else{
                if(temp->left){
                    q.push(temp->left);
                }
                 if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};
