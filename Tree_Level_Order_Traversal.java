

	/* 
    
    class Node 
    	int data;
    	Node left;
    	Node right;
	*/
    
    private static List<Node> nodes = new ArrayList<Node>();
    
    /**
    *
    */
    public static void readNode(Node node)
    {
        if(node != null)
        {
            System.out.print(node.data + " ");
            
            if(node.left != null)
                nodes.add(node.left);
            if(node.right != null)
                nodes.add(node.right);
        }
    }
    
	public static void levelOrder(Node root) {
        readNode(root);
        for(int index = 0; index < nodes.size(); index++)
        {
            readNode(nodes.get(index));
        }
    }

