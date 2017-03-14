package puzyrev.sem2.hw1.task2;

public class List<Type> {
    private ListElement head;

    public List() {
        head = null;
    }

    public void addValue(Type value) {
        ListElement newElement = new ListElement(value, null);

        if (isEmpty()) {
            head = newElement;
        }

        ListElement temp = head;

        while (temp.getNext() != null && temp.getValue() != value) {
            temp = temp.getNext();
        }

        if (temp.getValue() != value) {
            temp.setNext(newElement);
        }
    }

    public boolean deleteValue(Type value) {
        if (isEmpty()) {
            return false;
        }

        if (head.getValue() == value) {
            head = head.getNext();
            return true;
        }

        ListElement temp = head;

        while (temp.getNext() != null && temp.getNext().getValue() != value) {
            temp = temp.getNext();
        }

        if (temp.getNext() == null) {
            return false;
        } else {
            temp.setNext(temp.getNext().getNext());
            return true;
        }
    }

    public boolean isEmpty() {
        return head == null;
    }

    private class ListElement {
        private Type value;
        private ListElement next;

        public ListElement(Type value, ListElement next) {
            this.value = value;
            this.next = next;
        }

        public Type getValue() {
            return value;
        }

        public ListElement getNext() {
            return next;
        }

        public void setNext(ListElement next) {
            this.next = next;
        }
    }
}
