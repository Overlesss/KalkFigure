package geometrykalk;

import java.util.List;
import java.lang.reflect.Array;


public class Use {

	public static void main(String[] args) {
		

		// 1. PLANE SHAPES TEST
		try {	
		    Circle pC = new Circle(4);
		    IsoscelesTrapezoid pIT = new IsoscelesTrapezoid(4,3,3);
		    Square pS = new Square(4);
		    RegularPentagon pRP = new RegularPentagon(4);
	
		    Plane[] aPlane = new Plane[] {pC, pIT, pRP};
		    
		    for(int i = 0; i < Array.getLength(aPlane); ++i) {
		    	System.out.println(aPlane[i].getName() + " : ");
		    	System.out.println(" points created : ");
		    	List<Point2> lP = aPlane[i].getPoints();
		    	for(int j = 0; j < lP.size(); ++j) {
		    		System.out.print(lP.get(j).toString() + " ");
		        }
		    	System.out.print("\n");
		    	System.out.println(" centre of simmetry = " + aPlane[i].centreOfSymmetry().toString());
	
	            System.out.println(" - Geometric formulas test :");
		    	System.out.println("     area = " + aPlane[i].area());
		    	System.out.println("     perimeter = " + aPlane[i].perimeter());
		    	System.out.println("     radius = " + aPlane[i].radius());
	
		        if(aPlane[i] instanceof Circle) {
		        	Circle c0 = (Circle) aPlane[i];
			    	System.out.println("     diameter = " + c0.diameter());
	
		            System.out.println(" - Expansion / Reduction test :");
		            System.out.println("   create a new circle 'c1' copied from the current one 'c0' (they are congruent) :");
			    	Circle c1 = new Circle(c0.radius());
		            c1.expand(100);
		            System.out.println("     c1 new expanded radius (100% expansion) = " + c1.radius());
		            c1.reduce(50);
		            System.out.println("     c1 new reduced radius (50% reduction) = " + c1.radius());
		            
		            System.out.println(" - Binary operations test :");
		            System.out.println("   create a new circle 'c2' resulting from the sum of c0 and c1 :");
		            Circle c2 = new Circle();
		            c2 = c0.sum(c1);
		            System.out.println("     radius of c2 = " + c2.radius());
		            c2 = c2.difference(c0);
		            System.out.println("     radius of c2 after the subtraction of c0 from c2 = " + c2.radius());
		            c2 = c2.multiplication(c0);
		            System.out.println("     radius of c2 after the multiplication of c0 and c2 = " + c2.radius());
		            c2 = c2.division(c0);
		            System.out.println("     radius of c2 after the division between c2 and c0 = " + c2.radius());
		            
		            System.out.println(" - Other functions test :");
		            System.out.println("     c2 is greater that c1 : " + c2.isGreater(c1));
		        }
	
		        if(aPlane[i] instanceof IsoscelesTrapezoid) {
			        IsoscelesTrapezoid pIT2 = (IsoscelesTrapezoid) aPlane[i];
			        System.out.println("     vertex number = " + pIT2.vertexCount());
			        System.out.println("     long base length = " + pIT2.longBase());
			        System.out.println("     short base length = " + pIT2.shortBase());
			        System.out.println("     leg length = " + pIT2.leg());
			        System.out.println("     height = " + pIT2.height());
			        System.out.println("     diagonal length = " + pIT2.diagonal());
		        }
	
		        if(aPlane[i] instanceof RegularPentagon) {
			        RegularPentagon pRP2 = (RegularPentagon) aPlane[i];
			        System.out.println("     vertex number = " + pRP2.vertexCount());
			        System.out.println("     apothem length = " + pRP2.apothem());
			        System.out.println("     side length = " + pRP2.side());
			        System.out.println("     height = " + RegularPentagon.height(pRP2.side()));
			        System.out.println("     diagonal length = " + pRP2.diagonal(pRP2.side()));
		        }
		        System.out.println("\n");
		    }
	
		    
		    
		    // 2. SOLID SHAPES TEST
		    
		    Solid[] aSolid = new Solid[] {
		    		new RightCircularCylinder(4,4),
		    		new PentagonalPrism(4,4)
		    };	    		
	
		    Solid[] aSolidFromPlaneShape = new Solid[] {
		    		new Cube(pS)
		    };
		    
		    
		    for(int i = 0; i < Array.getLength(aSolid); ++i) {
		    	System.out.println(aSolid[i].getName() + " : ");
		    	System.out.println(" points created : ");
		    	List<Point3> lP = aSolid[i].getPoints();
		    	for(int j = 0; j < lP.size(); ++j) {
		    		System.out.print(lP.get(j).toString() + " ");
		        }
		    	System.out.print("\n");
		    	System.out.println(" centre of simmetry = " + aSolid[i].centreOfSymmetry().toString());
	
	            System.out.println(" - Geometric formulas test :");
		    	System.out.println("     volume = " + aSolid[i].volume());
		    	System.out.println("     surface = " + aSolid[i].surface());
	
		        if(aSolid[i] instanceof RightCircularCylinder) {
		        	RightCircularCylinder c0 = (RightCircularCylinder) aSolid[i];
		        	System.out.println("     shape rotated = " + c0.shapeRotated().getName());
		        	System.out.println("     base shape = " + c0.baseShape().getName());
		        	System.out.println("     radius = " + c0.radius());
		        	System.out.println("     height = " + c0.height());
		        	System.out.println("     lateral surface = " + c0.lateralSurface());
	
		            System.out.println(" - Expansion / Reduction test :");
		            System.out.println("   create a new cylinder 'c1' copied from the current one 'c0' (they are congruent) :");
		            Circle temp = new Circle(c0.radius());
		            RightCircularCylinder c1 = new RightCircularCylinder(temp, 4);
		            c1.expand(100);
		            System.out.println("     c1 new expanded radius (100% expansion) = " + c1.radius());
		            c1.reduce(50);
		            System.out.println("     c1 new reduced radius (50% reduction) = " + c1.radius());
		            
		            System.out.println(" - Binary operations test :");
		            System.out.println("   create a new cylinder 'c2' resulting from the sum of c0 and c1 :");
		            RightCircularCylinder c2 = new RightCircularCylinder();
		            c2 = c0.sum(c1);
		            System.out.println("     radius of c2 = " + c2.radius());
		            c2 = c2.difference(c0);
		            System.out.println("     radius of c2 after the subtraction of c0 from c2 = " + c2.radius());
		            c2 = c2.multiplication(c0);
		            System.out.println("     radius of c2 after the multiplication of c0 and c2 = " + c2.radius());
		            c2 = c2.division(c0);
		            System.out.println("     radius of c2 after the division between c2 and c0 = " + c2.radius());
		        }
	
		        if(aSolid[i] instanceof PentagonalPrism) {
			        PentagonalPrism pRP2 = (PentagonalPrism) aSolid[i];
	
			        System.out.println("     number of faces = " + pRP2.faceCount());
			        System.out.println("     number of edges = " + pRP2.edgeCount());
			        System.out.println("     number of vertices = " + pRP2.vertexCount());
			        System.out.println("     base shape = " + pRP2.baseShape().getName());
			        System.out.println("     height length = " + pRP2.height());
			        System.out.println("     lateral surface = " + pRP2.lateralSurface());
		        }
		        System.out.print("\n");
		    }
	
		    for(int i = 0; i < Array.getLength(aSolidFromPlaneShape); ++i) {
		    	System.out.println(aSolidFromPlaneShape[i].getName() + " : ");
		    	System.out.print(" points created : ");
		    	List<Point3> lP = aSolidFromPlaneShape[i].getPoints();
		    	for(int j = 0; j < lP.size(); ++j) {
		    		System.out.print(lP.get(j).toString() + " ");
		        }
		        System.out.print("\n");
		        System.out.println(" centre of simmetry = " + aSolidFromPlaneShape[i].centreOfSymmetry().toString());
	
	            System.out.println(" - Geometric formulas test :");
		    	System.out.println("     volume = " + aSolidFromPlaneShape[i].volume());
		    	System.out.println("     surface = " + aSolidFromPlaneShape[i].surface());
		        
		        if(aSolidFromPlaneShape[i] instanceof Cube) {
			        Cube pS2 = (Cube) aSolidFromPlaneShape[i];
			        System.out.println("     vertex number = " + pS2.vertexCount());
			        System.out.println("     face number = " + pS2.faceCount());
			        System.out.println("     edge number = " + pS2.edgeCount());
			        System.out.println("     lateral surface = " + pS2.lateralSurface());
			        System.out.println("     face shape = " + pS2.face().getName());
			        System.out.println("     edge length = " + pS2.edge());
			        System.out.println("     space diagonal length = " + pS2.spaceDiagonal());
			        System.out.println("     inRadius length = " + pS2.inRadius());
			        System.out.println("     circumRadius length = " + pS2.circumRadius());
			        System.out.println("     schlafli symbol = " + pS2.schlafliSymbol());
		        }
		    }
	
		}  catch (KalkException e) { System.out.println(e.getError());}

	}
}
