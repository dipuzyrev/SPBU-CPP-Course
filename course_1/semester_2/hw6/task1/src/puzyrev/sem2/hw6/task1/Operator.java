package puzyrev.sem2.hw6.task1;

/**
 * Parent class for operation nodes of Tree.
 */
public abstract class Operator implements Node {
    protected Node leftChild;
    protected Node rightChild;
    protected char value;

    public String convertToString() {
        return "( " + value + " " + leftChild.convertToString() + " " + rightChild.convertToString() + " )";
    }

    /**
     * Set left child of node.
     * @param leftChild node to set
     */
    public void setLeftChild(Node leftChild) {
        this.leftChild = leftChild;
    }

    /**
     * Set right child of node.
     * @param rightChild node to set
     */
    public void setRightChild(Node rightChild) {
        this.rightChild = rightChild;
    }
}
