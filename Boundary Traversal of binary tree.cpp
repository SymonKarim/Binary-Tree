

// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    private:
    void leftTree(Node* root, vector<int> &ans){
        if(root == NULL ) return;
        if(root -> left!=NULL){
            ans.push_back(root -> data);
            leftTree(root -> left,ans);
        }else if(root -> right!=NULL){
            ans.push_back(root -> data);
            leftTree(root -> right,ans);
        }
    }
    void leafNodes(Node* root, vector<int>&ans){
        if(root == NULL) return;
        leafNodes(root->left,ans); 
        if(root->left == NULL and root->right==NULL){
            ans.push_back(root->data);
        }
        leafNodes(root->right,ans);
       
        
    }
    void rightNodes(Node* root, vector<int> &ans){
        if(root == NULL ) return;
        if(root -> right){
            rightNodes(root -> right,ans);
            ans.push_back(root -> data);
        }
        else if(root -> left){
            rightNodes(root -> left,ans);
            ans.push_back(root -> data);
        } 
    }
    
public:
    vector <int> boundary(Node *root)
    {
       vector<int>ans;
       if(root==NULL) return ans;
       if(!root->left and !root->right) return {root->data};
       ans.push_back(root->data);
       leftTree(root->left, ans);
       leafNodes(root,ans);
       rightNodes(root->right,ans);
       return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
