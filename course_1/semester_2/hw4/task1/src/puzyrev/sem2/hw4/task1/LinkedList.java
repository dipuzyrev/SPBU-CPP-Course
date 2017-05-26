package puzyrev.sem2.hw4.task1;

/**
 * List class that can contain not unique elements.
 * @param <T> type of list elements
 */
public class LinkedList<T extends Comparable> implements List<T> {
    protected Element first = null;
    protected int size = 0;

    public void addValue(T value) {
        size++;

        if (isEmpty()) {
            first = new Element(value, null);
            return;
        }

        first = new Element(value, first);
    }

    public void deleteValue(T value) {
        if (isEmpty()) {
            return;
        }

        Element temp = first;
        if (temp.next == null && temp.value.compareTo(value) == 0) {
            first = null;
            size--;
            return;
        }

        if (temp.value.compareTo(value) == 0) {
            first = temp.next;
            return;
        }

        while (temp.next != null && temp.next.value.compareTo(value) != 0) {
            temp = temp.next;
        }

        if (temp.next == null) {
            return;
        }

        temp.next = temp.next.next;
        size--;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return size;
    }

    public void print() {
        Element temp = first;

        while (temp != null) {
            System.out.print(temp.value + " ");
            temp = temp.next;
        }

        System.out.println();
    }

    protected class Element {
        public T value;
        public Element next;

        public Element(T value, Element next) {
            this.value = value;
            this.next = next;
        }
    }
}
