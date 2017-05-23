package puzyrev.sem2.hw1.task1;

public class Stack<Type> {
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

    public void push(Type value) {
        head = new StackElement(value, head);
    }

    public Type pop() {
        if (head == null) {
            return null;
        } else {
            Type value = head.getValue();
            head = head.getNext();
            return value;
        }
    }

    public boolean isEmpty() {
        return head == null;
    }
}