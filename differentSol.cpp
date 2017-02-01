void connectNodes(node *root){
  queue<node *> q;
  int n;
  node *t,*t1;
  q.push(root);
  while(1){
    n=q.size();

    if(n==0)
      break;

    while(n--){
      t=q.front();
      q.pop();

      if(n==0){
        t->nextRight = NULL;
      }else{
        t->nextRight = q.front();
      }

      if(t->left){
        q.push(t->left);
      }
      if(t->right){
        q.push(t->right);
      }
    }
  }
}

void connectNode1(node *root){
  root->nextRight =NULL;
  connectRecurr(root);
}
void connectRecurr(node *root){
  if(root == NULL)
    return;
  if(root->nextRight)
    connectRecurr(root->nextRight);
  if(root->left){
    if(root->right){
      root->nextRight = root->right;
      root->right->nextRight = getNextRight(root)
    }else{
      root->nextRight=getNextRight(root);
    }
    connectRecurr(root->left);
  }else if(root->right){
    root->nextRight = getNextRight(root);
    connectRecurr(root->right);
  }else{
    connectRecurr(getNextRight(root));
  }
}
node *getNextRight(node *root){
  temp = root->nextRight;
  while(temp!=NULL){
    if(temp->left)
      return temp->left;
    if(temp->right)
      return temp->right;
    temp = temp->nextRight;
  }
  return NULL;
}
void connectNode2(node *root){
  if(root==NULL)
    return;
  root->nextRight = NULL:

  while(root!=NULL){
    node *curr =root;
    while(curr!=NULL){
      if(curr->left){
        if(curr->right){
          curr->left->nextRight = curr->right;
        }else{
          curr->left->nextRight = getNextRight(curr);
        }
      }
      if(curr->right){
        curr->right->nextRight = getNextRight(curr);
      }
      curr=curr->nextRight;
    }
    if(root->left)
      root=root->left;
    else if(root->right)
      root=root->right;
    else
      root=root->nextRight;
  }
}
bool isIden(node *t,node *s){
	if(t==NULL&&s==NULL)
		return true;
	if(	(t->data == s->data) && isIden(t->left,s->left) &&isIden(t->right,s->right) )
		return true;
	return false;
}
bool isSubtree(node *T,node *S){
	if(S==NULL)
		return true;
	if(T==NULL)
		return false;
	if( T->data==S->data )
		return isIden(T,S);
	return isSubtree(T->left,S)||isSubtree(T->right,S);
}
int[] preOrder(node *root){
	node *curr=root;
	char arr[10];
	int index=0;
	while(curr!=NULL){
		if(curr->left==NULL){
			arr[index++]=curr->data;
		}else{
			node *pre = curr->left;
			while(pre->right!=NULL && pre->right!=curr){
				pre=pre->right;
			}
			if(pre->right==NULL){
				arr[index++] = curr->data;
				pre->right=curr;
				curr=curr->left;
			}else{
				curr=curr->right;
				pre->right=NULL;
			}
		}
	}
}

