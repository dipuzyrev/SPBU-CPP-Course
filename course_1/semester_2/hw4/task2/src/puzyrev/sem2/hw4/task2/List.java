package puzyrev.sem2.hw4.task2;

/**
 * Interface for List classes.
 * @param <T> type of List elements
 */
public interface List<T> {

    /**
     * Add element to list.
     * @param value to add
     */
    void add(T value);

    /**
     * Remove element form list.
     * @param value to remove
     */
    void remove(T value);

    /**
     * Get first element and remove it from List.
     * @return first List element
     */
    T extractFirst();

    /**
     * Check if List is empty.
     * @return 'true' if List empty or 'false' if not
     */
    boolean isEmpty();

    /**
     * Get List size.
     * @return elements count
     */
    int size();

    /**
     * Check if List contains element.
     * @param value to check
     * @return 'true' if List contains element or 'false' if not
     */
    boolean contains(T value);

    /**
     * Print List to debugging.
     */
    void print();
}