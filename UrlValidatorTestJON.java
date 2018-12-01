

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

	//public static final int ALLOW_ALL_SCHEMES;

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing
	   //Citation: from Apache Commons documentation: 
	   //https://commons.apache.org/proper/commons-validator/apidocs/org/apache/commons/validator/routines/UrlValidator.html
	   
	 
	   //using schemes var to specifically add two valid schemes in UrlValidator constructor
	   String urlStr1 = "https://stackoverflow.com";
	   System.out.println("Manual Test 1: " + urlStr1);
	   String[] schemes = {"http", "https"};
	   UrlValidator urlVal1 = new UrlValidator(schemes);
	   if(urlVal1.isValid(urlStr1)) {
		   System.out.println("PASS - url is valid\n");
	   }
	   else {
		   System.out.println("FAIL - url is valid but flagged invalid\n");
	   }
	   
	   
	   
	   //using default UrlValidator constructor - should allow http, https, ftp as valid schemes
	   String urlStr2 = "https://www.stackoverflow.com";
	   System.out.println("Manual Test 2: " + urlStr2);
	   UrlValidator urlVal2 = new UrlValidator();
	   if(urlVal2.isValid(urlStr2)) {
		   System.out.println("PASS - url is valid\n");
	   }
	   else {
		   System.out.println("FAIL - url is valid but flagged invalid\n");
	   }
	   
	   
	   //allow all schemes
	   String urlStr3 = "http://www.reddit.com";
	   System.out.println("Manual Test 3: " + urlStr3);
	   UrlValidator urlVal3 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(urlVal3.isValid(urlStr3)) {
		   System.out.println("PASS - url is valid\n");
	   }
	   else {
		   System.out.println("FAIL - url is valid but flagged invalid\n");
	   }
	   
	   
	 //allow all schemes
	   String urlStr4 = "ht//www.reddit.com";
	   System.out.println("Manual Test 4: " + urlStr4);
	   UrlValidator urlVal4 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(urlVal4.isValid(urlStr4)) {
		   System.out.println("FAIL - url is invalid but flagged valid\n");
	   }
	   else {
		   System.out.println("PASS - url is invalid\n");
	   }
	   
	 //no fragments
	   String urlStr5 = "http://www.reddit.";
	   System.out.println("Manual Test 5: " + urlStr5);
	   UrlValidator urlVal5 = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
	   if(urlVal5.isValid(urlStr5)) {
		   System.out.println("FAIL - url is invalid but flagged valid\n");
	   }
	   else {
		   System.out.println("PASS - url is invalid\n");
	   }
	   
	 //allow all schemes
	   // This test crashes - commenting it out so any other tests added to this file will run
	   /*
	   String urlStr6 = "https://stackoverflow.com";
	   System.out.println("Manual Test 6: " + urlStr6);
	   UrlValidator urlVal6 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(urlVal6.isValid(urlStr6)) {
		   System.out.println("PASS - url is valid\n");
	   }
	   else {
		   System.out.println("FAIL - url is valid but flagged invalid\n");
	   }
	   */
   }
   
   
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
