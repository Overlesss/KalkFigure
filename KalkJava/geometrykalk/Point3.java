package geometrykalk;


/**
 * Class that represents an ordered triplet (x,y,z) in the three-dimensional Euclidean space,
 * with the additional third double type number representing depth (z).
 */
public class Point3 extends Point2 {

	private double z;
	
	
	/**
	 * Constructor with two double type parameters
	 * @param d1 represents the abscissa value
	 * @param d2 represents the ordinate value
	 * @param d3 represents the z value
	 */
	public Point3(double d1, double d2, double d3) {
		super(d1, d2);
		z = d3;
	}

	
	/**
     * Default constructor which inizializes all the parameters to 0.0 
     */
	public Point3() {
		super();
		z = 0.0;
	}
	
	
	/**
     * @return z value of a point
     */
    public double getZ() {
    	return z;
    }
    
    
    /**
     * @return the distance between two points
     */
    public static double distance(Point3 p1, Point3 p2) {
    	return Math.sqrt(Math.pow(p2.getX() - p1.getX(), 2) + Math.pow(p2.getY() - p1.getY(), 2) + Math.pow(p2.z - p1.z, 2));
    }
    
    
    /**
     * @return the string representation of a 3-dimensional point
     */
    public String toString() {
    	return "(" + getX() + ", " + getY() + ", " + z + ")";
    }
}
