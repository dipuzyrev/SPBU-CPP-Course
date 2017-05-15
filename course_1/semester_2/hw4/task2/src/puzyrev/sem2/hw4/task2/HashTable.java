package puzyrev.sem2.hw4.task2;

public class HashTable<T extends Comparable> {
    private static final int INIT_SIZE = 1024;
    private static final int CRITICAL_LOAD_FACTOR = 5;

    private UniqueList<T>[] table;
    private Hasher hasher;

    private int addedElements;
    private int emptyCellsCount;
    private int collisionsCount;
    private int maxListLength;
    private int maxListHash;
    private int size;

    public HashTable(Hasher hasher) {
        table = new UniqueList[INIT_SIZE];
        this.hasher = hasher;

        addedElements = 0;
        emptyCellsCount = INIT_SIZE;
        collisionsCount = 0;
        maxListLength = 0;
        maxListHash = 0;
        size = INIT_SIZE;
    }

    public void add(T value) {
        if (loadFactor() > CRITICAL_LOAD_FACTOR) {
            resize();
        }

        int hash = hasher.getHash(value.toString(), size);

        if (table[hash] == null) {
            table[hash] = new UniqueList<>();
            table[hash].add(value);

            addedElements++;
            emptyCellsCount--;

            if (maxListLength == 0) {
                maxListLength = 1;
                maxListHash = hash;
            }
        }

        if (table[hash].contains(value)) {
            return;
        }

        table[hash].add(value);

        addedElements++;

        int listSize = table[hash].size();
        collisionsCount += (listSize == 2) ? 1 : 0;

        if (listSize > maxListLength) {
            maxListLength = listSize;
            maxListHash = hash;
        }
    }

    public void remove(T value) {
        int hash = hasher.getHash(value.toString(), size);

        if ((table[hash] == null) || (!table[hash].contains(value))) {
            return;
        }

        table[hash].remove(value);

        addedElements--;
        emptyCellsCount += (table[hash].size() == 0) ? 1 : 0;
        collisionsCount -= (table[hash].size() == 1) ? 1 : 0;
        maxListLength = (hash != maxListHash) ? maxListLength : getMaxListLength();
    }

    public boolean contains(T value) {
        int hash = hasher.getHash(value.toString(), size);
        return (table[hash] != null) && (table[hash].contains(value));
    }

    public String statistics() {
        String stat = "Added Elements: " + addedElements;
        stat += "\nSize: " + size;
        stat += "\nLoad Factor: " + loadFactor();
        stat += "\nCollisions Count: " + collisionsCount;
        stat += "\nMax List Length: " + maxListLength + "\n";

        return stat;
    }

    public void changeHasher(Hasher hasher) {
        this.hasher = hasher;
    }

    private int getMaxListLength() {
        int max = 0;

        for (int i = 0; i < size; i++) {
            if (table[i] != null) {
                int listSize = table[i].size();
                max = (listSize > max) ? listSize : max;
            }
        }

        return max;
    }

    private float loadFactor() {
        return (float) addedElements / size;
    }

    private void resize() {
        UniqueList<T>[] oldTable = table;
        int oldSize = size;

        addedElements = 0;
        emptyCellsCount = oldSize * 2;
        collisionsCount = 0;
        maxListLength = 0;
        size  = oldSize * 2;

        table = new UniqueList[size];

        for (int i = 0; i < oldSize; i++) {
            int listSize = oldTable[i].size();

            for (int j = 0; j < listSize; j++) {
                T value = oldTable[i].extractFirst();
                add(value);
            }
        }
    }
}
