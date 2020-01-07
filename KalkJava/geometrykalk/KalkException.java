package geometrykalk;


/**
 * Class that allows Kalk's error handling.
 */
public class KalkException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private String err;
	
	
	/**
	 * @param mess contains the string error
	 * which must be assigned to err.
	 */
	public KalkException(final String mess) { err = mess; }
	
	
	/**
	 * @return the string containing the error message.
	 * */
    String getError() { return err; }
}
