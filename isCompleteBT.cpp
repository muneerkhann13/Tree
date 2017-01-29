bool isCompleteTree(node  *root){
  queue<node*>q;
  bool falg=false;
  node *temp;
  q.push(root);
  while( !q.empty() ){
    temp=q.front;
    q.pop();
    if(temp->left!=NULL){
      if(flag)
        return false;
      q.push(temp->left);
    }else{
      flag=true;;
    }
    if(temp->right!=NULL){
      if(flag)
        return false;
      q.push(temp->right);
    }else{
      flag=true;
    }
  }
  return true;
}
