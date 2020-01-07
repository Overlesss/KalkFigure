package geometrykalk;

import java.util.List;
import java.util.ArrayList;


/**
 *Class that represents a 2-dimensional shape
 */
public abstract class Plane extends Shape {

	/**
	 * the Cartesian coordinates of the points on the plane that represent a 2-dimensional shape
	 */
	private List<Point2> points = new ArrayList<Point2>();

	/**
	 * @param d1 represents the abscissa
	 * @param d2 represents the ordinate
	 * to be assegned to a point in the two-dimensional Euclidean space
	 */
	protected void setPoint(double d1, double d2) {
		points.add(new Point2(d1, d2));
	}


	/**
	 * Constructor with 1 parameter,
	 * @param s is the name of the shape
	 */
	public Plane(String s) {
		super(s);
	}
	
	
	/**
     * Default constructor
     */
	public Plane() {
		super();
	}
	

	/**
	 * @return the points of a 2-dimensional shape
	 */
    List<Point2> getPoints() {
    	return points;
    }

    
    /**
     * if TD(*this) <= SimplePolygon, the radius is the length of the circumcircle of the polygon
     */
    public abstract double radius();
    
    
    /**
     * @return the path that surrounds a 2-dimensional shape
     */
    public abstract double perimeter();
    
    
    /**
     * @return the extent of a 2-dimensional shape on the plane
     */
    public abstract double area();

    
    /**
     * Assigns new name and points values to the current object, if different from the previous ones
     */
    Plane setEqual(Plane p) {
    	if(getName() != p.getName())
            setName(p.getName());
        points = p.points; //assigns new contents, replacing current contents of points and modifying its size accordingly.
        return this;
    }
    
    
    /**
     * @return true if two plane shapes have the same area
     */
    boolean isGreater(Plane p) {
    	return area() > p.area();
    }

    
    /**
     * @return the sum of two plane shapes of the same type
     */
    public abstract Plane sum(Plane p) throws KalkException;

    
    /**
     * @return the difference of two plane shapes of the same type
     */
    public abstract Plane difference(Plane p) throws KalkException; 

    
    /**
     * @return the product of two plane shapes of the same type
     */
    public abstract Plane multiplication(Plane p) throws KalkException;
    
    
    /**
     * @return the quotient of two plane shapes of the same type
     */
    public abstract Plane division(Plane p) throws KalkException;
}
