int toSumTree(node *root){
  if(root==NULL)
    return 0;

  oldVal=root->data;

  root->data=toSumTree(root->left)+toSumTree(root->right);
  return oldVal+root->data;
}
