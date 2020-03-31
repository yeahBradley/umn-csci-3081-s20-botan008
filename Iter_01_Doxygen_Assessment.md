### Iteration 1 - Doxygen Partial Assessment (Graded By: Brandon Voigt)

Run on March 30, 20:03:19 PM.

<hr>

This Partial Assessment indicates a TA has begun grading your Doxygen-generated documentation. However, documentation will be graded using a Canvas rubric and grades will only be posted on Canvas once every student's documentation has been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout iteration 1 final submission.




#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.


#### Doxygen Tests

+ Pass: Change into directory "project/docs".

+ Pass: Check that file "Doxyfile" exists.

+ Pass: Generating documentation by running doxygen

+ Pass: Check that file "html/index.html" exists.

+ Pass: Inspecting Doxygen webpages...



<hr>

This Partial Assessment indicates a TA has begun grading your branches and issues. However, this will be graded using a tallying spreadsheed and grades will only be posted to Canvas once every student's branches and issues have been graded. We ask for your patience at this time.

  Please note: Branches are counted throughout Iteration 1. We are looking for branches you made and left alone during Iteration 1. Issues however are counted for the entirety of the semester. We ran into some glitches automatically grading this, so this is the solution we came up with.

<hr>

+ Pass: Configuring GHI

+  _2_ / _2_ : Pass: This test counts the number of branches made during development of Iteration 1

Sufficient branches found (found=11, required=8):

Iter1/01-PL1-bus-class-indentation

Iter1/02-PL1-LoadPassenger-definition-change

Iter1/03-PL1-refactor-naming-Route-NextStop

Iter1/04-PL1-web-code-main-indentation

Iter1/05-PL1-add-new-route

Iter1/06-PL2-implement-bus-factory

Iter1/07-PL3-pause-resume

Iter1/08-PL4-skip-stops

Iter1/09-doxy-documentation

fix/01-compilation-errors

fix/02-google-style-pass

