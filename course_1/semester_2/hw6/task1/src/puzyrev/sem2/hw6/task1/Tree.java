package puzyrev.sem2.hw6.task1;

import java.io.*;

public class Tree {
    private Node root = null;
    private static int pointer = 0;

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

    public String convertToString() {
        return root.convertToString();
    }

    public float calculate() {
        return root.calculate();
    }

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

    private boolean isOperation(char value) {
        if (value == '+' || value == '-' || value == '*' || value == '/') {
            return true;
        } else {
            return false;
        }
    }

    private boolean isNumber(char value) {
        if ((int) value >=  '0' && (int) value <= '9') {
            return true;
        } else {
            return false;
        }
    }
}
