
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
int height(Node* root) {
	int heightL = 0;
	int heightR = 0;
	
	if(!root)
		return -1;
	else
	{
		heightL += height(root->left);
		heightR += height(root->right);
		
		//cout << "heightL:: " << heightL << " heightR:: " << heightR << endl;
	}
	
	return max(heightL, heightR) + 1;
}

