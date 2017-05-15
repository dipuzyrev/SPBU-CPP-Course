package puzyrev.sem2.hw4.task1;

public class UniqueList<T extends Comparable> extends LinkedList<T> implements List<T> {
    @Override
    public void addValue(T value) throws ElementDoesExist {
        if (doesExist(value)) {
            throw new ElementDoesExist();
        }
        super.addValue(value);
    }

    @Override
    public void deleteValue(T value) throws ElementDoesntExist {
        if (!doesExist(value)) {
            throw new ElementDoesntExist();
        }
        super.deleteValue(value);
    }

    private boolean doesExist(T value) {
        if (super.isEmpty())
            return false;
        Element temp = super.first;
        while (temp != null) {
            if (temp.next.value.compareTo(value) == 0)
                return true;
            temp = temp.next;
        }
        return false;
    }

    /** Adding element which already exists. */
    public static class ElementDoesExist extends RuntimeException {
        public ElementDoesExist() {
            super("Element is exist in the UniqueList");
        }
    }
    /** Removing element which doesn't exist. */
    public static class ElementDoesntExist extends RuntimeException {
        public ElementDoesntExist() {
            super("Element isn't exist in the UniqueList");
        }
    }
}
