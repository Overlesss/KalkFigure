package geometrykalk;


/**
 * Class that represents a regular and convex polyhedron,
 * with the same number of congruent regular polygonal faces meeting at each vertex
 */
public abstract class PlatonicSolid extends Polyhedron {
	
	
	/**
	 * @return the symbol p of the Schlafli Symbol
	 */
	protected int schlafliSymbol_p() throws KalkException {
		return face().vertexCount();
	}
	
	/**
	 * @return the symbol p of the Schlafli Symbol
	 */
    protected abstract int schlafliSymbol_q();


    /**
	 * @param s is the name of the shape
	 */
    public PlatonicSolid(String s) {
    	super(s);
    }
    
    
    /**
	 * Default constructor
	 */
    public PlatonicSolid() {
    	super();
    }
    
    
    /**
     * Builds a platonic solid starting from its face @param p
     */
    protected abstract void createShape(Plane p) throws KalkException;

    /**
     * Each Platonic solid can be denoted by a symbol {p,q} where
     * p is the number of edges (or, equivalently, vertices) of each face, and
     * q is the number of faces (or, equivalently, edges) that meet at each vertex.
     * */
    public String schlafliSymbol() throws KalkException {
    	String s = "{" + schlafliSymbol_p() + "," + schlafliSymbol_q() + "}";
        return s;
    }

    
    /**
     * @return the length of the edge
     */
    public double edge() {
    	return Point3.distance(getPoints().get(0), getPoints().get(1));
    }
    
    
    public int faceCount() throws KalkException {
    	return schlafliSymbol_q() * vertexCount() / schlafliSymbol_p();
    }
    
    
    public int edgeCount() throws KalkException {
    	return faceCount() + vertexCount() - 2;
    }
    
    
    /**
     * @return the length of the radius of the incircle
     */
    public abstract double inRadius() throws KalkException;
    
    
    /**
     * @return the length of the radius of the circumcircle
     */
    public abstract double circumRadius();
    
    
    public double surface() throws KalkException {
    	return Math.pow(edge() / 2, 2) * faceCount() * schlafliSymbol_p() * (1 / Math.tan(Math.PI / schlafliSymbol_p()));
    }

    public abstract RegularPolygon face() throws KalkException ;  //function that returns the face shape; used for 3D->2D conversion

}
