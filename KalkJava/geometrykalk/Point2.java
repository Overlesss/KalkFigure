package geometrykalk;


/**
 * Class that represents an ordered pair (x,y) in the two-dimensional Euclidean space,
 * where the first one represents the horizontal (x),
 * and the second one represents the vertical (y).
 */
public class Point2 {
	
	/**
	 * x represents the abscissa of a point
	 */
	private double x;
	
	/**
	 * y represents the ordinate of a point
	 */
	private double y;

	
	/**
	 * Constructor with two double type parameters
	 * @param d1 represents the abscissa value
	 * @param d2 represents the ordinate value
	 */
    public Point2(double d1, double d2) {
    	x = d1;
    	y = d2;
    }

    
    /**
     * Default constructor which inizializes the parameters x and y to 0.0 
     */
	public Point2() {
		this(0.0, 0.0);
	}

	
	/**
	 * @return x value of a point
	 */
    public double getX() {
    	return x;
    }
    

    /**
     * @return y value of a point
     */
    public double getY() {
    	return y;
    }

    
    /**
     * @return the distance between two points
     */
    public static double distance(Point2 p1, Point2 p2) {
    	return Math.sqrt(Math.pow(p2.x-p1.x, 2) + Math.pow(p2.y-p1.y, 2));
    }

    
    /**
     * @return the string representation of a 2-dimensional point
     */
    public String toString() {
    	return "(" + x + ", " + y + ")";
    }

}
