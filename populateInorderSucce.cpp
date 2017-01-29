void inorderSucc(node *root, node **next){
  if(root==NULL)
    return ;
  inorderSucc(root->right,next);
  root->next=*next;
  *next=root;
  inorderSucc(root->left,next);
}
