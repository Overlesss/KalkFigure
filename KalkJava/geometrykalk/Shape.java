package geometrykalk;


/**
 * Class that represents a shape on the Cartesian coordinate system,
 * and implements its geometric functions.
 */
public abstract class Shape {
	
	/**
	 * name is the name of a shape
	 */
	private String name;

	
	/**
	 * Constructor with 1 parameter,
	 * @param s is the name of the shape
	 */
	public Shape(String s) {
		name = s;
	}
	
	
	/**
     * Default constructor which inizializes the name to an empty space 
     */
	public Shape() {
		this("");
	}

	
	/**
	 * @return the name of the shape
	 */
	public String getName() {
		return name;
	}

	
	/**
	 * @param s is the name to be assigned to the shape
	 */
    public void setName(String s) {
		name = s;
	}

    
    /**
     * @return the Cartesian coordinates of
     * the centroid for plane shapes,
     * and the centre of mass for solid shapes
     */
    public abstract Point2 centreOfSymmetry() throws KalkException;

    
    /**
     * @param d represents a percentage value of which a shape must be expanded
     */
    public abstract void expand(double d) throws KalkException;
    
    
    /**
     * @param d represents a percentage value of which a shape must be reduced
     */
    public abstract void reduce(double d) throws KalkException;
	
}
