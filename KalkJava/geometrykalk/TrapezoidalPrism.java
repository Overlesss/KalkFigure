package geometrykalk;

public class TrapezoidalPrism extends RightPrism {
	
	/**
	 * Constructor with four double type parameters
	 * @param lbT represents the length of the base's long base
	 * @param sbT represents the length of the base's short base
	 * @param hT represents the base's height
	 * @param h represents the height of the solid
	 * @throws KalkException if all parameters have not positive values
	 */
	public TrapezoidalPrism(double lbT, double sbT, double hT, double h) throws KalkException {
		super("Trapezoidal Prism");
		IsoscelesTrapezoid t = new IsoscelesTrapezoid(lbT, sbT, hT); //it may throw an exception
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(t, h);
	}
	
	
	/**
	 * Default constructor
	 */
	public TrapezoidalPrism() throws KalkException {
		this(2, 1, 1, 1);
	}
	
	
	/**
	 * Constructor with two parameters
	 * @param t represents the base shape
	 * @param h represents the height of the solid
	 * @throws KalkException if h has not positive value
	 * Used for 2D->3D conversion
	 */
	public TrapezoidalPrism(IsoscelesTrapezoid t, double h) throws KalkException {
		super("Trapezoidal Prism");
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(t, h);
	}
	
	
	/**
	 * Constructor with one parameter
	 * @param p represents the base shape
	 * Used for 2D->3D conversion
	 */
	public TrapezoidalPrism(IsoscelesTrapezoid t) throws KalkException {
		this(t, 1);
	}
	
	
	public IsoscelesTrapezoid baseShape() throws KalkException {
		double longBase = Point2.distance(getPoints().get(0), getPoints().get(2));
	    double shortBase = Point2.distance(getPoints().get(4), getPoints().get(6));
	    double height = Point2.distance(new Point2((longBase - shortBase) / 2, 0), getPoints().get(4));
	    return new IsoscelesTrapezoid(longBase, shortBase, height);
    }
    
    
    public void expand(double d) throws KalkException {
		IsoscelesTrapezoid newBase = baseShape();
	    newBase.expand(d); //it may throw an exception
	    TrapezoidalPrism p = new TrapezoidalPrism (newBase, height() + height() * d / 100);
	    this.setEqual(p);
	}
	
	
	public void reduce(double d) throws KalkException {
		IsoscelesTrapezoid newBase = baseShape();
	    newBase.reduce(d); //it may throw an exception
	    TrapezoidalPrism p = new TrapezoidalPrism (newBase, height() - height() * d / 100);
	    this.setEqual(p);
	}
	

	public TrapezoidalPrism sum(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		TrapezoidalPrism p = (TrapezoidalPrism) s;
		IsoscelesTrapezoid sumBase = baseShape().sum(p.baseShape());
	    return new TrapezoidalPrism(sumBase, height() + p.height());
	}
	
	
	public TrapezoidalPrism difference(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		TrapezoidalPrism p = (TrapezoidalPrism) s;
		
		if(p.isGreater(this))
			throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
	    double newBaseLB = Math.abs(baseShape().longBase() - p.baseShape().longBase());
	    double newBaseSB = Math.abs(baseShape().shortBase() - p.baseShape().shortBase());
	    double newBaseH = Math.abs(baseShape().height() - p.baseShape().height());
	    double newHeight = Math.abs(height() - p.height());

	    //case 1 : both heights and base shapes are congruent
	   if(newBaseLB == 0 && newBaseSB == 0 && newBaseH == 0 && newHeight == 0)
		   throw new KalkException("The two shapes are congruent. Their difference would delete the object.");

	   IsoscelesTrapezoid newBase;
	   try { newBase = new IsoscelesTrapezoid(newBaseLB, newBaseSB, newBaseH); }
	   catch(KalkException err) {
	       //case 2: congruent base shapes but different heights
	       //error catched is ignored, new base shape will be equal to the current object's one
	       newBase = baseShape();
	   }

	    return new TrapezoidalPrism(newBase, newHeight);
	}
	
	
	public TrapezoidalPrism multiplication(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		TrapezoidalPrism p = (TrapezoidalPrism) s;
		IsoscelesTrapezoid productBase = baseShape().multiplication(p.baseShape());
	    return new TrapezoidalPrism(productBase, height() * p.height());
	}
	
	
	public TrapezoidalPrism division(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		TrapezoidalPrism p = (TrapezoidalPrism) s;

	    //both operands are greater than 0
		IsoscelesTrapezoid quotientBase = baseShape().division(p.baseShape());
	    return new TrapezoidalPrism(quotientBase, height() / p.height());
	}

}
