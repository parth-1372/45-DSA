class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      if(root==nullptr)return 0;
      return getCount(root->left,l,h)+getCount(root->right,l,h)+(root->data>=l && root->data<=h);
      // your code goes here   
    }
};