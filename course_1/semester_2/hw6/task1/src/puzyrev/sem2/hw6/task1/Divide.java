package puzyrev.sem2.hw6.task1;

/**
 * Operation node of Tree: divide.
 */
public class Divide extends Operator implements Node {

    /**
     * Init node.
     */
    public Divide() {
        this.value = '/';
    }

    public float calculate() {
        float leftCalculated = leftChild.calculate();
        float rightCalculated = rightChild.calculate();
        return leftCalculated / rightCalculated;
    }
}