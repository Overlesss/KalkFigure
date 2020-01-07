package geometrykalk;

public class PentagonalPrism extends RightPrism{

	
	/**
	 * Constructor with two double type parameters
	 * @param e the length of the base's side
	 * @param h represents the height of the solid
	 * @throws KalkException if all parameters have not positive values
	 */
	public PentagonalPrism(double e, double h) throws KalkException {
		super("Pentagonal Prism");
		RegularPentagon p = new RegularPentagon(e); //it may throw an exception
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(p, h);
	}
	
	
	/**
	 * Default constructor
	 */
	public PentagonalPrism() throws KalkException {
		this(1, 1);
	}
	
	
	/**
	 * Constructor with two parameters
	 * @param p represents the base shape
	 * @param h represents the height of the solid
	 * @throws KalkException if h has not positive value
	 * Used for 2D->3D conversion
	 */
	public PentagonalPrism(RegularPentagon p, double h) throws KalkException {
		super("Pentagonal Prism");
		if(h <= 0)
			throw new KalkException("Value/values must be greater than 0.");
	    createShape(p, h);
	}
	
	
	/**
	 * Constructor with one parameter
	 * @param p represents the base shape
	 * Used for 2D->3D conversion
	 */
	public PentagonalPrism(RegularPentagon p) throws KalkException {
		this(p, 1);
	}
	
	
	public RegularPentagon baseShape() throws KalkException {
        return new RegularPentagon(Point2.distance(getPoints().get(0), getPoints().get(2)));
    }
    
    
    public void expand(double d) throws KalkException {
		RegularPentagon newBase = baseShape();
	    newBase.expand(d); //it may throw an exception
	    PentagonalPrism p = new PentagonalPrism (newBase, height() + height() * d / 100);
	    this.setEqual(p);
	}
	
	
	public void reduce(double d) throws KalkException {
		RegularPentagon newBase = baseShape();
	    newBase.reduce(d); //it may throw an exception
	    PentagonalPrism p = new PentagonalPrism (newBase, height() - height() * d / 100);
	    this.setEqual(p);
	}
	

	public PentagonalPrism sum(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		PentagonalPrism p = (PentagonalPrism) s;
		RegularPentagon sumBase = baseShape().sum(p.baseShape());
	    return new PentagonalPrism(sumBase, height() + p.height());
	}
	
	
	public PentagonalPrism difference(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		PentagonalPrism p = (PentagonalPrism) s;
		
		if(p.isGreater(this))
			throw new KalkException("The shape is too big. Cannot subtract a bigger shape from a smaller one.");
	    double newEdge = Math.abs(baseShape().side() - p.baseShape().side());
	    double newHeight = Math.abs(height() - p.height());

	    //case 1 : both heights and base shapes are congruent
	   if(newEdge == 0 && newHeight == 0)
		   throw new KalkException("The two shapes are congruent. Their difference would delete the object.");

	   RegularPentagon newBase;
	   try { newBase = new RegularPentagon(newEdge); }
	   catch(KalkException err) {
	       //case 2: congruent base shapes but different heights
	       //error catched is ignored, new base shape will be equal to the current object's one
	       newBase = baseShape();
	   }

	    return new PentagonalPrism(newBase, newHeight);
	}
	
	
	public PentagonalPrism multiplication(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		PentagonalPrism p = (PentagonalPrism) s;
		RegularPentagon productBase = baseShape().multiplication(p.baseShape());
	    return new PentagonalPrism(productBase, height() * p.height());
	}
	
	
	public PentagonalPrism division(Solid s) throws KalkException {
		if(s.getClass() != getClass())
			throw new KalkException("The two shapes are not of the same type.");
		PentagonalPrism p = (PentagonalPrism) s;

	    //both operands are greater than 0
		RegularPentagon quotientBase = baseShape().division(p.baseShape());
	    return new PentagonalPrism(quotientBase, height() / p.height());
	}
	
}
