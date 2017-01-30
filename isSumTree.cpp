bool isSumTree1(node *root){
  if(root==NULL || (root->left==NULL &&root->right==NULL) )
    return true;
    int l,r;
    if(isSumTree1(root->left)&&isSumTree1(root->right)){
      if(root->left==NULL)
        l=0;
      else if (root->left->left==NULL && root->left->right==NULL)
        l=root->left->data;
      else
        l=2*root->left->data;

      if(root->right==NULL)
        r=0;
      else if (root->right->left==NULL && root->right->right==NULL)
        r=root->right->data;
      else
        r=2*root->right->data;

      return root->data==l+r;
    }
    return false;
}
