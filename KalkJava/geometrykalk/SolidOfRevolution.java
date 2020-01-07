package geometrykalk;


/**
 * Class that represents a solid shape
 * obtained by rotating a plane shape around a straight line (the axis of revolution)
 * which lies on the same plane
 */
public abstract class SolidOfRevolution extends Solid {
	
	
	/**
	 * @param s is the name of the shape
	 */
	public SolidOfRevolution(String s) {
		super(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public SolidOfRevolution() {
		super();
	}

	
	/**
	 * @return the rotated plane shape
	 */
    public abstract Plane shapeRotated() throws KalkException;

    
    /**
     * @return the height of the solid
     */
    public abstract double height();

}
