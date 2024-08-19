class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    pair<pair<bool,int>,pair<int,int>> f(Node* root,int& ans){
        if(root==nullptr){
            return {{true,0},{INT_MAX,INT_MIN}};
        }
        if(root->left==nullptr && root->right==nullptr){
            ans=max(ans,1);
            return {{true,1},{root->data,root->data}};
        }
        
         bool curr=false;
         pair<pair<bool,int>,pair<int,int>> L = f(root->left,ans);
         pair<pair<bool,int>,pair<int,int>> R = f(root->right,ans); 
         

         if(L.first.first && R.first.first &&
            root->data>L.second.second && root->data<R.second.first)
            curr=true;
        int subTreeSize=L.first.second+R.first.second+1;
        if(curr){
            ans=max(ans,subTreeSize);
        }
        return {{curr,subTreeSize},{min(root->data,L.second.first),
                              max(root->data,R.second.second)}};
        
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans=0;
    	auto it = f(root,ans);
    	return ans;
    }
};