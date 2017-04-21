package puzyrev.sem2.hw1.task2;

public class List<Type> {
    private ListElement head = null;

    public void addValue(Type value) {
        ListElement newElement = new ListElement(value, null);

        if (isEmpty()) {
            head = newElement;
        }

        ListElement temp = head;

        while (temp.next != null && temp.value != value) {
            temp = temp.next;
        }

        if (temp.value != value) {
            temp.next = newElement;
        }
    }

    public boolean deleteValue(Type value) {
        if (isEmpty()) {
            return false;
        }

        if (head.value == value) {
            head = head.next;
            return true;
        }

        ListElement temp = head;

        while (temp.next != null && temp.next.value != value) {
            temp = temp.next;
        }

        if (temp.next == null) {
            return false;
        } else {
            temp.next = temp.next.next;
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
    }
}
