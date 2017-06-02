package puzyrev.sem2.hw6.task1;

/**
 * Number node of Tree.
 */
public class Number implements Node {
    private int value;

    /**
     * Init number node.
     * @param value node value
     */
    public Number(int value) {
        this.value = value;
    }

    public String convertToString() {
        return Integer.toString(value);
    }

    public float calculate() {
        return value;
    }
}