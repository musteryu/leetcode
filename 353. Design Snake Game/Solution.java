public class SnakeGame {

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */

    private Deque<Integer> nodes;
    private Set<Integer> nodeSet;
    private int foodIndex;
    private int[][] food;
    private int width;
    private int height;

    public SnakeGame(int width, int height, int[][] food) {
        nodes = new LinkedList<Integer>();
        nodeSet = new HashSet<Integer>();
        nodes.offerLast(0);
        nodeSet.add(0);
        foodIndex = 0;
        this.food = food;
        this.width = width;
        this.height = height;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    public int move(String direction) {
        int snakeHead = nodes.peekLast();
        int row = snakeHead / width;
        int col = snakeHead % width;
        switch (direction) {
            case "U":
            row--; break;
            case "D":
            row++; break;
            case "L":
            col--; break;
            case "R":
            col++; break;
            default:
            break;
        }
        if (row < 0 || row >= height || col < 0 || col >= width) return -1;
        int newSnakeHead = row * width + col;
        if (foodIndex < food.length &&
            row == food[foodIndex][0] && col == food[foodIndex][1]) {
            foodIndex++;
        } else {
            int snakeTail = nodes.pollFirst();
            nodeSet.remove(snakeTail);
        }
        if (nodeSet.contains(newSnakeHead)) return -1;
        nodes.offerLast(newSnakeHead);
        nodeSet.add(newSnakeHead);
        return foodIndex;
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */