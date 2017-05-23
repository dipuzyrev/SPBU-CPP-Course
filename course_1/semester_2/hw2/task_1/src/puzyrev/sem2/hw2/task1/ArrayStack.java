package puzyrev.sem2.hw2.task1;

/**
 * Array-based Stack.
 *
 * @param <Type> type of Stack element
 */
public class ArrayStack<Type> implements Stack<Type> {
    private Type[] array;
    private int capacity = 0;
    private int top = 0;

    public ArrayStack(int capacity) {
        this.capacity = capacity;
        array = (Type[])(new Object[capacity]);
    }

    /**
     * Enlarge array capacity if it is too small.
     */
    private void enlarge() {
        Type[] newArray = (Type[])(new Object[capacity * 2]);
        System.arraycopy(array, 0, newArray, 0, capacity);
        capacity *= 2;
        array = newArray;
    }

    public void push(Type value) {
        if (top == capacity) {
            enlarge();
        }

        array[top++] = value;
    }

    public Type pop() {
        if (top == 0) {
            return null;
        }

        return array[--top];
    }

    public boolean isEmpty() {
        return top == 0;
    }
}