package puzyrev.sem2.hw4.task1;

/**
 * List class that contain only unique elements.
 * @param <T> type of list elements
 */
public class UniqueList<T extends Comparable> extends LinkedList<T> implements List<T> {
    @Override
    public void addValue(T value) throws ElementAlreadyExist {
        if (doesExist(value)) {
            throw new ElementAlreadyExist();
        }
        super.addValue(value);
    }

    @Override
    public void deleteValue(T value) throws ElementNotFound {
        if (!doesExist(value)) {
            throw new ElementNotFound();
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
    public static class ElementAlreadyExist extends RuntimeException {
        public ElementAlreadyExist() {
            super("Element is exist in the UniqueList");
        }
    }
    /** Removing element which doesn't exist. */
    public static class ElementNotFound extends RuntimeException {
        public ElementNotFound() {
            super("Element not found in the UniqueList");
        }
    }
}
