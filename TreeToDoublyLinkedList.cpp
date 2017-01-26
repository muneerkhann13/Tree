node *treeTodll(node *root){
  if(root==NULL)
    return NULL;
  if(root->left){
    node *left=treeTodll(root->left);
    for(;left->right!=NULL;left=left->right);
    left->right=root;
    root->left=left;
  }
  if(root->right){
    node *right=treeTodll(root->right);
      for(;right->left!=NULL;right=right->left);
      root->right=right;
      right->left=root;
  }
  return root;
}
