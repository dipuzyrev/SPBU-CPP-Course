package puzyrev.sem2.hw6.task1;

/**
 * Interface for Nodes of Tree.
 */
public interface Node {
    /**
     * Convert all node structure to string.
     * @return node structure converted to string
     */
    public String convertToString();

    /**
     * Recursively calculate node.
     * @return result of calculation
     */
    public float calculate();
}