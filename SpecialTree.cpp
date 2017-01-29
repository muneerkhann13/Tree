node *speacialTree(int pre[],char preLN[],int n,int *index){
  if(*index==n)
    return NULL;

    node *root=newNode(pre[*index]);
    (*index)++;
    if(preLN[*index-1]=='N'){
      root->left = speacialTree(pre,preLN,n,index);
      root->right = speacialTree(pre,preLN,n,index);
    }
    return root;
}
