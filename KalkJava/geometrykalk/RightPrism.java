package geometrykalk;

import java.util.List;


/**
 * Class that represents a polyhedron comprising an n-sided polygonal base,
 * a second base which is a translated copy (rigidly moved without rotation) of the first,
 * and n other faces (necessarily all parallelograms) joining corresponding sides of the two bases;
 * the joining edges and faces are perpendicular to the base faces
 */
public abstract class RightPrism extends Polyhedron {
	
	
	/**
	 * Builds a right prism starting from its base plane shape and its height
	 */
	protected void createShape(Plane p, double h) throws KalkException {
		//creates 2n points representing the vertices of the polyhedron with n-sided polygonal base
	    //pP has to be a polygon
		
		if(p instanceof SimplePolygon) {
			SimplePolygon sp = (SimplePolygon) p;
	        List<Point2> lP = sp.getPoints();
	        
	        for(Point2 point : lP) {
	            setPoint(point.getX(), point.getY(), 0);
	            setPoint(point.getX(), point.getY(), h);
	        }
	    } else throw new KalkException("It is not possible to build the object from the current plane shape.");
	}


	/**
	 * @param s is the name of the shape
	 */
	public RightPrism(String n) {
		super(n);
	}
	
	
	/**
	 * Default constructor
	 */
	public RightPrism() {
		super();
	}

	
	/**
	 * @return the height of the prism
	 */
    public double height() {
    	return Point3.distance(getPoints().get(0), getPoints().get(1));
    }
    
    
    /**
     * @return the surface of the solid, excluding the area of its base and top faces
     */
    public double lateralSurface() throws KalkException {
    	return baseShape().perimeter() * height();
    }
    
    
    public int faceCount() throws KalkException {
    	return baseShape().vertexCount() + 2;
    }
    
    
    public int edgeCount() throws KalkException {
	    return baseShape().vertexCount() * 3;
    }
    
    
    public double surface() throws KalkException {
    	return baseShape().area() * 2 + lateralSurface();
    }
    
    
    public double volume() throws KalkException {
    	return baseShape().area() * height();
    }

    
    /**
     * @return the base (and top) plane shape.
     * Used for 3D->2D conversion.
     */
    public abstract SimplePolygon baseShape() throws KalkException;

    
    public Point3 centreOfSymmetry() throws KalkException {
    	Point2 p = baseShape().centreOfSymmetry();
        return new Point3(p.getX(), p.getY(), height() / 2);
    }

}
