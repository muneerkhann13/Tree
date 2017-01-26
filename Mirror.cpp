node *MirrorTree(node *root){
    if(root==NULL)
      return NULL;
    node *temp;

    root->left=MirrorTree(root->left);
    root->right=MirrorTree(root->right);

    temp=root->left;
    root->left=root->right;
    root->right=temp;
    return root;
}
