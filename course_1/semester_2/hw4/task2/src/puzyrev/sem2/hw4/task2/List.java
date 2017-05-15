package puzyrev.sem2.hw4.task2;

public interface List<T> {
    void add(T value);
    void remove(T value);
    T extractFirst();
    boolean isEmpty();
    int size();
    boolean contains(T value);
    void print();
}