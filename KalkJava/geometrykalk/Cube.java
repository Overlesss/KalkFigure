package geometrykalk;

import java.util.List;


public class Cube extends PlatonicSolid {

	/**
	 * Builds a cube starting from its face
	 */
	protected void createShape(Plane p) throws KalkException {
		//creates eight points representing the vertices of the cube (in the first quadrant)
		if(p instanceof Square) {
			Square s = (Square) p;
	        double h = s.side();
	        List<Point2> vP = s.getPoints();
	        for(Point2 point : vP) {
	            setPoint(point.getX(), point.getY(), 0);
	            setPoint(point.getX(), point.getY(), h);
	        }
	    } else throw new KalkException("It is not possible to build the object from the current plane shape.");
	}

	
	/**
	 * Constructor with one double type parameter
	 * @param s represents the length of the edge
	 * @throws KalkException if r is not a positive value
	 */
	public Cube(double e) throws KalkException {
		super("Cube");
		Square s = new Square(e);
		createShape(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public Cube() throws KalkException {
		this(1);
	}
	
	
	/**
	 * Constructor with one parameter, which represents its face.
	 * Used for 2D->3D conversion
	 */
	public Cube(Square s) throws KalkException {
		super("Cube");
		createShape(s);
	}

	
	/**
	 * @return the length of the space diagonal, which is the segment connecting two vertices that are not on the same face
	 */
	public double spaceDiagonal() {
	    return edge() * Math.sqrt(3);
	}
	
	
	/**
	 * @return the surface of the solid, excluding the area of its base and top faces
	 */
	public double lateralSurface() {
	    return 4 * Math.pow(edge(), 2);
	}
	
	
	public int schlafliSymbol_q() {
		return 3;
	}
	
	
	public double inRadius() {
	    return edge() / 2;
	}
	
	
	public double circumRadius() {
	    return edge() * Math.sqrt(3) / 2;
	}
	
	
	public double surface() {
	    return 6 * Math.pow(edge(), 2);

	}
	
	
	public double volume() {
	    return Math.pow(edge(), 3);

	}
	

	public Square face() throws KalkException {
	    return new Square(edge());
	}

	
	public Point3 centreOfSymmetry() throws KalkException {
		Point2 p = face().centreOfSymmetry();
	    return new Point3(p.getX(), p.getY(), edge() / 2);
	}

	
	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
		Cube c = new Cube(edge() + edge() * d / 100);
	    this.setEqual(c);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
		Cube c = new Cube(edge() + edge() * d / 100);
	    this.equals(c);
	}
	

	public Cube sum(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Cube c = (Cube) s;
	    double newEdge = edge() + c.edge();
	    return new Cube(newEdge);
	}
	
	
	public Cube difference(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Cube c = (Cube) s;
	    Square faceDifference = face().difference(c.face()); //it may throw exceptions
	    return new Cube(faceDifference);
	}
	
	
	public Cube multiplication(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Cube c = (Cube) s;
	    double newEdge = edge() * c.edge();
	    return new Cube(newEdge);
	}
	
	
	public Cube division(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Cube c = (Cube) s;

	    //both operands are greater than 0
	    double newEdge = edge() / c.edge();
	    return new Cube(newEdge);
	}
}
