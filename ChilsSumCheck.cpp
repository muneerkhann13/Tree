/* error in code */

int checkChildSum(node *root){
  if(root->left==NULL && root->right==NULL)
    return 1;
  if(root==NULL)
    return 1;
  int ldata=0,rdata=0;
  if(root->left!=NULL)
    ldata=root->left->data;
  if(root->right!=NULL)
    rdata=root->right->data;
  if( (ldata+rdata==root->data) && checkChildSum(root->left)&&checkChildSum(root->right))
    return 1;

  return 0;
}
