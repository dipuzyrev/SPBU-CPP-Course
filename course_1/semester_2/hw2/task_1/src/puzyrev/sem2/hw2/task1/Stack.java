package puzyrev.sem2.hw2.task1;

import java.util.EmptyStackException;

public interface Stack<Type> {
    void push(Type value);
    Type pop();

    boolean isEmpty();
}
