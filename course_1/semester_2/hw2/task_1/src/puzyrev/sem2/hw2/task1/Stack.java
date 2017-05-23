package puzyrev.sem2.hw2.task1;

public interface Stack<Type> {
    void push(Type value);
    Type pop();

    boolean isEmpty();
}