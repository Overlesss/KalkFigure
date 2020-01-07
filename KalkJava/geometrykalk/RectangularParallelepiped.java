package geometrykalk;

public class RectangularParallelepiped extends RightPrism {

	
	/**
	 * Constructor with three double type parameters
	 * @param bR represents the length of the base shape's base
	 * @param hR represents the length of the base shape's height
	 * @param h represents the height of the solid
	 * @throws KalkException if all parameters have not positive values
	 */
	public RectangularParallelepiped(double bR, double hR, double h) throws KalkException {
		super("Rectangular Parallelepiped");
		Rectangle r = new Rectangle(bR, hR); //it may throw an exception
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(r, h);
	}
	
	
	/**
	 * Default constructor
	 */
	public RectangularParallelepiped() throws KalkException {
		this(2, 1, 1);
	}
	
	
	/**
	 * Constructor with two parameters
	 * @param r represents the base shape
	 * @param h represents the height of the solid
	 * @throws KalkException if h has not positive value
	 * Used for 2D->3D conversion
	 */
	public RectangularParallelepiped(Rectangle r, double h) throws KalkException {
		super("Rectangular Parallelepiped");
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(r, h);
	}
    
	
	/**
	 * Constructor with one parameter
	 * @param r represents the base shape
	 * Used for 2D->3D conversion
	 */
	public RectangularParallelepiped(Rectangle r) throws KalkException {
		this(r, 1);
	}

    
    public Rectangle baseShape() throws KalkException {
    	double base = Point2.distance(getPoints().get(0), getPoints().get(2));
        double height = Point2.distance(getPoints().get(0), getPoints().get(4));
        return new Rectangle(base, height);
    }
    
    
    public void expand(double d) throws KalkException {
		Rectangle newBase = baseShape();
	    newBase.expand(d); //it may throw an exception
	    RectangularParallelepiped p = new RectangularParallelepiped (newBase, height() + height() * d / 100);
	    this.setEqual(p);
	}
	
	
	public void reduce(double d) throws KalkException {
		Rectangle newBase = baseShape();
	    newBase.reduce(d); //it may throw an exception
	    RectangularParallelepiped p = new RectangularParallelepiped (newBase, height() - height() * d / 100);
	    this.setEqual(p);
	}
	

	public RectangularParallelepiped sum(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RectangularParallelepiped p = (RectangularParallelepiped) s;
		Rectangle sumBase = baseShape().sum(p.baseShape());
	    return new RectangularParallelepiped(sumBase, height() + p.height());
	}
	
	
	public RectangularParallelepiped difference(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RectangularParallelepiped p = (RectangularParallelepiped) s;
		
		if(p.isGreater(this))
			throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
		double newBaseB = Math.abs(baseShape().base() - p.baseShape().base());
	    double newBaseH = Math.abs(baseShape().height() - p.baseShape().height());
	    double newHeight = Math.abs(height() - p.height());

	    //case 1 : both heights and base shapes are congruent
	   if(newBaseB == 0 && newBaseH == 0 && newHeight == 0)
		   throw new KalkException("The two shapes are congruent. Their difference would delete the object.");

	   Rectangle newBase;
	   try { newBase = new Rectangle(newBaseB, newBaseH); }
	   catch(KalkException err) {
	       //case 2: congruent base shapes but different heights
	       //error catched is ignored, new base shape will be equal to the current object's one
	       newBase = baseShape();
	   }

	    return new RectangularParallelepiped(newBase, newHeight);
	}
	
	
	public RectangularParallelepiped multiplication(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RectangularParallelepiped p = (RectangularParallelepiped) s;
		Rectangle productBase = baseShape().multiplication(p.baseShape());
	    return new RectangularParallelepiped(productBase, height() * p.height());
	}
	
	
	public RectangularParallelepiped division(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		RectangularParallelepiped p = (RectangularParallelepiped) s;

	    //both operands are greater than 0
		Rectangle quotientBase = baseShape().division(p.baseShape());
	    return new RectangularParallelepiped(quotientBase, height() / p.height());
	}
    
}
