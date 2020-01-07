package geometrykalk;

import java.util.List;

public class RightCircularCylinder extends SolidOfRevolution {

	
	/**
	 * Builds a right circular cylinder starting from its base shape and the length of its height
	 */
	private void createShape(Plane p, double h) throws KalkException {
		//creates three points representing the radius of the base and the height of the cylinder (in the first quadrant)
		if(p instanceof Circle) {
			Circle c = (Circle) p;
	        List<Point2> vP = c.getPoints();
	        for(Point2 point : vP) {
	            setPoint(point.getX(), point.getY(), 0);
	        }
	        Point2 centre = c.centreOfSymmetry(); //centroid of the base shape
	        setPoint(centre, h);
	    } else throw new KalkException("It is not possible to build the object from the current plane shape.");
	}
	

	/**
	 * Constructor with two double type parameters
	 * @param b represents the length of the base diameter
	 * @param h represents the height of the cylinder
	 * @throws KalkException if r and h are not positive values
	 */
	public RightCircularCylinder(double b, double h) throws KalkException {
		super("Right Circular Cylinder");
		Circle c = new Circle(b / 2); //it may throw an exception
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
		createShape(c, h);
	}
	
	
	/**
	 * Default constructor
	 */
	public RightCircularCylinder() throws KalkException {
		this(1, 1);
	}
	
	
	/**
	 * Constructor with two parameters
	 * @param c represents the base shape
	 * @param h represents the height of the solid
	 * @throws KalkException if h has not positive value
	 * Used for 2D->3D conversion
	 */
	public RightCircularCylinder(Circle c, double h) throws KalkException {
		super("Right Circular Cylinder");
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
		createShape(c, h);
	}

	
	/**
	 * Constructor with one parameter
	 * @param c represents the base shape
	 * Used for 2D->3D conversion
	 */
	public RightCircularCylinder(Circle c) throws KalkException {
		this(c, 1);
	}
	
	
	/**
	 * @return the base (and top) plane shape
	 * Used for 3D->2D conversion
	 */
	public Circle baseShape() throws KalkException {
	    return new Circle(radius());
	}
	
	
	public Rectangle shapeRotated() throws KalkException {
	    return new Rectangle(radius(), height());
	}

	
	/**
	 * @return the surface of the solid, excluding the area of its base and top faces
	 */
	public double lateralSurface() {
		return 2 * Math.PI * radius() * height();
	}
	
	
	/**
     * @return the length of the radius
     */
	public double radius() {
		return Point3.distance(getPoints().get(0), getPoints().get(1));
	}
	
	
	public double height() {
		return Point3.distance(getPoints().get(1), getPoints().get(2));
	}
	
	
	public double surface() {
		double baseSurface = Math.PI * Math.pow(radius(), 2);
	    return 2 * baseSurface + lateralSurface();
	}
	
	
	public double volume() {
		return Math.pow(radius(), 2) * Math.PI * height();
	}
	
	
	public Point3 centreOfSymmetry() throws KalkException {
	    Point2 p = baseShape().centreOfSymmetry();
	    return new Point3(p.getX(), p.getY(), height() / 2);
	}

	
	public void expand(double d) throws KalkException {
		Circle newBase = baseShape();
	    newBase.expand(d); //it may throw an exception
	    RightCircularCylinder c = new RightCircularCylinder (newBase, height() + height() * d / 100);
	    this.setEqual(c);
	}
	
	
	public void reduce(double d) throws KalkException {
		Circle newBase = baseShape();
	    newBase.reduce(d); //it may throw an exception
	    RightCircularCylinder c = new RightCircularCylinder (newBase, height() - height() * d / 100);
	    this.setEqual(c);
	}
	

	public RightCircularCylinder sum(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RightCircularCylinder c = (RightCircularCylinder) s;
		Circle sumBase = baseShape().sum(c.baseShape());
	    return new RightCircularCylinder(sumBase, height() + c.height());
	}
	
	
	public RightCircularCylinder difference(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RightCircularCylinder c = (RightCircularCylinder) s;
		
		if(c.isGreater(this))
			throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
	    double newRadius = Math.abs(radius() - c.radius());
	    double newHeight = Math.abs(height() - c.height());

	    //case 1 : both heights and base shapes are congruent
	   if(newRadius == 0 && newHeight == 0)
		   throw new KalkException("The two shapes are congruent. Their difference would delete the object.");

	   Circle newBase;
	   try { newBase = new Circle(newRadius); }
	   catch(KalkException err) {
	       //case 2: congruent base shapes but different heights
	       //error catched is ignored, new base shape will be equal to the current object's one
	       newBase = baseShape();
	   }

	    return new RightCircularCylinder(newBase, newHeight);
	}
	
	
	public RightCircularCylinder multiplication(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RightCircularCylinder c = (RightCircularCylinder) s;
		Circle productBase = baseShape().multiplication(c.baseShape());
	    return new RightCircularCylinder(productBase, height() * c.height());
	}
	
	
	public RightCircularCylinder division(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RightCircularCylinder c = (RightCircularCylinder) s;

	    //both operands are greater than 0
		Circle quotientBase = baseShape().division(c.baseShape());
	    return new RightCircularCylinder(quotientBase, height() / c.height());
	}
	
}
