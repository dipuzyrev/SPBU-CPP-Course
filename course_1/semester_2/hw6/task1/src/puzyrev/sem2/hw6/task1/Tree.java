package puzyrev.sem2.hw6.task1;

import java.io.*;

/**
 * Tree data structure class.
 */
public class Tree {
    private Node root = null;
    private static int pointer = 0;

    /**
     * Create tree from file.
     * @param fileName file to parse
     */
    public Tree(String fileName) {
        String expression = null;

        try(FileReader reader = new FileReader(fileName)) {
            BufferedReader in = new BufferedReader(reader);
            expression = in.readLine();
        } catch(IOException e) {
            e.printStackTrace();
        }

        root = parseExpression(expression);
    }

    /**
     * Convert all tree structure to string.
     * @return tree converted to string
     */
    public String convertToString() {
        return root.convertToString();
    }

    /**
     * Calculate Tree.
     * @return result of Tree calculation
     */
    public float calculate() {
        return root.calculate();
    }

    /**
     * Return Node parsed from string.
     * @param expression string with node structure
     * @return parsed Node
     */
    private Node parseExpression(String expression) {
        int expressionLength = expression.length();

        if (expression.charAt(pointer) == '(') {
            pointer++;
        }

        char value = expression.charAt(pointer);

        if (isOperation(value)) {
            Operator operationNode = createOperator(value);
            pointer += 2;
            operationNode.setLeftChild(parseExpression(expression));
            operationNode.setRightChild(parseExpression(expression));
            return operationNode;
        } else {
            int number = Character.getNumericValue(value);

            value = expression.charAt(++pointer);
            while (pointer < expressionLength && expression.charAt(pointer) != ' ' && expression.charAt(pointer) != ')') {
                number = number * 10 + Character.getNumericValue(value);
                pointer++;
            }
            pointer++;
            while(pointer < expressionLength && expression.charAt(pointer) != '(' && !isNumber(expression.charAt(pointer))) {
                pointer++;
            }
            return new Number(number);
        }
    }

    /**
     * Create operation node from char.
     * @param value to parse
     * @return operation Node
     */
    Operator createOperator(char value) {
        switch (value) {
            case '+':
                return new Plus();
            case '-':
                return new Minus();
            case '*':
                return new Multiply();
            case '/':
                return new Divide();
            default:
                return new Plus();
        }
    }

    /**
     * Check if char is operation.
     * @param value to check
     * @return 'true' if operation or 'false' if not
     */
    private boolean isOperation(char value) {
        if ((int) value <  '0' || (int) value > '9') {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Check if char is number.
     * @param value to check
     * @return 'true' if number of 'false' if not
     */
    private boolean isNumber(char value) {
        if ((int) value >=  '0' && (int) value <= '9') {
            return true;
        } else {
            return false;
        }
    }
}
