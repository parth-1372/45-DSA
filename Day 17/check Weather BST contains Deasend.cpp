class Solution{
  public:
    bool helper(Node* root,int mini,int maxi){
        if(root==NULL)return false;
        if((mini!=INT_MIN &&maxi-mini<=2) || root->data==1 && root->left==nullptr && root->right==nullptr)return true;
        return 
        helper(root->left,mini,min(maxi,root->data)) ||
        helper(root->right,max(mini,root->data),maxi);
    }
    bool isDeadEnd(Node *root)
    {
        if(root==NULL)return false;
        //Your code here
        return helper(root->left,INT_MIN,root->data)||
               helper(root->right,root->data,INT_MAX);
    }
};