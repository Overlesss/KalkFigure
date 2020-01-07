package geometrykalk;

public class IsoscelesTrapezoid extends SimplePolygon {
	
	
	/**
	 * Constructor with three double type parameters
	 * @param lB represents the length of the long base
	 * @param sB represents the length of the short base
	 * @param h represents the height
	 * @throws KalkException if they are not a positive values
	 */
	public IsoscelesTrapezoid(double lB, double sB, double h) throws KalkException {
		super("Isosceles Trapezoid");
		if(lB <= 0 || sB <= 0 || h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(lB, sB, h);
	}
    
	
	/**
	 * Default constructor
	 */
	public IsoscelesTrapezoid() throws KalkException {
		this(2, 1, 1);
	}
	
	
	/**
	 * Builds an isosceles trapezoid starting from the length of its two bases and height
	 */
	private void createShape(double longBase, double shortBase, double height) {
		//creates four points representing the vertices of the trapezoid (in the first quadrant)
	    setPoint(0, 0);
	    setPoint(longBase, 0);
	    setPoint((longBase - shortBase) / 2, height);
	    setPoint(shortBase + (longBase - shortBase) / 2, height);
	}
	

	/**
	 * @return the length of the long base
	 */
	public double longBase() {
		return Point2.distance(getPoints().get(0), getPoints().get(1));
	}
	
	
	/**
	 * @return the length of the short base
	 */
	public double shortBase() {
		return Point2.distance(getPoints().get(2), getPoints().get(3));
	}
	
	
	/**
	 * @return the length of the leg
	 */
	public double leg() {
		return Point2.distance(getPoints().get(0), getPoints().get(2));
	}
	
	
	/**
	 * @return the height of the trapezoid
	 */
	public double height() {
		return Math.sqrt(Math.pow(leg(), 2) - Math.pow((longBase() - shortBase()) / 2, 2));
	}
	
	
	/**
	 * @return the length of the diagonal
	 */
	public double diagonal() {
		//using Pythagorean theorem
	    return Math.sqrt(longBase() * shortBase() + Math.pow(leg(), 2));
	}
	
	
	public double radius() {
    	Point2 c = centreOfSymmetry();
        Point2 p = getPoints().get(0);
        return Point2.distance(c, p);
    }
	
	
	public double perimeter() {
		return longBase() + shortBase() + 2 * leg();
	}
	
	
	public double area() {
		return ((longBase() + shortBase()) * height()) / 2 ;
	}
    	    

	public Point2 centreOfSymmetry() {
		double x = longBase() / 2;
	    double y = height() / 3 * ((2 * shortBase() + longBase()) / (shortBase() + longBase()));
	    return new Point2(x, y);
	}
	

	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
		double newShortBase = shortBase() + shortBase() * d / 100;
	    double newLongBase = longBase() + longBase() * d / 100;
	    double newHeight = height() + height() * d / 100;
		IsoscelesTrapezoid t = new IsoscelesTrapezoid(newLongBase, newShortBase, newHeight);
	    this.setEqual(t);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
		double newShortBase = shortBase() - shortBase() * d / 100;
	    double newLongBase = longBase() - longBase() * d / 100;
	    double newHeight = height() - height() * d / 100;
	    IsoscelesTrapezoid t = new IsoscelesTrapezoid(newLongBase, newShortBase, newHeight);
	    this.equals(t);
	}
	

	public IsoscelesTrapezoid sum(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		IsoscelesTrapezoid t = (IsoscelesTrapezoid) p;
		double sumLongBase = longBase() + t.longBase();
	    double sumShortBase = shortBase() + t.shortBase();
	    double sumHeight = height() + t.height();
	    return new IsoscelesTrapezoid(sumLongBase, sumShortBase, sumHeight);
	}
	
	
	public IsoscelesTrapezoid difference(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		IsoscelesTrapezoid t = (IsoscelesTrapezoid) p;
	    if(t.isGreater(this)) throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");

	    double longBaseDifference = Math.abs(longBase() - t.longBase());
	    double shortBaseDifference = Math.abs(shortBase() - t.shortBase());
	    double heightDifference = Math.abs(height() - t.height());
	    
	    //case 1 : equivalent heights and base shapes
	    if(shortBaseDifference == 0 && longBaseDifference == 0 && heightDifference == 0)
	    	throw new KalkException("The two shapes are congruent. Their difference would delete the object.");
	    
	  //case 2 : at least one between the height and the bases is different
	    if(longBaseDifference == 0) longBaseDifference = longBase();
	    if(shortBaseDifference == 0) shortBaseDifference = shortBase();
	    heightDifference = (2 * (area() - t.area())) / (longBaseDifference + shortBaseDifference);	    
	    
	    return new IsoscelesTrapezoid(longBaseDifference, shortBaseDifference, heightDifference);
	}
	
	
	public IsoscelesTrapezoid multiplication(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		IsoscelesTrapezoid t = (IsoscelesTrapezoid) p;
		double productLongBase = longBase() * t.longBase();
	    double productShortBase = shortBase() * t.shortBase();
	    double productHeight = height() * t.height();
	    return new IsoscelesTrapezoid(productLongBase, productShortBase, productHeight);
	}
	
	
	public IsoscelesTrapezoid division(Plane p) throws KalkException {
		if(p.getClass() != getClass()) throw new KalkException("The two shapes are not of the same type.");
		IsoscelesTrapezoid t = (IsoscelesTrapezoid) p;

	    //both operands are greater than 0
		double quotientLongBase = longBase() / t.longBase();
	    double quotientShortBase = shortBase() / t.shortBase();
	    double quotientHeight = height() / t.height();
	    return new IsoscelesTrapezoid(quotientLongBase, quotientShortBase, quotientHeight);
	}

}
