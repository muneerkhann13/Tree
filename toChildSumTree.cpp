// convert to child sum tree

void toChildSum(node *root){
  if(root==NULL)
    return;
  toChildSum(root->left);
  toChildSum(root->right);
  int leftData,rightData;
  if(root->left!=NULL)
    leftData = root->left->data;
  if(root-right!=NULL)
    rightData = root->right->data;
  int diff = leftData+rightData-root->data;

  if(diff>0)
    root->data+=diff;
  else
    increment(root,-diff);
}

void increment(node *root,int diff){
  if(root->left!=NULL){
    root->left->data+=diff;
    increment(root->left,diff);
  }
  else if(root->right!=NULL){
  root->right->data+=diff;
  increment(root->right,diff);
  }
}
