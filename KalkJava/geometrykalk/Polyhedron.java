package geometrykalk;


/**
 * Class that represents a solid with
 * flat polygonal faces, straight edges and sharp vertices
 */
public abstract class Polyhedron extends Solid {

	
	/**
	 * @param s is the name of the shape
	 */
	public Polyhedron(String s) {
		super(s);
	}
	
	
	/**
	 * Default constructor
	 */
	public Polyhedron() {
		super();
	}

	
	/**
	 * @return the number of vertices
	 */
    public int vertexCount() {
    	return getPoints().size();
    }
    
    
    /**
     * @return the number of faces
     */
    public abstract int faceCount() throws KalkException;
    
    
    /**
     * @return the number of edges
     */
    public abstract int edgeCount() throws KalkException;
}
