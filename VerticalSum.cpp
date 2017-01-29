
struct qNode {
  node *root;
  int dis;
};
void VerticalSum(node *root){
  if(root==NULL)
    return ;
  queue<qNode> q;
  qNode qroot,qtemp;
  int size;
  map<int,list<int> > m;
  map<int,list<int> >::iterator it;
  qroot.root=root;
  qroot.dis=0;
  q.push(qroot);
  while(1){
    size=q.size();
    if(size==0)
      break;
    while(size--){
      qroot=q.front();
      q.pop();
      m[qroot.dis].push_back(qroot.root->data);
      if(qroot.root->left){
        qtemp.root=qroot.root->left;
        qtemp.dis=qroot.dis-1;
        q.push(qtemp);
      }
      if(qroot.root->right){
        qtemp.root=qroot.root->right;
        qtemp.dis=qroot.dis+1;
        q.push(qtemp);
      }
    }
  }
  for(it=m.begin();it!=m.end();++it){
    cout<<it->first<<" ";
    int s=it->second.size();
    for(list<int>::iterator i=it->second.begin();i!=it->second.end();i++)
      cout<<*i<<" ";
    cout<<"\n";
  }
}
