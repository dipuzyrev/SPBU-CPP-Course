package puzyrev.sem2.hw6.task1;

public abstract class Operator implements Node {
    protected Node leftChild;
    protected Node rightChild;
    protected char value;

    public String convertToString() {
        return "( " + value + " " + leftChild.convertToString() + " " + rightChild.convertToString() + " )";
    }

    public float calculate() {
        float leftCalculated = leftChild.calculate();
        float rightCalculated = rightChild.calculate();

        switch (value) {
            case '+':
                return leftCalculated + rightCalculated;
            case '-':
                return leftCalculated - rightCalculated;
            case '*':
                return leftCalculated * rightCalculated;
            case '/':
                return leftCalculated / rightCalculated;
            default:
                return 0;
        }
    }

    public void setLeftChild(Node leftChild) {
        this.leftChild = leftChild;
    }

    public void setRightChild(Node rightChild) {
        this.rightChild = rightChild;
    }
}
