// child to  leaf path

void printArr(int arr[] ,int n){
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}
void printRootToLeaf(node *root,int arr[],int len){
  if(root==NULL)
    return;
  if(root->left==NULL && root->right==NULL){
    arr[len++]=root->data;
    printArr(arr,len);
  }
  arr[len++]=root->data;
  printRootToLeaf(root->left,arr,len);
  printRootToLeaf(root->right,arr,len);
}
