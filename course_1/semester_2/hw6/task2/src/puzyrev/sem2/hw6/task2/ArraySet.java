package puzyrev.sem2.hw6.task2;

import java.util.*;

public class ArraySet<T> implements Set<T> {
    /** Array with array elements. */
    private ArrayList<T> array = new ArrayList<>();

    @Override
    public int size() {
        return array.size();
    }

    @Override
    public boolean isEmpty() {
        return array.isEmpty();
    }

    @Override
    public boolean contains(Object value) {
        return array.contains(value);
    }

    @Override
    public Iterator<T> iterator() {
        return array.iterator();
    }

    @Override
    public Object[] toArray() {
        return array.toArray();
    }

    @Override
    public <T> T[] toArray(T[] a) {
        return array.toArray(a);
    }

    @Override
    public boolean add(T value) {
        if (contains(value)) {
            return false;
        } else {
            return array.add(value);
        }
    }

    @Override
    public boolean remove(Object value) {
        return array.remove(value);
    }

    @Override
    public boolean containsAll(Collection<?> collection) {
        return array.containsAll(collection);
    }

    @Override
    public boolean addAll(Collection<? extends T> collection) {
        return array.addAll(collection);
    }

    @Override
    public boolean retainAll(Collection<?> collection) {
        return array.retainAll(collection);
    }

    @Override
    public boolean removeAll(Collection<?> collection) {
        return array.removeAll(collection);
    }

    @Override
    public void clear() {
        array.clear();
    }
}
