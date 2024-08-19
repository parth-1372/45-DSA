void inorder(struct Node *root,vector<int>& arr){
    if(root==nullptr)return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
float findMedian(struct Node *root)
{
      //Code here
      vector<int> arr;
      inorder(root,arr);
      float ans;
      int n=arr.size();
      if(n%2!=0)ans=arr[n/2];
      else ans=float(arr[n/2]+arr[(n/2) - 1])/2;
      return ans;
}