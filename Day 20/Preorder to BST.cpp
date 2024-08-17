class Solution {
  public:
    Node* f(int pre[],int i,int j){
        if(i>j)return nullptr;
        if(i==j){
            return  newNode(pre[i]);
        }
        
        Node* root= newNode(pre[i]);
        int count=0;
        for(int k=i+1;k<=j;k++){
            if(pre[k]>pre[i])break;
            count++;
        }
        root->left=f(pre,i+1,i+count);
        root->right=f(pre,i+count+1,j);
        return root;
    }
    Node* Bst(int pre[], int size) {
        return f(pre,0,size-1);
    }
};