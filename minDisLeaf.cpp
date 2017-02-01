
int minLow(Node *root,char key){
  if(root==NULL)
    return INT_MAX;
  if(root->left==NULL&&root->right==NULL)
    return 0;
  return 1+min(minLow(root->left,key),minLow(root->right,key));
}
// closest leaf
int getMinLeafDisUtil(Node *root,char key,Node *ansector[],int index){
  if(root==NULL)
    return INT_MAX;
  if(root->key==key){
    int res = minLow(root,key);
    for(int i=index-1;i>=0;i--){
      res=min(res,index-i+minLow(ansector[i],key));
    }
    return res;
  }
  ansector[index]=root;
  return min(getMinLeafDisUtil(root->left,key,ansector,index+1),getMinLeafDisUtil(root->right,key,ansector,index+1));
}
int getMinLeafDis(Node *root, char key){
  Node *ansector[1000];
  return getMinLeafDisUtil(root,key,ansector,0);
}
