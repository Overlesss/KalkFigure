package geometrykalk;

public class Rectangle extends SimplePolygon {
	
	
	/**
	 * Constructor with two double type parameters
	 * @param b represents the length of the base
	 * @param h represents the height
	 * @throws KalkException if they are not a positive values
	 */
	public Rectangle(double b, double h) throws KalkException {
		super("Rectangle");
		if(b <= 0 || h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(b, h);		
	}
	
	
	public Rectangle() throws KalkException {
		this(2, 1);
	}
	
	
	/**
	 * Builds a rectangle starting from the length of its base and height
	 */
	private void createShape(double base, double height) {
		//creates four points representing the vertices of the square (in the first quadrant)
	    setPoint(0, 0);
	    setPoint(base,0);
	    setPoint(0,height);
	    setPoint(base,height);
	}

	
	/**
	 * @return the length of the base
	 */
    public double base() {
    	return Point2.distance(getPoints().get(0), getPoints().get(1));
    }
    
    
    /**
     * @return the height of the rectangle
     */
    public double height()  {
    	return Point2.distance(getPoints().get(0), getPoints().get(2));
    }
    
    
    /**
     * @return the length of the diagonal
     */
    public double diagonal() {
    	return Math.sqrt(Math.pow(base(), 2) + Math.pow(height(), 2));    }

	
    public double radius() {
    	Point2 c = centreOfSymmetry();
        Point2 p = getPoints().get(0);
        return Point2.distance(c, p);
    }
    
    
    public double perimeter() {
		return base() * 2 + height() * 2;
	}
	
	
	public double area() {
		return base() * height();
	}
    	    

	public Point2 centreOfSymmetry() {
	    return new Point2(base() / 2, height() / 2);
	}
	

	public void expand(double d) throws KalkException {
		if(d < 0)
			throw new KalkException("Negative values not allowed.");
		double newBase = base() + base() * d / 100;
	    double newHeight = height() + height() * d / 100;
		Rectangle r = new Rectangle(newBase, newHeight);
	    this.setEqual(r);
	}
	
	
	public void reduce(double d) throws KalkException {
		if(d < 0 || d >= 100)
			throw new KalkException("Value out of range. It must be between 0 and 100.");
		double newBase = base() - base() * d / 100;
	    double newHeight = height() - height() * d / 100;
		Rectangle r = new Rectangle(newBase, newHeight);
	    this.setEqual(r);
	}
	

	public Rectangle sum(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Rectangle r = (Rectangle) p;
		double sumBase = base() + r.base();
	    double sumHeight = height() + r.height();
	    return new Rectangle(sumBase, sumHeight);
	}
	
	
	public Rectangle difference(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Rectangle r = (Rectangle) p;
	    if(r.isGreater(this)) throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");

	    double baseDifference = Math.abs(base() - r.base());
	    double heightDifference = Math.abs(height() - r.height());
	    
	    //case 1 : the two shapes are congruent
	    if(baseDifference == 0 && heightDifference == 0)
	    	throw new KalkException("The two shapes are congruent. Their difference would delete the object.");
	    
	    //case 2 : one between base/height of the current object is equal to the one of r
	    if(baseDifference == 0) baseDifference = base();
	        else if(heightDifference == 0) heightDifference = height();
	    
	    return new Rectangle(baseDifference, heightDifference);
	}
	
	
	public Rectangle multiplication(Plane p) throws KalkException {
		if(p.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		Rectangle r = (Rectangle) p;
		double productBase = base() * r.base();
	    double productHeight = height() * r.height();
	    return new Rectangle(productBase, productHeight);
	}
	
	
	public Rectangle division(Plane p) throws KalkException {
		if(p.getClass() != getClass()) throw new KalkException("The two shapes are not of the same type.");
		Rectangle r = (Rectangle) p;

	    //both operands are greater than 0
		double quotientBase = base() / r.base();
	    double quotientHeight = height() / r.height();
	    return new Rectangle(quotientBase, quotientHeight);
	}


}
