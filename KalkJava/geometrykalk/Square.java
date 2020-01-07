package geometrykalk;

public class Square extends RegularPolygon {
	
	
	/**
	 * Constructor with one double type parameter
	 * @param s represents the length of the side
	 * @throws KalkException if r is not a positive value
	 */
	public Square(double s) throws KalkException {
		super("Square");
	    if(s <= 0) throw new KalkException("Value/values must be greater than 0.");
	    createShape(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public Square() throws KalkException {
		this(1);
	}
	
	
	/**
	 * Builds a square starting from the length of its side
	 */
	private void createShape(double side) {
		//creates four points representing the vertices of the square (in the first quadrant)
	    setPoint(0, 0);
	    setPoint(0, side);
	    setPoint(side, 0);
	    setPoint(side, side);
	}
	

	/**
	 * @return the length of the diagonal
	 */
	public double diagonal(double side) {
		return Math.sqrt(2) * side();
	}
	

	public Point2 centreOfSymmetry() {
	    return new Point2(side() / 2, side() / 2);
	}
	

	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
		Square s = new Square(side() + side() * d / 100);
	    this.setEqual(s);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
		Square s = new Square(side() + side() * d / 100);
	    this.equals(s);
	}
	

	public Square sum(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Square s = (Square) p;
	    double sum = side() + s.side();
	    return new Square(sum);
	}
	
	
	public Square difference(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Square s = (Square) p;
	    if(s.isGreater(this))
	    	throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
	    double difference = side() - s.side();
	    if(difference == 0)
	    	throw new KalkException("The two shapes are congruent. Their difference would delete the object.");
	    return new Square(difference);
	}
	
	
	public Square multiplication(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Square s = (Square) p;
	    double product = side() * s.side();
	    return new Square(product);
	}
	
	
	public Square division(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Square s = (Square) p;

	    //both operands are greater than 0
	    double quotient = side() / s.side();
	    return new Square(quotient);
	}

}
