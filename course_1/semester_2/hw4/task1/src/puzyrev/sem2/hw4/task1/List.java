package puzyrev.sem2.hw4.task1;

public interface List<T> {
    void addValue(T value);
    void deleteValue(T value);
    boolean isEmpty();
    int size();
    void print();
}
