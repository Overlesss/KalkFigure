package geometrykalk;


/**
 * Class that represents a convex regular polygon, which is equiangular and equilateral
 */
public abstract class RegularPolygon extends SimplePolygon {
	
	
	/**
	 * @param s is the name of the shape
	 */
	public RegularPolygon(String s) {
		super(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public RegularPolygon() {
		super();
	}

	
	/**
	 * @return the length of the side
	 */
    public double side() {
    	return Point2.distance(getPoints().get(0), getPoints().get(1));
    }

    
    /**
     * @return the length of the line segment from the centroid to the midpoint of one of the sides
     */
    public double apothem() {
    	return side() / (2 * Math.tan(Math.PI / vertexCount()));
    }
    
    
    public double radius() {
    	Point2 c = centreOfSymmetry();
        Point2 p = getPoints().get(0);
        return Point2.distance(c, p);
    }
    
    
    public double perimeter() {
    	return side() * vertexCount();
    }
    
    
    public double area() {
    	return (apothem() * perimeter()) / 2;
    }

}
