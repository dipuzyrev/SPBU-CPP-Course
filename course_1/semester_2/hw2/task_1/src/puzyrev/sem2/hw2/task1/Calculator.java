package puzyrev.sem2.hw2.task1;

/**
 * Class that calculates expression.
 */
public class Calculator {
    private static ArrayStack<Integer> numbers = new ArrayStack<>(10);
    private static PointerStack<Character> operators = new PointerStack<>();

    /**
     * Calculate expression.
     *
     * @param string expression.
     * @return calculated expression.
     */
    public static int getAnswer(String string) {
        return counting(toPostfix(string));
    }

    /**
     * Convert infix expression to postfix.
     *
     * @param inString expression
     * @return postfix expression
     */
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
            else if (isOpeningBracket(c))
                operators.push(c);
            else if (isClosingBracket(c)) {
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

    /**
     * Calculate answer from postfix form.
     *
     * @param string expression in postfix form
     * @return calculated answer
     */
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

    /**
     * Check if character is opening bracket.
     *
     * @param ch character to check
     * @return check result (true or false)
     */
    private static boolean isOpeningBracket(char ch) {
        return ch == '(';
    }

    /**
     * Check if character is closing bracket.
     *
     * @param ch character to check
     * @return check result (true or false)
     */
    private static boolean isClosingBracket(char ch) {
        return ch == ')';
    }

    /**
     * Check if character is number.
     *
     * @param ch character to check
     * @return check result (true or false)
     */
    private static boolean isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    /**
     * Check if character is operator.
     *
     * @param ch character to check
     * @return check result (true or false)
     */
    private static boolean isOperator(char ch) {
        return (ch == '+') || (ch == '-') || (ch == '/') || (ch == '*');
    }

    /**
     * Calculate character priority.
     *
     * @param ch character to calculate
     * @return character priority
     */
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

    /**
     * Calculate priority of last Stack element.
     *
     * @return last Stack element priority or '0' if empty
     */
    private static int getStackPriority() {
        if (operators.isEmpty())
            return 0;
        char c = operators.pop();
        int priority = priority(c);
        operators.push(c);
        return priority;
    }

    /**
     * Do operation with two last Stack elements.
     *
     * @param ch operation
     * @return calculated result
     */
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