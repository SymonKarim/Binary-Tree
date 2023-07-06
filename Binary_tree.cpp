//*Bismillahir Rahmanir Raheem
//! symonkarim
#include <bits/stdc++.h>
#define FASTER ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
//!------

#define ll long long

class node {
public:
    int val;
    node* left;
    node* right;

    node(int data) {
        this->val = data;
        this->left = NULL;
        this ->right = NULL;
    }
};
node* buildTree(node* root) {
    cout << "enter the data";
    int data; cin >> data;
    root = new node(data);

    if (data == -1) return NULL;
    cout << "Enter data to the left of Root";
    root -> left = buildTree(root -> left);
    cout << "Enter data to the right of Root";
    root -> right = buildTree(root -> right);
    return root;
}
void traverseTree(node* root) {
    queue<node*>q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            node* temp  = q.front();
            q.pop();
            if (temp) cout << temp->val << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}
node* inOrderTraverse(node* root) {
    if (root == NULL) return NULL;
    root->left = inOrderTraverse(root->left);
    cout << root->val << ' ';
    root->right = inOrderTraverse(root->right);

    return root;

}
node* preOrderTraverse(node* root) {
    if (root == NULL) return NULL;
    cout << root->val << ' ';
    root->left = preOrderTraverse(root->left);
    root->right = preOrderTraverse(root->right);

    return root;

}
node* postOrderTraverse(node* root) {
    if (root == NULL) return NULL;

    root->left = postOrderTraverse(root->left);

    root->right = postOrderTraverse(root->right);
    cout << root->val << ' ';
    return root;

}

void leverOrderTraversal(node* root) {
    queue<node*>q;
    q.push(root);
    while (!q.empty()) {

        node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left) {
            q.push(temp->left);
        } if (temp->right) {
            q.push(temp->right);
        }

    }
}
int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    node* root = NULL;
    root = buildTree(root);
    cout << endl;
    cout << "inOrderTraverse: ";
    inOrderTraverse(root);
    cout << endl;
    cout << "preOrderTraverse: ";
    preOrderTraverse(root);
    cout << endl;
    cout << "postOrderTraverse: ";
    postOrderTraverse(root);
    cout << endl;
    cout << "leverOrderTraversal: " << endl;
    leverOrderTraversal(root);
    cout << endl;
    traverseTree(root);


    return 0;
}
/*
input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
output:
inOrderTraverse: 7 3 11 1 17 5
preOrderTraverse: 1 3 7 11 5 17
postOrderTraverse: 7 11 3 17 5 1
leverOrderTraversal:
1
3 5
7 11 17
*/
