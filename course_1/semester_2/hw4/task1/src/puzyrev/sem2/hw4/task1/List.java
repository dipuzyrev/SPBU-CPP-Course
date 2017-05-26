package puzyrev.sem2.hw4.task1;

/**
 * Interface for List classes.
 * @param <T> type of list elements
 */
public interface List<T> {

    /**
     * Add value to list.
     * @param value element to add
     */
    void addValue(T value);

    /**
     * Deleting element from list.
     * @param value of element to delete
     */
    void deleteValue(T value);

    /**
     * Check if list is empty.
     * @return 'true' if empty or 'false' if not
     */
    boolean isEmpty();

    /**
     * Get list size.
     * @return count of list elements
     */
    int size();

    /**
     * Print all list element for debugging.
     */
    void print();
}
