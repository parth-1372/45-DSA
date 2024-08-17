class Solution {
  public:
    pair<Node*,Node*> f(Node* root){
        if(root==nullptr)return {NULL,NULL};
        pair<Node*,Node*> left = f(root->left);
        pair<Node*,Node*> right = f(root->right);
        
        if(left.first == nullptr && right.first==nullptr){
            return {root,root};
        }
        else if(left.first==nullptr && right.first!=nullptr){
            root->right=right.first;
            right.first->left=root;
            return {root,right.second};
        }
        else if(left.first!=nullptr && right.first==nullptr){
            left.second->right=root;
            root->left=left.second;
            return {left.first,root};
        }
        left.second->right=root;
        root->left=left.second;
        root->right=right.first;
        right.first->left=root;
        return {left.first,right.second};
    }
    Node* bToDLL(Node* root) {
        // code here
        return f(root).first;
    }
};