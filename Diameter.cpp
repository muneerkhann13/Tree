int Diameter(node *root,int *height){
  if(root==NULL){
    height=0;
    return 0;
  }
  int lh=0,rh=0;
  int ld=Diameter(root->left,&lh),rd=Diameter(root->right,&rh);
  *height=max(lh,rh)+1;
  return max(lh+rh+1,max(rd,ld));
}
