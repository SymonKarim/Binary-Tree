class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
       queue<Node*>Q;
       Q.push(root);
       while(!Q.empty()){
           int size = Q.size();
            Node* temp;
           while(size--){
                temp = Q.front(); Q.pop();
               if(temp->left) Q.push(temp->left);
               if(temp->right) Q.push(temp->right);
           }
           ans.push_back(temp->data);
       }
       return ans;
    }
};