int height(node *root){
	queue<node *> q;
	q.push(root);
	node *t;
	int h=0,n;
	while(1){
		n=q.size();
		if(n==0)
			break;
		h++;
		while(n--){
			t=q.front();
			q.pop();
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
	return h;
}
int diffOddEven(node *root){
	queue<node *> q;
	q.push(root);
	node *t;
	bool sum=false;
	int h=0,n;
	while(1){
		n=q.size();
		if(n==0)
			break;
		sum=!sum;
		while(n--){
			t=q.front();
			q.pop();
			if(sum)
				h=h+t->data;
			else
				h=h-t->data;
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
	return h;
}
int[] inOrder(node *root){
	node *curr=root;
	char arr[10];
	int index=0;
	while(curr!=NULL){
		if(curr->left==NULL){
			arr[index++]=curr->data;
		}else{
			node *pre = curr->left;
			while(pre->right!=NULL && pre->right!=curr){
				pre=pre->right;
			}
			if(pre->right==NULL){
				pre->right=curr;
				curr=curr->left;
			}else{
				arr[index++] = curr->data;
				curr=curr->right;
				pre->right=NULL;
			}
		}
	}
}
void left(node *t){
	if(t!=NULL){
		if(t->left){
			cout<<t->data;
			left(t->left);
		}else if(t->right){
			cout<<t->data;
			left(t->right);
		}
	}
}
void right(node *t){
	if(t!=NULL){
		if(t->right){
			left(t->right);
			cout<<t->data;
		}else if(t->left){
			left(t->left);
			cout<<t->data;
		}
	}
}
void printLeafs(node *t){
	if(t!=NULL){
		if(t->left)
			printLeafs(t->left);
		if(t->left ==NULL && t->right==NULL)
			cout<<t->data;
		if(t->right)
			printLeafs(t->right);
	}
}
void postorder2Stack(node *t){
	stack<node*> s1,s2;
	s1.push(t);
	while( !s1.empty() ){
		node *t1 = s1.pop();
		s2.push(t1);
		s1.push(t->left);
		s1.push(t->right);
	}
	while(!s2.empty()){
		node *t1=s2.pop();
		cout<<t1->data;
	}
}
void postorder1Stack(node *t){
	stack<node*> s;
	node*temp=t;
	do{
		while(temp!=NULL){
			if(temp->right){
				s.push(temp->right);
			}
			s.push(temp);
			temp=temp->right;
		}
		temp=s.pop();
		if(temp!=NULL && temp==s.top()){
			s.pop();
			s.push(temp);
			temp=temp->right;
		}else{
			cout<<temp->data;
			temp=NULL;
		}
	}while(!s.empty() );
}
void printLeftView(node *root){
	queue<node *> q;
	q.push(root);
	node *t;
	bool sum=false;
	int n;
	while(1){
		n=q.size();
		if(n==0)
			break;
		cout<<q.front()->data;
		while(n--){
			t=q.front();
			q.pop();
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
	return ;
}
struct qNode{
	node *n;
	int dis;
};
void printTopView(node *root){
	queue<qNode> q;
	struct qNode qn;
	map<int,int> m;
	int n;
	node *t;

	qn.n = root;

	qn.dis=0;
	q.push(qn);

	while(1){
		n=q.size();
		if(n==0)
			break;

		while(n--){
			qn=q.front();
			q.pop();
			if(m[qn.dis]==0){
				m[q.dis]=1;
				cout<<qn.n->data;
			}
			t=qn.n;
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
	return ;
}
void printBottomView(node *root){
	queue<qNode>q;
	struct qNode qn,te;
	map<int,int>m;
	int n,min=INT_MAX,max=INT_MIN;
	node *t;

	qn.n =root;
	qn.dis=0;
	q.push(qn);
	while(1){
		n=q.size();
		if(n==0)
			break;
		while(n--){
			qn=q.front();
			q.pop();
			m[qn.dis]=qn.n->data;
			t=qn.n;
			if(t->left){
				te.dis=qn.dis-1;
				te.n=t->left;
				q.push(te);
			}
			if(t->right){
				te.dis=qn.dis+1;
				te.n=t->right;
				q.push(te);
			}
			if(min>qn.dis)
				min=qn.dis;
			else if(max<qn.dis)
				max=qn.dis;

		}
	}
	for(auto i=m.begin();i!=m.end();i++){
		cout<<i->second<< " ";
	}
}
void VerticalOrder(node *root){
	map<int,list<int> > m;
	queue<qNode> q;
	struct qNode qn,qt;
	node* t;
	int n;

	qn.n=root;
	qn.dis=0;
	q.push(qn);
	while(1){
		n=q.size();
		if(n==0)
			break;
		while(n--){
			qn=q.front();
			q.pop();
			m[qn.dis].push_back(qn.n->data);
			t=qn.n;
			if(t->left){
				qt.dis=qn.dis-1;
				qt.n=t->left;
				q.push(qt);
			}
			if(t->right){
				qt.dis=qn.dis+1;
				qt.n=t->right;
				q.push(qt);
			}
		}
	}
	for(auto i=m.begin();i!=m.end();++i){
		list<int>::iterator it;
		for(it=i->second.begin();it!=i->second.end();++it)
			cout<<*it<< " ";
		cout<<"\n";
	}
}

Node *LCA(Node *root,Node* n1,Node*n2){
	if(root==NULL)
		return NULL;
	Node *le = LCA(root->left,n1,n2);
	Node *re =LCA(root->right,n1,n2);

	if(le&&re)
		return root;
	else if(re)
		return re:
	else
		le

}
	if (root == NULL) return NULL;
	if (root->key == n1 || root->key == n2)
		return root;
	Node *left_lca = LCA(root->left, n1, n2);
	Node *right_lca = LCA(root->right, n1, n2);
	if (left_lca && right_lca) return root;
	return (left_lca != NULL)? left_lca: right_lca;
