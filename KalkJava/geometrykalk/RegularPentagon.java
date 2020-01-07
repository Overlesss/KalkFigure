package geometrykalk;

public class RegularPentagon extends RegularPolygon {
	
	
	/**
	 * Constructor with one double type parameter
	 * @param s represents the length of the side
	 * @throws KalkException if r is not a positive value
	 */
	public RegularPentagon(double s) throws KalkException {
		super("Regular Pentagon");
	    if(s <= 0) throw new KalkException("Value/values must be greater than 0.");
	    createShape(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public RegularPentagon() throws KalkException {
		this(1);
	}
	
	
	/**
	 * Builds a regular pentagon starting from the length of its side
	 */
	private void createShape(double side) {
		//creates five points representing the vertices of the pentagon (in the first quadrant)
	    double auxb = (diagonal(side) - side) / 2;
	    setPoint(auxb, 0);
	    setPoint(auxb + side, 0);

	    //using Pythagorean theorem on the a right triangle built using auxb as a base and l as the hypotenuse, auxh will be the height
	    double auxh = Math.sqrt(Math.pow(side, 2) - Math.pow(auxb, 2));
	    setPoint(0, auxh);
	    setPoint(diagonal(side), auxh);

	    setPoint(side / 2 + auxb, height(side));
	}
	

	/**
	 * @return the height of the pentagon based on its side @param side
	 */
	public static double height(double side) {
		return side * Math.sqrt(5 + 2 * Math.sqrt(5)) / 2;
	}
	
	
	/**
	 * @return the length of the diagonal
	 */
	public double diagonal(double side) {
	    return side * (1 + Math.sqrt(5)) / 2;
	}
	

	public Point2 centreOfSymmetry() {
		//a regular pentagon can be broken down into 5 identical isosceles triangles:
	    //the base of each triangle represents the side of the pentagon,
	    //the legs of each triangle represent the radii of the pentagon,
	    //the height of each triangle represents the apothem of the pentagon
	    double x = diagonal(side()) / 2;
	    double y = apothem();
	    return new Point2(x,y);
	}
	

	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
		RegularPentagon p = new RegularPentagon(side() + side() * d / 100);
	    this.setEqual(p);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
		RegularPentagon p = new RegularPentagon(side() + side() * d / 100);
	    this.equals(p);
	}
	

	public RegularPentagon sum(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RegularPentagon rp = (RegularPentagon) p;
	    double sum = side() + rp.side();
	    return new RegularPentagon(sum);
	}
	
	
	public RegularPentagon difference(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RegularPentagon rp = (RegularPentagon) p;
	    if(rp.isGreater(this))
	    	throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
	    double difference = side() - rp.side();
	    if(difference == 0)
	    	throw new KalkException("The two shapes are congruent. Their difference would delete the object.");
	    return new RegularPentagon(difference);
	}
	
	
	public RegularPentagon multiplication(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RegularPentagon rp = (RegularPentagon) p;
	    double product = side() * rp.side();
	    return new RegularPentagon(product);
	}
	
	
	public RegularPentagon division(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RegularPentagon rp = (RegularPentagon) p;

	    //both operands are greater than 0
	    double quotient = side() / rp.side();
	    return new RegularPentagon(quotient);
	}

}
