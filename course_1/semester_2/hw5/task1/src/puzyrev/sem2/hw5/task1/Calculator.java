package puzyrev.sem2.hw5.task1;

public class Calculator {
    private final int MAX_VALUE = 10;
    private final int MIN_VALUE = 0;

    public int getMaxValue() {
        return MAX_VALUE;
    }

    public int getMinValue() {
        return MIN_VALUE;
    }

    public int count(String operation, int firstValue, int secondValue) {
        int result = 0;

        switch (operation) {
            case "+":
                result = firstValue + secondValue;
                break;
            case "-":
                result = firstValue - secondValue;
                break;
            case "*":
                result = firstValue * secondValue;
                break;
            case "/":
                result = firstValue / secondValue;
                break;
        }

        return result;
    }
}