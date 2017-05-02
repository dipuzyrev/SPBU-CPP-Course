package puzyrev.sem2.hw2.task1;

public class Calculator {
    private static ArrayStack<Integer> numbers = new ArrayStack<>(10);
    private static PointerStack<Character> operators = new PointerStack<>();

    public static int getAnswer(String string) {
        return counting(toPostfix(string));
    }

    private static String toPostfix(String inString) {
        String outString = "";
        int i = 0;
        while (i < inString.length()) {
            char c = inString.charAt(i);
            if (isNumber(c))
                outString = outString.concat(Character.toString(c));
            else if (isOperator(c)) {
                while (getStackPriority() >= priority(c)) {
                    outString = outString.concat(Character.toString(operators.pop()));
                }
                operators.push(c);
            }
            else if (isOpeningBrace(c))
                operators.push(c);
            else if (isClosingBrace(c)) {
                char top = operators.pop();
                while (top != '(') {
                    outString = outString.concat(Character.toString(top));
                    top = operators.pop();
                }
            }
            i++;
        }

        while (!operators.isEmpty()) {
            outString = outString.concat(Character.toString(operators.pop()));
        }
        return outString;
    }

    private static int counting(String string) {
        int i = 0;
        while (i < string.length()) {
            char c = string.charAt(i);
            if (isNumber(c))
                numbers.push(c - '0');
            else if (isOperator(c))
                numbers.push(doMath(c));
            i++;
        }
        return numbers.pop();
    }

    private static boolean isOpeningBrace(char ch) {
        return ch == '(';
    }

    private static boolean isClosingBrace(char ch) {
        return ch == ')';
    }

    private static boolean isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    private static boolean isOperator(char ch) {
        return (ch == '+') || (ch == '-') || (ch == '/') || (ch == '*');
    }

    private static int priority(char ch) {
        if (ch == '(')
            return 1;
        if (ch == '+' || ch == '-')
            return 2;
        if (ch == '/' || ch == '*')
            return 3;
        else
            return -1;
    }

    private static int getStackPriority() {
        if (operators.isEmpty())
            return 0;
        char c = operators.pop();
        int priority = priority(c);
        operators.push(c);
        return priority;
    }

    private static int doMath(char ch) {
        int a = numbers.pop();
        int b = numbers.pop();
        if (ch == '+')
            return a + b;
        if (ch == '-')
            return b - a;
        if (ch == '*')
            return a * b;
        if (ch == '/')
            return b / a;
        else
            return -1;
    }
}