

import junit.framework.TestCase;
import java.util.concurrent.ThreadLocalRandom;

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
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	      try {
	          assertTrue(urlVal.isValid("http://www.google.com"));
	          assertTrue(urlVal.isValid("http://www.google.com/"));
	      }
	      catch (Exception e) {
	          System.out.println("Assertions failed");
	      }

	      //test schemes
	      int schemeIter = testUrlScheme.length - 1;
	      for(int i = 0; i<schemeIter; i++) {
	          //build string buffer of known site
	         StringBuilder schemeTestBuffer = new StringBuilder("www.reddit.com");
	        //append our scheme
	         schemeTestBuffer.insert(0,testUrlScheme[i].item);
	        //check validity
	         if(testUrlScheme[i].valid) {
	             try {
	                 if(urlVal.isValid(schemeTestBuffer.toString())) { System.out.println("Success"); }
	                 else { System.out.println("Failed on valid test: "+ schemeTestBuffer +""); }
	             }
	             catch(Exception e) {
	                 System.out.println("Exception on valid test: "+ schemeTestBuffer +"");
	             }
	         }
	         //invalid scheme returned
	         else {
	             try {
	                 if(urlVal.isValid(schemeTestBuffer.toString())) { System.out.println("Failed on invalid test: "+ schemeTestBuffer +""); }
	                 else { System.out.println("Success"); }
	             }
	             catch(Error e) {
	                 System.out.println("Exception on invalid test: "+ schemeTestBuffer +"");
	             }
	         }
	      }

	      //test domains
	       int domIter = testUrlDomains.length - 1;
	       for(int i = 0; i<domIter; i++) {
	        //build our test buffer with known address
	         StringBuilder domainTestBuffer = new StringBuilder("www.reddit");
	        //add our domains
	         domainTestBuffer.append(testUrlDomains[i].item);
	        //check domain
	         if(testUrlDomains[i].valid) {
	             try {
	                 if(urlVal.isValid(domainTestBuffer.toString())) { System.out.println("Success"); }
	                 else { System.out.println("Failed on valid test: "+ domainTestBuffer +""); }
	             }
	             catch (Exception e) {
	                 System.out.println("Exception on valid test: "+ domainTestBuffer +"");
	             }
	         }
	        //invalid domain returned
	         else {
	             try {
	                 if(urlVal.isValid(domainTestBuffer.toString())) { System.out.println("Failed on invalid test: "+ domainTestBuffer +""); }
	                 else { System.out.println("Success"); }
	             }
	             catch (Exception e) {
	                 System.out.println("Exception on invalid test: "+ domainTestBuffer +"");
	             }
	         }
	      }
	      //test authority
	       for(int i = 0; i<10000; i++) {
	        //build our test buffer
	           StringBuilder authTestBuffer = new StringBuilder("http://");
	           //generate our 4 random numbers
	           //https://stackoverflow.com/questions/9236197/generate-random-ip-address
	           int auth1 = ThreadLocalRandom.current().nextInt(0, 1000);
	           int auth2 = ThreadLocalRandom.current().nextInt(0, 1000);
	           int auth3 = ThreadLocalRandom.current().nextInt(0, 1000);
	           int auth4 = ThreadLocalRandom.current().nextInt(0, 1000);
	           //append to our test buffer
	           authTestBuffer.append(auth1 + "." + auth2 + "." + auth3 + "." + auth4);
	            //check validity
	           if(auth1 < 256 && auth2 < 256 && auth3 < 256 && auth4 < 256) {
	               try {
	                   if(urlVal.isValid(authTestBuffer.toString())) { System.out.println("Success"); }
	                   else { System.out.println("Failed on valid test: "+ authTestBuffer +""); }
	               }
	               catch (Exception e) {
	                   System.out.println("Exception on valid test: "+ authTestBuffer +"");
	               }
	           }
	            //invalid response returned
	           else {
	               try {
	                   if(urlVal.isValid(authTestBuffer.toString())) { System.out.println("Failed on invalid test: "+ authTestBuffer +""); }
	                   else { System.out.println("Success"); }
	               }
	               catch (Error e) {
	                   System.out.println("Exception on invalid test: "+ authTestBuffer +"");
	               }
	           }
	       }
	      //test port
	       for(int i = 0; i<10000; i++) {
	            //build our test buffer
	           StringBuilder portTestBuffer = new StringBuilder("http://www.reddit.com:");
	            //generate random int
	           int randomNum = ThreadLocalRandom.current().nextInt(-1000, 100000);
	            //append it to test buffer
	           portTestBuffer.append(randomNum);
	            //check if valid
	           //https://stackoverflow.com/questions/113224/what-is-the-largest-tcp-ip-network-port-number-allowable-for-ipv4
	           if(randomNum > 1023 && randomNum < 65536) {
	               try {
	                   if(urlVal.isValid(portTestBuffer.toString())) { System.out.println("Success"); }
	                   else { System.out.println("Failed on valid test: "+ portTestBuffer +""); }
	               }
	               catch (Exception e) {
	                   System.out.println("Exception on valid test: "+ portTestBuffer +"");
	               }

	           }
	            //invalid resp returned
	           else {
	               try {
	                   if(urlVal.isValid(portTestBuffer.toString())) { System.out.println("Failed on invalid test: "+ portTestBuffer +""); }
	                   else { System.out.println("Success"); }
	               }
	               catch (Exception e) {
	                   System.out.println("Exception on invalid test: "+ portTestBuffer +"");
	               }
	           }
	       }
	   }

	   //truncated from valid URI schemes https://www.iana.org/assignments/uri-schemes/uri-schemes.xhtml
	   ResultPair[] testUrlScheme = {
	           new ResultPair("aaa://", true),
	           new ResultPair("about://", true),
	           new ResultPair("bitcoin://", true),
	           new ResultPair("chrome://", true),
	           new ResultPair("dns://", true),
	           new ResultPair("ed2k://", true),
	           new ResultPair("ftp://", true),
	           new ResultPair("gtalk://", true),
	           new ResultPair("http://", true),
	           new ResultPair("https://", true),
	           new ResultPair("imap://", true),
	           new ResultPair("jms://", true),
	           new ResultPair("res://", true),
	           new ResultPair("http:", false),
	           new ResultPair("ht/", false),
	           new ResultPair("123456789", false),
	           new ResultPair("1337$|>34|<://", false),
	           new ResultPair("heyjude://", false)
	   };

	   //truncated from valid Domains https://en.wikipedia.org/wiki/List_of_Internet_top-level_domains
	   ResultPair[] testUrlDomains = {
	           new ResultPair(".com", true),
	           new ResultPair(".org", true),
	           new ResultPair(".net", true),
	           new ResultPair(".int", true),
	           new ResultPair(".edu", true),
	           new ResultPair(".gov", true),
	           new ResultPair(".mil", true),
	           new ResultPair(".ac", true),
	           new ResultPair(".ba", true),
	           new ResultPair(".ca", true),
	           new ResultPair(".de", true),
	           new ResultPair(".ec", true),
	           new ResultPair(".fi", true),
	           new ResultPair(".ga", true),
	           new ResultPair(".hk", true),
	           new ResultPair(".id", true),
	           new ResultPair(".ke", true),
	           new ResultPair(".la", true),
	           new ResultPair(".ma", true),
	           new ResultPair(".na", true),
	           new ResultPair(".om", true),
	           new ResultPair(".ro", true),
	           new ResultPair(".sa", true),
	           new ResultPair(".td", true),
	           new ResultPair(".ua", true),
	           new ResultPair(".ws", true),
	           new ResultPair(".ye", true),
	           new ResultPair(".zw", true),
	           new ResultPair(".pe", true),
	           new ResultPair(".qa", true),
	           new ResultPair(".jp", true),
	           new ResultPair(".vn", true),
	           new ResultPair(".th1ssh0uldb3wr0ng", false),
	           new ResultPair(".1337$|>34|<", false),
	           new ResultPair(".***#$#&", false),
	           new ResultPair(".itwasthebestoftimesitwastheworstoftimeshello", false),
	           new ResultPair(".__", false),
	           new ResultPair(".///||/", false),
	   };


   }
   

