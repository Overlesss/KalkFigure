package geometrykalk;

public class EquilateralTriangle extends RegularPolygon {
	
	
	/**
	 * Constructor with one double type parameter
	 * @param s represents the length of the side
	 * @throws KalkException if r is not a positive value
	 */
	public EquilateralTriangle(double s) throws KalkException {
		super("Equilateral Triangle");
	    if(s <= 0) throw new KalkException("Value/values must be greater than 0.");
	    createShape(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public EquilateralTriangle() throws KalkException {
		this(1);
	}
	
	
	/**
	 * Builds an equilateral triangle starting from the length of its side
	 */
	private void createShape(double side) {
		//creates three points representing the vertices of the triangle (in the first quadrant)
	    setPoint(0, 0);
	    setPoint(side, 0);
	    setPoint(side / 2, height(side));
	}
	

	/**
	 * @return the height of the triangle based on its side @param side
	 */
	public static double height(double side) {
		return (side * Math.sqrt(3)) / 2;
	}
	

	public Point2 centreOfSymmetry() {
		return new Point2(side() / 2, apothem());
	}
	

	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
		EquilateralTriangle t = new EquilateralTriangle(side() + side() * d / 100);
	    this.setEqual(t);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
		EquilateralTriangle t = new EquilateralTriangle(side() + side() * d / 100);
	    this.equals(t);
	}
	

	public EquilateralTriangle sum(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		EquilateralTriangle t = (EquilateralTriangle) p;
	    double sum = side() + t.side();
	    return new EquilateralTriangle(sum);
	}
	
	
	public EquilateralTriangle difference(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		EquilateralTriangle t = (EquilateralTriangle) p;
	    if(t.isGreater(this))
	    	throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
	    double difference = side() - t.side();
	    if(difference == 0)
	    	throw new KalkException("The two shapes are congruent. Their difference would delete the object.");
	    return new EquilateralTriangle(difference);
	}
	
	
	public EquilateralTriangle multiplication(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		EquilateralTriangle t = (EquilateralTriangle) p;
	    double product = side() * t.side();
	    return new EquilateralTriangle(product);
	}
	
	
	public EquilateralTriangle division(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		EquilateralTriangle t = (EquilateralTriangle) p;

	    //both operands are greater than 0
	    double quotient = side() / t.side();
	    return new EquilateralTriangle(quotient);
	}

}
