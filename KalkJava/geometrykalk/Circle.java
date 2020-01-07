package geometrykalk;

public class Circle extends Plane {
	
	
	/**
	 * Constructor with one double type parameter
	 * @param r represents the length of the radius
	 * @throws KalkException if r is not a positive value
	 */
	public Circle(double r) throws KalkException {
		super("Circle");
	    if(r <= 0) throw new KalkException("Value/values must be greater than 0.");
	    createShape(r);
	}
	
	
	/**
	 * Default constructor
	 */
	public Circle() throws KalkException {
		this(1);
	}
	
	
	/**
	 * Builds a circle starting from the length of its radius
	 */
	private void createShape(double radius) {
		//creates two points representing the radius of the circle by calculating the segment's end points (in the first quadrant)
	    setPoint(radius, 0);
	    setPoint(radius, radius);
	}

	
	/**
	 * @return the length of the diameter
	 */
	public double diameter() {
		return 2 * radius();
    }
	
	
	public double radius() {
		return Point2.distance(getPoints().get(0), getPoints().get(1));
	}
	
	
	public double perimeter() {
		return 2 * radius() * Math.PI;
	}
	
	
	public double area() {
		return Math.PI * Math.pow(radius(), 2);
	}

	
	public Point2 centreOfSymmetry() {
		return new Point2(radius(), radius());
	}

	
	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
	    Circle c = new Circle(radius() + radius() * d / 100);
	    this.setEqual(c);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
	    Circle c = new Circle(radius() - radius() * d / 100);
	    this.setEqual(c);
	}

	
	public Circle sum(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
	    Circle rC = (Circle) p;
	    double sum = radius() + rC.radius();
	    return new Circle(sum);
	}
	
	
	public Circle difference(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
	    Circle rC = (Circle) p;
	    if(rC.isGreater(this))
	    	throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
	    double difference = radius() - rC.radius();
	    if(difference == 0)
	    	throw new KalkException("The two shapes are congruent. Their difference would delete the object.");
	    return new Circle(difference);
	}
	
	
	public Circle multiplication(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
	    Circle rC = (Circle) p;
	    double product = radius() * rC.radius();
	    return new Circle(product);
	}
	
	
	public Circle division(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
	    Circle rC = (Circle) p;

	    //both operands are greater than 0
	    double quotient = radius() / rC.radius();
	    return new Circle(quotient);
	}

}
