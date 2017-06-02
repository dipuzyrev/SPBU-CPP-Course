package puzyrev.sem2.hw6.task1;

/**
 * Operation node of Tree: minus.
 */
public class Minus extends Operator implements Node {

    /**
     * Init node.
     */
    public Minus() {
        this.value = '-';
    }

    public float calculate() {
        float leftCalculated = leftChild.calculate();
        float rightCalculated = rightChild.calculate();
        return leftCalculated - rightCalculated;
    }
}

