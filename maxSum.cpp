int maxSUm(node *root){
  if(root==NULL)
    return 0;
  int min=INT_MIN;

   maxSum(root,&min);
   return min
}

int maxSUmUtil(node *root,int *res){
  if(root==NULL)
    return 0;
  int l= maxSum(root->left,res);
  int r = maxSum(root->right,res);

  int s=max(max(l,r)+root->data,root->data);
  int ss=max(s,l+r+root->data);
  res=max(res,ss);
  return s;
}
