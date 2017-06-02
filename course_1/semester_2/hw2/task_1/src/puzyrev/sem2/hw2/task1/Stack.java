package puzyrev.sem2.hw2.task1;

/**
 * Interface for Stack classes.
 *
 * @param <Type> type of Stack element
 */
public interface Stack<Type> {
    /**
     * Add element to Stack.
     *
     * @param value element you want to add
     */
    void push(Type value);

    /**
     * Remove last element from Stack.
     *
     * @return removed element
     */
    Type pop();

    /**
     * Check if Stack is empty.
     *
     * @return true or false if Stack is empty on not
     */
    boolean isEmpty();
}