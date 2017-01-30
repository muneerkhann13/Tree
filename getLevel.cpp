
int getLevel1(node *root,int level,int data){
  if(root==NULL)
    return 0;
  int lev;
  if(root->data==data)
    return level;
  lev=getLevel1(root->left,level+1,data);
  if(!lev)
    lev=getLevel1(root->right,level+1,data);

  return lev;
}
