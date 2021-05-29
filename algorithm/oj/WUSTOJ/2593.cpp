#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct Node{
	Node* lchild;
	Node* rchild;
	char data;
};
int build(Node* root, string& pre, int lp, int rp, string& in, int li, int ri){
	root->lchild = NULL;
	root->rchild = NULL;
	root->data = pre[lp];
	if(lp == rp) return 1;
	int pos = li;
	int depth1=0, depth2=0;
	for(int i = li; i <= ri; ++i){
		if(in[i] == pre[lp]){
			int lsize = i - li;
			if(lsize > 0){
				root->lchild = new Node();
				depth1 = build(root->lchild, pre, lp + 1, lp + lsize, in, li, li + lsize - 1);
			}
			if(ri - i > 0){
				root->rchild = new Node();
				depth2 = build(root->rchild, pre, lp + lsize + 1, rp, in, li + lsize + 1, ri);
			}
			break;
		}
	}
	return max(depth1, depth2) + 1;

}
queue<Node*> Q;
void post_order(Node *root){
	if(root){
		post_order(root->lchild);
		post_order(root->rchild);
		cout << root-> data;
	}
}
int main(){
	string pre, in;
	while(cin >> pre >> in){
		if(!Q.empty()) Q.pop();
		Node* root = new Node();
		int depth = build(root, pre, 0, pre.length() - 1, in, 0, in.length() - 1);
		cout << depth << endl;
		post_order(root);
		cout << endl;
		Q.push(root);
		while(!Q.empty()){
			Node* root = Q.front();
			Q.pop();
			if(root){
				cout << (root->data);
				Q.push(root->lchild);
				Q.push(root->rchild);
			}
		}
		cout << endl;
	}
	return 0;
}
