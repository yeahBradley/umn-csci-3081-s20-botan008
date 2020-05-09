### Iteration 3 - Style-And-Git Partial Assessment (Graded By: Pallavi Mitra)

Run on May 09, 12:43:38 PM.

<hr>

This Partial Assessment indicates a TA has begun grading your Iteration 3 Design. However, design will be graded using a Canvas rubric and grades will only be posted on Canvas once every student's program design has been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout iteration 3 final submission.




#### Style Compliance Tests

+ Pass: Change into directory "project/src".

+ Pass: Linting main src files...



+ Pass: Change into directory "../web_code/web".

+ Pass: Linting web code...




#### Git Tests

+  _2_ / _2_ : Pass: Counting Iteration 3 branches...

Sufficient branches found (found=9, required=6):

Iter3/01-output-log-file

Iter3/02-bus-color-decorator

Iter3/03-bus-intensity-decorator

Iter3/04-template-observer-pattern

Iter3/05-fix-bus-observer

Iter3/06-stop-observer

Iter3/07-decorator-implementation-files

Iter3/08-google-style-cpplint

Iter3/09-doxygen-content

+  _2.0_ / _2_ : Pass: Run ghi for total number of issues in Github repo (Found: 10, Expected: 4) 

 [OPEN issue #22] :  Iter3/07-decorator-implementation-files [bug] [enhancement] @botan008

[CLOSED issue #24] :  Iter3/09-doxygen-content

[CLOSED issue #23] :  Iter3/08-google-style-cpplint [enhancement] @botan008

[CLOSED issue #21] :  Iter3/06-stop-observer [enhancement] @botan008

[CLOSED issue #20] :  Iter2/05-fix-bus-observer [bug] @botan008

[CLOSED issue #19] :  Iter3/04-template-observer-pattern [enhancement] 1 @botan008

[CLOSED issue #18] :  Iter3/03-bus-intensity-decorator [enhancement] @botan008

[CLOSED issue #17] :  Iter3/02-bus-color-decorator [enhancement] @botan008

[CLOSED issue #16] :  Iter3/01-output-log-file [enhancement] @botan008

[CLOSED issue #15] :  Iter2/08-doxygen-content [enhancement] 1 @botan008

 




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Bradley Botanel] 2020-05-02 (HEAD, tag: Iter3-master) Merge branch 'devel' This is the end. Iteration 3 is complete. Final merge to master.


		[Bradley Botanel] 2020-05-02 (tag: Iter3-devel, origin/devel) docs(added ReleaseNotes.pdf to docs folder): #24 Last minute addition of a ReleaseNotes.pdf.


		[Bradley Botanel] 2020-05-02 Merge branch 'Iter3/09-doxygen-content' into devel #24 

		[Bradley Botanel] 2020-05-02 (origin/Iter3/09-doxygen-content, Iter3/09-doxygen-content) docs(Iteration 3 modules: FileWriter, Decorator pattern, Template Observer pattern): #24 Doxygen style documentation has been included for all new Iteration 3 classes and methods.

Mainpage.h has been updated to include discussion on the decorator pattern and its implementation in the bus simulation.

The config section of Mainpage.h was also updated to support the new Observer functionality.


		[Bradley Botanel] 2020-05-02 Merge branch 'Iter3/08-google-style-cpplint' into devel #23 Google style pass is complete. Mergeing back to devel


		[Bradley Botanel] 2020-05-02 (origin/Iter3/08-google-style-cpplint, Iter3/08-google-style-cpplint) style(google style with cpplint): #23 Google style compliance has been implemented via cpplint. All files in project/src and web/web_code are compliant.


		[Bradley Botanel] 2020-05-02 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-botan008 

		[Bradley Botanel] 2020-05-02 Merge branch 'devel' This is my initial submission. More are sure to follow. This will also act
as a failsafe incase something catastrophic happens that prevents me from
making another submission.


		[Bradley Botanel] 2020-05-02 Merge branch 'Iter3/06-stop-observer' into devel #21 

		[Bradley Botanel] 2020-05-02 (origin/Iter3/06-stop-observer, Iter3/06-stop-observer) feat(Stop Observer): #21 Stop observer is complete along with the template pattern I pulled an audible in the middle of this branch. I had initially intended to write the stop observer before changing the observer pattern to templates. But after I got the Bus Observer to work after changing the code to specificially refer to the bus, I decided to get the template to work for the bus observer. Progress was quick and in almost no time the bus observer was functioning with the template base class. After that it was smooth sailing implementing the stop observer.

All major priority levels of Iteration 3 are complete.


		[Bradley Botanel] 2020-05-02 Merge branch 'Iter3/06-stop-observer' into devel #21 Saving my work up into devel


		[Bradley Botanel] 2020-05-02 feat(busobserver): #21 I have changed the names of methods so that they specify the bus observer. I am saving this work.


		[Bradley Botanel] 2020-05-01 Merge branch 'Iter3/05-fix-bus-observer' into devel #20 The bug has been fixed so the branch is being merged back into devel.


		[Bradley Botanel] 2020-05-01 (origin/Iter3/05-fix-bus-observer, Iter3/05-fix-bus-observer) fix(BusWebObserver): #20 Bus Observer Pattern is functional again I had made this issue/branch from the working devel branch solely to fix the broken Bus Observer design. Since adding the bus decorator the busdata was no longer being displayed. The solution was to add pass-through methods in the decorators for RegisterObserver and ClearObservers and to add the virtual keyword to the method declarations in IObservable.h.


		[Bradley Botanel] 2020-04-30 Merge branch 'Iter3/03-bus-intensity-decorator' into devel #18 Merging with devel certifies completion of Priority Level 5.


		[Bradley Botanel] 2020-04-30 (origin/Iter3/03-bus-intensity-decorator, Iter3/03-bus-intensity-decorator) feat(IBusDecorator, BusColorDecorator, IBus, Bus, and the new member of the family BusIntensityDecorator): #18 Implemented an alpha channel intensity decorator To appropriately implement this new decorator I had to refactor the existing code for BusColorDecorator::SetColor method so that neither decorator will step on each other's toes.

Previously, SetColor used a color object to change color values to either maroon or gold. But this included the alpha values. If left as is, these values would overwrite those set by BusIntensityDecorator.

Now, SetColor retrieves the bus_data_ object from the bus it's wrapping, change the RGB color values, then uses the new SetBusData method to send it back to the bus. BusIntensityDecorator::SetIntensity works on the same principle but for setting the alpha channel based on how many passengers are on the bus.

Lastly, there is an error that a new issue will be created to address. I'm not able to move the method definitions from the header files of BusColorDecorator and BusIntensityDecorator to a .cc file without Bus losing the ability to inherit from IBus.


		[Bradley Botanel] 2020-04-30 Merge branch 'Iter3/02-bus-color-decorator' into devel #17 As the implementation for Priority level 3 is finished, it is being merged
back into devel.


		[Bradley Botanel] 2020-04-30 (origin/Iter3/02-bus-color-decorator, Iter3/02-bus-color-decorator) feat(front-end, simulation, back-end): #17 Decorator pattern that changes the bus color depending on its route This corresponds to much of lab 17 and the entirety of Priority level 3 for Itertaion 3. It required modification of many files:
my_web_server_command.cc, my_web_server.cc, visualization_simulator.h/.cc, data_structs.h, bus.h/.cc.
And the creation of whole new classes:
i_bus.h, i_bus_decorator.h, and bus_color_decorator.h

Much of the changes were made to facilitate the communcation of the color struct between the front-end, the simulation, and the back-end.
The new classes incorporated the decorator pattern to perform the necessary color changes on busses.


		[Bradley Botanel] 2020-04-30 Merge branch 'Iter3/01-output-log-file' into devel #16 This verifies the completion of Lab16 and priority level 2.


		[Bradley Botanel] 2020-04-30 (origin/Iter3/01-output-log-file, Iter3/01-output-log-file) feat(bus, PassengerUnloader,  VisualizationSimulator, new class FileWriter): #16 Singleton file logger This encompases lab 16 and Priority level 2 from Iteration 3.
Using the singleton pattern a filewriter class was made. It writes to one of two files based on whether the data is from a bus or passenger object. The data it writes is from either Bus::Report or Passenger::Report. To incorporate it into the program, changes were made to visualizationSimulator::Update and PassengerUnloader::UnloadPassengers. Additionally, the bus now keeps track of the total number of passengers that have ridden the bus and ouputs this data in its Bus::Report method.


		[Bradley Botanel] 2020-04-29 Merge branch 'support-code' into devel 

		[Bradley Botanel] 2020-04-29 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 




















+  _1_ / _1_ : Pass: Check git commit history
Sufficient commits (found=61,required=10)

+ Pass: Opening Iter_03_Style-And-Git_Assessment.md using firefox

