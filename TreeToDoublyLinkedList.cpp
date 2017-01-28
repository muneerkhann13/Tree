void inPlaceTreeToDLL(node *root,node **head){
	static node *prev;
	if(root==NULL)
		return;
	inPlaceTreeToDLL(root->left,head);
	if(prev==NULL)
		*head=root;
	else{
		prev->right=root;
		root->left=prev;
	}
	prev=root;
	inPlaceTreeToDLL(root->right,head);
}
void fixPrevPointer(node *root){
static node *prev =NULL;
	if(root!=null){
		fixPrevPointer(root->left);
		root->left=prev;
		prev=root;
		fixPrevPointer(root->right);
	}
}

node *fixNextPointer(node *root){
	if(root==NULL)
		return;
	while(root!=NULL&&root->right!=NULL)
		root=root->right;
	node *prev;
	while(root!=NULL&&root->left!=NULL){
		prev=root;
		root=root->left;
		root->right=prev;
	}
	return root;
}
node *bToDLL(node *root){
	fixPrevPointer(root);
	return fixNextPointer(root);
}

node *treeTodll(node *root){
  if(root==NULL)
    return NULL;
  if(root->left){
    node *left=treeTodll(root->left);
    for(;left->right!=NULL;left=left->right);
    left->right=root;
    root->left=left;
  }
  if(root->right){
    node *right=treeTodll(root->right);
      for(;right->left!=NULL;right=right->left);
      root->right=right;
      right->left=root;
  }
  return root;
}
