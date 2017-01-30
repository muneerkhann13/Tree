bool isFoldable(node *left,node *right){
  if(left==NULL && right==NULL)
    return true;
  if(left==NULL||right==NULL)
    return false;
  return isFoldable(left->left,right->right)&&isFoldable(left->right,right->left);
}
