package geometrykalk;

import java.util.List;
import java.util.ArrayList;


/**
 *Class that represents a 3-dimensional shape
 */
public abstract class Solid extends Shape {

	/**
	 * the Cartesian coordinates of the points on the space that represent a 3-dimensional shape
	 */
	private List<Point3> points = new ArrayList<Point3>();
	

	/**
	 * Assigns values to solid's points
	 */
	protected void setPoint(double d1, double d2, double d3) {
		points.add(new Point3(d1, d2, d3));
	}

	
	/**
	 * Assigns values to a solid shapes' points, starting from a 2-dimensional point
	 */
	protected void setPoint(Point2 p, double d) {
		points.add(new Point3(p.getX(), p.getY(), d));
	}


	/**
	 * Constructor with 1 parameter,
	 * @param s is the name of the shape
	 */
	public Solid(String s) {
		super(s);
	}
	
	
	/**
     * Default constructor
     */
	public Solid() {
		super();
	}
	

	/**
	 * @return the points of a 3-dimensional shape
	 */
    List<Point3> getPoints() {
    	return points;
    }

    
    
    /**
     * @return the total area that the surface of the solid shape occupies
     */
    public abstract double surface() throws KalkException;
    
    
    /**
     * @return the quantity of 3-dimensional space enclosed by a closed surface
     */
    public abstract double volume() throws KalkException;

    
    /**
     * Assigns new name and points values to the current object, if different from the previous ones
     */
    Solid setEqual(Solid p) {
    	if(getName() != p.getName())
            setName(p.getName());
        points = p.points; //assigns new contents, replacing current contents of points and modifying its size accordingly.
        return this;
    }
    
    
    /**
     * @return true if two solid shapes have the same area
     */
    boolean isGreater(Solid p) throws KalkException {
    	return volume() > p.volume();
    }

    
    /**
     * @return the sum of two solid shapes of the same type
     */
    public abstract Solid sum(Solid p) throws KalkException;

    
    /**
     * @return the difference of two solid shapes of the same type
     */
    public abstract Solid difference(Solid p) throws KalkException; 

    
    /**
     * @return the product of two solid shapes of the same type
     */
    public abstract Solid multiplication(Solid p) throws KalkException;
    
    
    /**
     * @return the quotient of two solid shapes of the same type
     */
    public abstract Solid division(Solid p) throws KalkException;
}
