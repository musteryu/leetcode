public class ZigzagIterator {
    private ListIterator<Integer> currItr;
    private ListIterator<Integer> nextItr;
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        if (v1 != null && !v1.isEmpty() && v2 != null && !v2.isEmpty()) {
            currItr = v1.listIterator();
            nextItr = v2.listIterator();
        } else if (v1 == null || v1.isEmpty()) {
            nextItr = currItr = v2.listIterator();
        } else if (v2 == null || v2.isEmpty()) {
            nextItr = currItr = v1.listIterator();
        } else {
            nextItr = currItr = null;
        }
    }

    public int next() {
        int val = currItr.next();
        if (!currItr.hasNext())
            currItr = nextItr;
        ListIterator<Integer> tmp = nextItr;
        nextItr = currItr;
        currItr = tmp;
        return val;
    }

    public boolean hasNext() {
        if (currItr == null) return false;
        return currItr.hasNext();
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */