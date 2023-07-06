

vector<int> diagonal(Node *root)
{
  
   if(!root) return {};
   queue<Node*>Q; 
   vector<int>ans;
   Q.push(root);
   while(!Q.empty()){
       Node* temp = Q.front();
       Q.pop();
       while(temp){
           if(temp->left) Q.push(temp->left);
           ans.push_back(temp->data);
           temp = temp->right;
       }
   }
   return ans;
}