+  _1.3333333333333333_ / _2_ : Pass: Run ghi for total number of issues in Github repo (Found: 7, Expected: 8) 

 [OPEN issue #] : 

[CLOSED issue #7] :  Iter1: Doxygen Documentation [enhancement] 1 @botan008

[CLOSED issue #6] :  Iter1: Priority Level 4 [enhancement] 2 @botan008

[CLOSED issue #5] :  Iter1: Priority Level 3 [enhancement]

[CLOSED issue #4] :  Iter1: Priority Level 2 [enhancement]

[CLOSED issue #3] :  Iter1: Priority Level 1  [enhancement] @botan008

[CLOSED issue #2] :  Google style pass [enhancement]

[CLOSED issue #1] :  Compilation Error [bug]

 




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Bradley Botanel] 2020-03-24 (HEAD -> devel, tag: iteration1-final-devel, origin/devel) fixing a last minute merge conflict on mainpage.h 

		[Bradley Botanel] 2020-03-24 Merge branch 'Iter1/09-doxy-documentation' into devel #7 This merge completes issue #7. doxy-documentation is finished.


		[Bradley Botanel] 2020-03-24 (origin/Iter1/09-doxy-documentation, Iter1/09-doxy-documentation) docs(mainpage.h): #7 Doxygen mainpage update This will conclude the Doxygen documentation required for Iteration1. Mainpage.h includes all the required discussions and explanations.


		[Bradley Botanel] 2020-03-24 docs(large_bus_factory.h, large_bus.h, small_bus_factory.h, small_bus.h, regular_bus_factory.h, regular_bus.h, random_bus_factory.h, abstract_bus_factory.h): #7 Doxygen Pass This commit includes the Doxygen documentation pass of all the new factories and bus types.


		[Bradley Botanel] 2020-03-24 Style(mainpage.h and /src): #7 Created a mainpage.h and added documentation for the methods in passenger.h and passenger_factory.h/.cc.


		[Bradley Botanel] 2020-03-24 Merge branch 'devel' into Iter1/09-doxy-documentation Bringing the minor gitignore change that was done in devel to Iter1/09 #7


		[Bradley Botanel] 2020-03-24 docs(.gitignore): #7 Added an ignore for .nfs* files that randomly appear.


		[Bradley Botanel] 2020-03-24 Merge branch 'Iter1/09-doxy-documentation' into devel I mistakenly ran Doxygen in Devel instead of Iter1/09 branch. This merge
should alleviate this issue. #7


		[Bradley Botanel] 2020-03-24 docs(.gitignore): #7 Added /docs/html/ and /docs/latex/ to the .gitignore per lab 07 instructions.


		[Bradley Botanel] 2020-03-24 Merge branch 'Iter1/08-PL4-skip-stops' into devel Priority Level 4 is complete. Merging back into Devel


		[Bradley Botanel] 2020-03-24 (origin/Iter1/08-PL4-skip-stops, Iter1/08-PL4-skip-stops) feat(bus.cc and config.txt): #6 prints information to terminal when a bus skips a stop In terms of our simulation it is not necessary for a bus to "literally" skip a
stop. It need only check that it unloaded or loaded passengers when at the stop.
This feature prints to the terminal the bus id and stop id when that bus skips a stop.
This feature appears in the Bus::Move() function.

To better test this feature the probability a stop generates a passenger for all stops
in route 2 was set to 0. Hence the modification to config.txt.


		[Bradley Botanel] 2020-03-24 feat(bus.cc and config.txt): prints information to terminal when a bus skips a stop In terms of our simulation it is not necessary for a bus to "literally" skip a
stop. It need only check that it unloaded or loaded passengers when at the stop.
This feature prints to the terminal the bus id and stop id when that bus skips a stop.
This feature appears in the Bus::Move() function.

To better test this feature the probability a stop generates a passenger for all stops
in route 2 was set to 0. Hence the modification to config.txt.


		[Bradley Botanel] 2020-03-24 Merge branch 'Iter1/07-PL3-pause-resume' into devel This merge concludes the work on PL3 and brings the changes back to devel.


		[Bradley Botanel] 2020-03-24 (origin/Iter1/07-PL3-pause-resume, Iter1/07-PL3-pause-resume) feat(config.txt, web_code/web, and web_graphics/sketch.js): #5 Added Pause functionality Pause functionality was added to the visualization simulator backend and to the sketch.js frontend.
This completes the second half of lab 11 and Priority Level 3 for Iteration 1.


		[Bradley Botanel] 2020-03-24 Merge branch 'Iter1/06-PL2-implement-bus-factory' into devel Google style compliance is complete on 06-PL2


		[Bradley Botanel] 2020-03-24 (origin/Iter1/06-PL2-implement-bus-factory, Iter1/06-PL2-implement-bus-factory) style(abstract_bus_factory.h, bus.h, large_bus_factory.h and .cc, large_bus.h and .cc, random_bus_factory.h and .cc, regular_bus_factory.h and .cc, regular_bus.h and .cc, small_bus_factory.h and .cc, small_bus.h and .cc) : #4 Google style compliance on priority level 2.


		[Bradley Botanel] 2020-03-24 Merge branch 'Iter1/06-PL2-implement-bus-factory' into devel PL2 is finished. Merging branch back into devel.


		[Bradley Botanel] 2020-03-24 feat(abstract_bus_factory.h, random_bus_factory.h and .cc, small_bus_factory.h and .cc, regular_bus_factory.h and .cc, large_bus_factory.h and .cc, small_bus.h and .cc, regular_bus.h and .cc, large_bus.h and .cc, bus.h, visualization_simulator.cc): #4 This commit certifies the completion of Priority Level 2 and the first half of
lab 11. Three new bus types were made (small, regular, large). All are derived
from the base Bus class and can be made by its own factory. Every factory is
derived from the abstract bus factory class. Also created was a random bus
factory so that visualization simulator will call a factory instead of the Bus
constructor.


		[Bradley Botanel] 2020-03-23 Resolved merge conflict by incorporating both suggestions. From @281 on Piazza 

		[Bradley Botanel] 2020-03-23 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code Lab11 instructed I do this.


		[Bradley Botanel] 2020-03-23 Merge branch 'Iter1/05-PL1-add-new-route' into devel This merge adds a new route to config.txt and is the final merge to complete
PL1 tasks.


		[Bradley Botanel] 2020-03-23 (origin/Iter1/05-PL1-add-new-route, Iter1/05-PL1-add-new-route) feat(config.txt): #3 Added a Campus Connector Express route This route is a subset of the Compus Connector route. It has the same 4 stops
in both eastbound and westbound directions. (Of course in reverse order).

This branch and commit fulfills the final requirement of PL1.







		[Bradley Botanel] 2020-03-16 Merge branch 'Iter1/04-PL1-web-code-main-indentation' into devel Fourth task in PL1 is complete: Fix the indentation of web_code/web/main.cpp


		[Bradley Botanel] 2020-03-16 (origin/Iter1/04-PL1-web-code-main-indentation, Iter1/04-PL1-web-code-main-indentation) style(web_code/web/main.cpp): #3 fix the indentation However, there is a difference in indentation styles used in this project.
The files within src are indented with two spaces whereas the files within
web_code/web are tab indented.

With guidance from Piazza post @307, no changes were main to web_code/web/main.cpp


		[Bradley Botanel] 2020-03-16 Merge branch 'Iter1/03-PL1-refactor-naming-Route-NextStop' into devel Third task in PL1 is complete: name change of Route::NextStop to
Route::ToNextStop


		[Bradley Botanel] 2020-03-16 (origin/Iter1/03-PL1-refactor-naming-Route-NextStop, Iter1/03-PL1-refactor-naming-Route-NextStop) refactor(bus.cc, route.cc, route.h): #3 Name change for a route method The name of Route::NextStop() was changed to Route::ToNextStop().
And because busses use routes, the calls in those methods had to change as well.


		[Bradley Botanel] 2020-03-16 Merge branch 'Iter1/02-PL1-LoadPassenger-definition-change' into devel Second task in PL1 is complete: Change PassengerLoader::LoadPassenger definition


		[Bradley Botanel] 2020-03-16 (origin/Iter1/02-PL1-LoadPassenger-definition-change, Iter1/02-PL1-LoadPassenger-definition-change) refactor(PassengerLoader .h and .cc): #3 Refactored LoadPassenger to return a boolean.
This required a change to Bus::LoadPassenger as it uses PassengerLoader::LoadPassenger.

This change improves the readability of both functions instead of relying on an int for a flag.


		[Bradley Botanel] 2020-03-16 Merge branch 'Iter1/01-PL1-bus-class-indentation' into devel First task in PL1 is complete


		[Bradley Botanel] 2020-03-16 (origin/Iter1/01-PL1-bus-class-indentation, Iter1/01-PL1-bus-class-indentation) style(bus.h and bus.cc): #3 Corrects the indentation of bus.h and bus.cc 

		[Bradley Botanel] 2020-03-06 (tag: Iter1D2) Deliverable 2 of Iteration 1 is complete: Unittests have been written for all public methods of passenger class, constructors, and boolean functions of stop, route, and bus classes. Test: Google Unittesting is complete for
passenger_UT.cc
stop_UT.cc
route_UT.cc
bus_UT.cc

However, an explanation is needed for Bus::Move(). There is an arithmetic
error in this method that causes it to not apply the correct distance between
certain stops. I believe the logic of this method is that it should return
true when the bus does move from or to a stop, return false when at the first
stop of the route, and return false when both routes are complete. This was
my expectation for the Bus::Move() unit testing. Yet, Bus::Move() only
returns true when distance_remaining_ is greater than 1 at the conclusion
of the call to Route::GetNextStopDistance(). So, it returns false far too
often which is why the unit test for false passes and the unit test for true
fails.



		[Bradley Botanel] 2020-03-05 test(Iter1 deliverable 2: First days work complete) passenger_UT.cc DONE stop_UT.cc DONE route_UT.cc IN PROGRESS bus_UT.cc TODO 


		[Bradley Botanel] 2020-03-05 test<unit tests>: initial commit establishing unit test files passenger_UT.cc bus_UT.cc stop_UT.cc route_UT.cc 









		[Bradley Botanel] 2020-02-28 Merge branch 'fix/02-google-style-pass' into devel Final cpplint error has been corrected.


		[Bradley Botanel] 2020-02-28 (origin/fix/02-google-style-pass, fix/02-google-style-pass) fix/02-google-style #2 Corrected the final cpplint error.


		[Bradley Botanel] 2020-02-27 Merge branch 'fix/02-google-style-pass' into devel Completed google style pass of .cc and .h files.


		[Bradley Botanel] 2020-02-27 fix(.cc and .h): fix #2 google-style-pass Changed .cc and .h files to be google style compliant.


		[Bradley Botanel] 2020-02-27 Merge branch 'fix/02-google-style-pass' into devel .cc and .h files are now google code compliant via cpplint


		[Bradley Botanel] 2020-02-27 style(.cc and .h files): cpplint compliance Changed the code style to be cpplint compliant.


		[Bradley Botanel] 2020-02-27 Merge branch 'fix/01-compilation-errors' into devel The compilation errors have been corrected.


		[Bradley Botanel] 2020-02-27 (origin/fix/01-compilation-errors, fix/01-compilation-errors) Testing the gitmessage 

		[Bradley Botanel] 2020-02-27 fix(files): fix #1 fix compilation errors - Several files had necessary methods commented out. They were:
- random_passenger_generator.cc; GeneratePassengers()
- bus.cc; LoadPassenger()
- passenger.cc; Update()
- stop.cc; LoadPassengers()

This has been corrected. The program compiles.


		[Bradley Botanel] 2020-02-27 #7 

		[Bradley Botanel] 2020-02-27 lab10: #4 



		[Bradley Botanel] 2020-02-27 Lab09 Final deliverables 

		[Bradley Botanel] 2020-02-26 Merge branch 'support-code' 

		[Bradley Botanel] 2020-02-26 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 







































+  _1_ / _1_ : Pass: Check git commit history
Sufficient commits (found=136,required=15)

