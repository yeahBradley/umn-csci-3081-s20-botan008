### Fuller Feedback for Lab 08

Run on February 22, 02:46:44 AM.


#### System Files and Lab Directory Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab08_google_tests" exists.

+ Pass: Make directory "Lab08_Testing".

+ Pass: Change into directory "Lab08_Testing".


#### Essential Files Exist

+ Pass: Check that file "../labs/lab08_google_tests/date_unittest.cc" exists.


### Testing correct implementation

+ Pass: Copy directory "Lab08 files.".



+ Pass: Copy directory "Files for correct version".



+ Pass: Change into directory "correct".

+ Pass: Check that make compiles.



+ Pass: Check that file "date_unittest" exists.

+ Pass: Get all google tests.
    12 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTestsWithNewline.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTestsWithoutNewline.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintUsDateTestsWithNewline.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintUsDateTestsWithoutNewline.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.GetDateTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.GetUsDateTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.DaysBetweenTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.OperatorminusTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.OperatorplusTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.ConstructorEpochTests.



+ Fail: Check that a GoogleTest test passes.
    fails the test: DateTest.ConstructerDefaultTests.
<pre>
[ RUN      ] DateTest.ConstructerDefaultTests
./date_unittest.cc:235: Failure
      Expected: test3.GetDate()
      Which is: "2020-02-21"
To be equal to: test1.GetDate()
      Which is: "2020-02-22"</pre>



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.ConstructorParamTests.



+ Fail: 91.67% of the tests passed, but the target is 100%.


### Testing Mutants


#### Testing Mutant 1 for failure

+ Pass: At least one test failed for Mutant 1


#### Testing Mutant 2 for failure

+ Pass: At least one test failed for Mutant 2


#### Testing Mutant 3 for failure

+ Pass: At least one test failed for Mutant 3


#### Testing Mutant 4 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Today's date month off by one


#### Testing Mutant 5 for failure

+ Pass: At least one test failed for Mutant 5


#### Testing Mutant 6 for failure

+ Pass: At least one test failed for Mutant 6


#### Testing Mutant 7 for failure

+ Pass: At least one test failed for Mutant 7


#### Testing Mutant 8 for failure

+ Pass: At least one test failed for Mutant 8


#### Testing Mutant 9 for failure

+ Pass: At least one test failed for Mutant 9

