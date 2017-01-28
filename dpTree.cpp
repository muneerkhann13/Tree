map<node *,int> dp1,dp2;

void dpTree(node *root){
  int sum1=0,sum2=0;
  if(root==NULL)
    return;
  if(root->left==NULL&&root->right==NULL){
    dp1[root]=1;
    dp2[root]=0;
    return;
  }
  dpTree(root->left);
  dpTree(root->right);
  sum1=sum1+dp2[tree->left]+dp2[tree->right];
  sum2=max(dp1[root->left],dp2[root->left])+max(dp1[root->right],dp2[root->right]);
  dp1[root]=1+sum1;
  dp2[root]=sum2;
}
