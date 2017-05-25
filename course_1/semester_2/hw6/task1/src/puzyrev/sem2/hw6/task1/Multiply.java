package puzyrev.sem2.hw6.task1;

/**
 * Operation node of Tree: multiply.
 */
public class Multiply extends Operator implements Node {

    /**
     * Init node.
     */
    public Multiply() {
        this.value = '*';
    }

    public float calculate() {
        float leftCalculated = leftChild.calculate();
        float rightCalculated = rightChild.calculate();
        return leftCalculated * rightCalculated;
    }
}