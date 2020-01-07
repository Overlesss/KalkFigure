package geometrykalk;

import java.util.List;


public class Tetrahedron extends PlatonicSolid {
	
	
	/**
	 * Builds a tetrahedron starting from its face
	 */
	protected void createShape(Plane p) throws KalkException {
		//creates eight points representing the vertices of the tetrahedron (in the first quadrant)
		if(p instanceof EquilateralTriangle) {
			EquilateralTriangle t = (EquilateralTriangle) p;
	        List<Point2> vP = t.getPoints();
	        for(Point2 point : vP) {
	            setPoint(point.getX(), point.getY(), 0);
	        }
	        Point2 c = t.centreOfSymmetry(); //centre of the base shape
	        double h = height(t.side()); //height of the tetrahedron
	        setPoint(c, h);
	    } else throw new KalkException("It is not possible to build the object from the current plane shape.");
	}

	
	/**
	 * Constructor with one double type parameter
	 * @param s represents the length of the edge
	 * @throws KalkException if r is not a positive value
	 */
	public Tetrahedron(double e) throws KalkException {
		super("Tetrahedron");
		EquilateralTriangle s = new EquilateralTriangle(e);
		createShape(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public Tetrahedron() throws KalkException {
		this(1);
	}
	
	
	/**
	 * Constructor with one parameter, which represents its face.
	 * Used for 2D->3D conversion
	 */
	public Tetrahedron(EquilateralTriangle t) throws KalkException {
		super("Tetrahedron");
		createShape(t);
	}

	
	/**
	 * @return the height of the tetrahedron based on its edge @param e
	 */
	public static double height(double e) { 
	    return Math.sqrt(6) / 3 * e;
	}

	
	/**
	 * @return the surface of the solid, excluding the area of its base and top faces
	 */
	public double lateralSurface() {
	    return (3 * Math.sqrt(3)) / 4 * Math.pow(edge(), 2);
	}
	
	
	public int schlafliSymbol_q() {
		return 3;
	}
	
	
	public double inRadius() throws KalkException {
		return circumRadius() / 3;
	}
	
	
	public double circumRadius() {
	    return edge() * Math.sqrt(6) / 4;
	}
	
	
	public double volume() {
	    return Math.sqrt(2) / 12 * Math.pow(edge(), 3);

	}
	

	public EquilateralTriangle face() throws KalkException {
	    return new EquilateralTriangle(edge());
	}

	
	public Point3 centreOfSymmetry() throws KalkException {
		List<Point3> lP = getPoints();
		double z = 0.0;
		for(Point3 point : lP) {
	        z += point.getZ();
	    }
	    Point2 p = face().centreOfSymmetry();
	    return new Point3(p.getX(), p.getY(), z / 4);
	}

	
	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
		Tetrahedron t = new Tetrahedron(edge() + edge() * d / 100);
	    this.setEqual(t);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
		Tetrahedron t = new Tetrahedron(edge() + edge() * d / 100);
	    this.equals(t);
	}
	

	public Tetrahedron sum(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Tetrahedron t = (Tetrahedron) s;
	    double newEdge = edge() + t.edge();
	    return new Tetrahedron(newEdge);
	}
	
	
	public Tetrahedron difference(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Tetrahedron t = (Tetrahedron) s;
	    EquilateralTriangle faceDifference = face().difference(t.face()); //it may throw exceptions
	    return new Tetrahedron(faceDifference);
	}
	
	
	public Tetrahedron multiplication(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Tetrahedron c = (Tetrahedron) s;
	    double newEdge = edge() * c.edge();
	    return new Tetrahedron(newEdge);
	}
	
	
	public Tetrahedron division(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Tetrahedron c = (Tetrahedron) s;

	    //both operands are greater than 0
	    double newEdge = edge() / c.edge();
	    return new Tetrahedron(newEdge);
	}

}
