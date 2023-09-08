

	/*
    class Node 
    	int data;
    	Node left;
    	Node right;
	*/
	public static int height(Node root) {
      	// Write your code here.
          int _height = 0;
          if(root != null)
          {
              if(root.left != null || root.right != null)
              {
                  _height++;
                  int leftHeight = height(root.left);
                  int rightHeight = height(root.right);
                  _height += Integer.max(leftHeight, rightHeight);
              }
          }
          return _height;
    }

