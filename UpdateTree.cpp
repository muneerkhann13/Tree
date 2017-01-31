int updateTree(node *root){
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->data;
  int leftData=updateTree(root->left);
  int rightData=updateTree(root->right);

  root->data+=leftData;
  return root->data+rightData;
}
