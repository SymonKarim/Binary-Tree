class Solution
{
    public:
    int sum(Node* root){
      if(root==NULL) return 0;
      
      return root->data+sum(root->left) + sum(root->right);
    }
    bool isSumTree(Node* root)
    {
       if(!root or( !root->left and !root->right)) return 1;
       int leftAns = 0 , rightAns=0;
       
       if(root->left) leftAns= sum(root->left);
       if(root->right) rightAns= sum(root->right);
       
       if(leftAns+rightAns == root->data and isSumTree(root->left) and isSumTree(root->right)){
           return 1;
       }else return 0;
      
    }
};
