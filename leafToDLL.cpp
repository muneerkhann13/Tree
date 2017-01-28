node *leafToDLL(node *root,node **head){
  if(root!=NULL){
    if(root->left==NULL&&root->right==NULL){
        root->right=(*head);
        if((*head)!=NULL)
          (*head)->left=root;
        *head=root;
      return NULL;
    }
    root->right=leafToDLL(root->right,head);
    root->left=leafToDLL(root->left,head);
    return root;
  }
}
