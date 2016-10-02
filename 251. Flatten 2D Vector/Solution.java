public class Vector2D implements Iterator<Integer> {
    Iterator<List<Integer>> rowIterator;
    Iterator<Integer> colIterator;

    public Vector2D(List<List<Integer>> vec2d) {
        rowIterator = vec2d.listIterator();
        if (rowIterator.hasNext()) {
        }
        
    }

    @Override
    public Integer next() {
        if (colIterator.hasNext())
            return colIterator.next();
        if (rowIterator.hasNext()) {
            
            return colIterator.next();
        }
        return null;
    }

    @Override
    public boolean hasNext() {
        return rowIterator.hasNext() || colIterator.hasNext();     
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i = new Vector2D(vec2d);
 * while (i.hasNext()) v[f()] = i.next();
 */