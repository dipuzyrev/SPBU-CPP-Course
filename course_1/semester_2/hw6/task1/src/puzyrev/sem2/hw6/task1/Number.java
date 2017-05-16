package puzyrev.sem2.hw6.task1;

public class Number implements Node {
    private int value;

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