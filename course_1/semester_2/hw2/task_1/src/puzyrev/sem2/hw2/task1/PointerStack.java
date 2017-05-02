package puzyrev.sem2.hw2.task1;

public class PointerStack<Type> implements Stack<Type> {
    private class StackElement {
        private Type value;
        private StackElement next;

        public StackElement(Type value, StackElement next) {
            this.value = value;
            this.next = next;
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
            Type value = head.value;
            head = head.next;
            return value;
        }
    }

    public boolean isEmpty() {
        return head == null;
    }
}
