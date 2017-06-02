package puzyrev.sem2.hw4.task2;

/**
 * List which contains only unique elements.
 * @param <T> List elements type
 */
public class UniqueList<T extends Comparable> implements List<T> {
    private Element first = null;
    private Element last = null;
    private int size = 0;

    public void add(T value) throws ValueAlreadyExist {
        if (contains(value)) {
            throw new ValueAlreadyExist();
        }

        size++;

        if (isEmpty()) {
            first = new Element(value, null);
            last = first;
            return;
        }

        last.next = new Element(value, null);
        last = last.next;
    }

    public void remove(T value) throws ValueNotFound {
        if (!contains(value)) {
            throw new ValueNotFound();
        }

        if (isEmpty()) {
            return;
        }

        Element temp = first;
        if (temp.next == null && temp.value.compareTo(value) == 0) {
            first = null;
            last = null;
            size--;
            return;
        }

        if (temp.value.compareTo(value) == 0) {
            first = temp.next;
            return;
        }

        while (temp.next.value.compareTo(value) != 0) {
            temp = temp.next;
        }

        temp.next = temp.next.next;
        size--;

        last = (temp.next == null) ? temp : last;
    }

    public T extractFirst() {
        if (first != null) {
            T value = first.value;
            first = first.next;
            size--;
            return value;
        }

        return null;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return size;
    }

    public boolean contains(T value) {
        if (isEmpty()) {
            return false;
        }

        Element temp = first;
        while (temp != null) {
            if (temp.value.compareTo(value) == 0) {
                return true;
            }
            temp = temp.next;
        }

        return false;
    }

    public void print() {
        Element temp = first;

        while (temp != null) {
            System.out.print(temp.value + " ");
            temp = temp.next;
        }

        System.out.println();
    }

    /** Class for List elements. */
    private class Element {
        public T value;
        public Element next;

        public Element(T value, Element next) {
            this.value = value;
            this.next = next;
        }
    }

    /** Adding element which already contains. */
    public static class ValueAlreadyExist extends RuntimeException {
        public ValueAlreadyExist() {
            super("Element is already exist in the UniqueList");
        }
    }
    /** Removing element which doesn't contains in list. */
    public static class ValueNotFound extends RuntimeException {
        public ValueNotFound() {
            super("Element not found in the UniqueList");
        }
    }
}