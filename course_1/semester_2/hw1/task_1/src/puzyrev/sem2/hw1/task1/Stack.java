package puzyrev.sem2.hw1.task1;

/**
 * Stack data structure.
 * @param <Type> type of stack element
 */
public class Stack<Type> {

    /**
     * Stack element class.
     */
    private class StackElement {
        private Type value;
        private StackElement next;

        public StackElement(Type value, StackElement next) {
            this.value = value;
            this.next = next;
        }

        public Type getValue() {
            return value;
        }

        public StackElement getNext() {
            return next;
        }
    }

    private StackElement head = null;

    /**
     * Add element to top.
     * @param value element to be adding
     */
    public void push(Type value) {
        head = new StackElement(value, head);
    }

    /**
     * Get top element and remove it from Stack.
     * @return top element
     */
    public Type pop() {
        if (head == null) {
            return null;
        } else {
            Type value = head.getValue();
            head = head.getNext();
            return value;
        }
    }

    /**
     * Check if Stack is empty.
     * @return 'true' if Stack is empty or 'false' if not.
     */
    public boolean isEmpty() {
        return head == null;
    }
}