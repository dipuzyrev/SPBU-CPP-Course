package puzyrev.sem2.hw6.task1;

/**
 * Operation node of Tree: plus.
 */
public class Plus extends Operator implements Node {

    /**
     * Init node.
     */
    public Plus() {
        this.value = '+';
    }

    public float calculate() {
        float leftCalculated = leftChild.calculate();
        float rightCalculated = rightChild.calculate();
        return leftCalculated + rightCalculated;
    }
}