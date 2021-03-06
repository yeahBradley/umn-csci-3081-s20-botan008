/**
 * "Copyright 2020 Bradley Botanel"
 *
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/** \mainpage Bus Transit Simulator
 *
 * \section intro_sec Introduction
 *
 * The Bus Transit Simulation is being developed for CSCI 3081w in Spring 2020.
 *
 * \section design_sec Program Design
 *
 * \subsection domain_structure Domain Element Structure

 * This program consists of several domains that all work together to produce the bus transit simulator. They are as follows:

 * There is a domain for the code-base of the Bus Transit Simulator. This domain contains the source files for our simulator. These files are in the /src/ folder.

 * There is a domain for the running of the simulation. This domain contains the main driver for the simulation (visualization simulator and other required classes. These files are in the /web_code/web/ folder.

 * Lastly, there is a domain for the client-side program and the web browser GUI. These files are in the /web_graphics/ folder.

 * \subsection factory_design Bus Factory Design: Abstract vs. Concrete

 * Extendability is a key reason to use a factory. It allows other classes or usage scenarios to call the factory when they need a bus. A factory also segments and separates the implementation of bus objects so that if or when changes to the creation of bus objects is necessary those changes can be made in the bus factory without affecting how the factory is used in the rest of the program.

 * The abstract bus factory design follows the design heuristics of “Open to extension, closed to change” and “Low coupling/High Cohesion” more rigorously than a concrete bus factory. Factories can inherit from an abstract base class allowing them to be more specific and unique thus adhering to “Open to extension, closed to change”. This property also allows for a greater adherence to “Low coupling/High Cohesion” by separating the factories into their own classes instead of having a single concrete factory make many similar types of objects.

 * There’s also a functional difference in how these factories are used. The concrete factory requires an input parameter to specify which type of object to create. While the type of object to create with the abstract factory is determined by the type of factory making it.

 * A concrete factory will require less work to design and implement by needing far fewer classes and files than an abstract factory, but will be harder to refactor. To refactor the concrete factory, I would have to make changes to the concrete factory class and add a new class for the new type of object.

 * An abstract factory, on the other hand, needs more classes and initially requires more time to design and implement. But to refactor the abstract factory, I would simply add two classes (one for the bus and the other for its factory) while leaving the abstract base class and other factories unchanged. Meaning I only need to concern myself with developing the new elements and not have to search through the other code to find something that needs to change to support the new elements.

 * In short, a concrete factory requires less files and classes but is more difficult to refactor while an abstract factory requires more files and classes but is easier to refactor.

 * For these reasons (and to have a challenge) I implemented the Bus Factory as an Abstract Factory. This proved quite beneficial when it came time to incorporate randomness in the creation of busses within the visualization simulator class. I was able to easily extend the abstract bus factory to a random bus factory that generates one of the three bus types randomly without concerning myself with the other factories. 

 * \section user_guide User Guide: How to configure and run the simulation

 * \subsection gen_over General Overview: **Updated**
 *
 * This user guide instructs a user on establishing an instance of the Bus Transit Simulator, explains the various configuration options available, and how to appropriately decommission the simulator.

 * Creating an instance of the simulator requires a Linux terminal and a web browser. You will create and start a server for the simulation in the terminal and then navigate the web browser to a front end view of the simulation.

 * \subsection set_up Set-up:
 *
 * Open Linux Terminal
 * Navigate to /src folder
 * Type “make” into terminal and hit enter
 * Type “cd ..” into terminal and hit enter
 * Type “./build/bin/vis_sim <Port Number>”
 * Port Number is your choice between 8000 and 8999
 *
 * Open Web Browser
 * Open a new tab
 * Enter “http://127.0.0.1:<Port Number>/web_graphics/project.html” into the URL and hit enter
 *
 * \subsection conf_opt Configure options:
 *
 * On the front end simulation web page are several options available to the user. There are three sliders on the top left under Sim Info and two buttons on the bottom left under Run.
 *
 * The sliders are as follows:
 * Number of time steps to run: Tells the server how long to run
 * Time steps between busses for route 0: This sets the time interval between creating busses for route 0.
 * Time steps between busses for route 1: This sets the time interval between creating busses for route 1.
 *
 * The two buttons are as follows:
 * Start: Activates the bus transit simulation.
 * Pause/Resume: Behaves like a toggle. If the simulation is running then it will pause the simulation. If the simulation is already paused then it resume the simulation.
 *
 * \subsection run_sim Run Simulation:
 *
 * After setting your desired options, click the start button to run the simulation. Once running, the routes and stops will appear on the map window. Hovering your mouse over a bus will give you information on the number of passengers it is carrying and its capacity. Hovering your mouse over a stop will tell you how many people are waiting at that stop. The simulation ends when it has run for the specified number of time steps set by the slider.
 *
 * To run the simulation again you must restart the simulation server and refresh the simulation web page. To do this go to the server terminal and type the escape character (ctrl+c) to end the simulation server. Then type “./build/bin/vis_sim <Port Number>” with your chosen port number and hit enter. Now go to the web page with the view of the simulation and hit refresh. You can now reconfigure the options and run again.
 *
 * \subsection decom_sim Decommission Simulation:
 *
 * Once you are done running simulations it is best to decommission the resources. To close the view of the simulation simply close the web page or web browser. To close the server go to the terminal and type the escape character (ctrl+c). With the server closed, type “cd src” and hit enter. Now type “make clean” to wipe away any trace of the build for that simulation. You can now exit the terminal. 
 *
 * \subsection iter3_update **Update**: New Features with Iteration 3
 * 
 * You can now select a bus and/or a stop and the relevant data for your selection will be displayed in a window to the right of the map. To select a bus click on its icon in the map. If you’re having difficulty you can pause the simulation and then click the bus. To select a stop simply use the new drop down menu located under the two buttons in the bottom left.
 * 
 * \section obs_patt Observer Pattern Discussion
 *
 * \subsection wha_it What is it?
 *
 * The Observer pattern is defined as, “a one-to-many dependency between objects so that when one object changes state, all of its dependents are notified and updated automatically.” (Freeman, 2014, p. 51) This type of dependency is valuable for establishing low coupling between different objects. How it works is that there is an observer object and a subject object. The observer object can communicate to the subject in only two ways; to be registered and to be unregisterd.
 *
 * While registered with the subject, the observer will be notified of any state changes that happen to the subject. These state changes are the only communication the subject sends to the observer and is what makes the observer dependent on the subject. There can be “many” observers to “one” subject, hence the term “one-to-many”. The subject maintains a list of registered observers, adding and removing observers as requested.
 *
 * \subsection ben_fit Benefits
 * 
 * The most significant benefit to the Observer pattern is called Loose Coupling. When objects are loosely coupled, it means that their implementations are coded to be separate and independent from each other. This allows a developer to more rigorously define how and what the two communicate and affords him/her much more freedom to expand both their implementations. On the contrary, if the subject was implemented to communicate with the observers directly then changes to one object will likely require changes to the other objects. Potentially leading to duplicate code and more code that requires changes when a new feature is being added.
 *
 * \subsection how_here How its being used in this program
 *
 * With the second iteration, the Observer pattern has been incorporated into the Bus Transit Simulator program. Presently, there is a single observer and it is being used to display the selected bus data in a new window on the right side-bar of the online GUI. The data consists of the bus’s ID number, GPS coordinates, the current number of passengers, and the maximum capacity of the bus. Other busses can be selected by clicking their moving markers on the map. It may be helpful to pause the simulation when attempting to click a bus. The subject for this observer is the bus class. The bus was expanded with this functionality through the added Iobserver abstract class. It will now regularly send bus data to the observer to be displayed in the online GUI.
 *
 * \subsection cit_ation Citation
 *
 * “Chapter 2 The Observer Pattern.” Head First Design Patterns: a Brain-Friendly Guide, by Eric Freeman and Elisabeth Robson, O'Reilly, Edition: 10th Anniversary Ed., 2014, pp. 37–80. 
 *
 * \section dec_patt Decorator Pattern Discussion
 * 
 * \subsection what_it What is it and how did it change the program
 * 
 * The Decorator Pattern allows for the extension of new behavior or functionality to a class without needing to modify that class. It does this primarily through new decorator classes that share an interface with the class they’re decorating. The inherited interface allows the two classes to be treated the same through the existing program. The decorator classes mostly consist of “pass-through” methods that call the same methods of the class they decorate. This ensures that the functionality of the class remains after being decorated. Most importantly, the decorator class can have new methods that support the addition of new behavior or functionality. 
 * 
 * The implementation of the Decorator pattern for the bus simulation program added new behavior to the bus class. The new behavior included changing the color of the bus based on whether it is on an outgoing route or an incoming route and changing the intensity of the color based on the number of passengers on the bus. Each behavior was given its own decorator with a new method that only performed the necessary operations for the behavior. 
 * 
 * An important consideration and potential con when implementing the decorator pattern is to ensure that decorators don’t conflict with each other. Designing the decorator’s to be disjoint so that the changes they make or behavior they add doesn’t get affected by the other decorators can be a challenge. For instance, in the current implementation both behaviors make changes to the color struct of the bus class. If I wanted to add a new decorator that also changes the color struct then I would have to ensure that it can decorate the other decorators without conflicts or that it will never be applied to an object that already has one of the other decorators.
 * 
 * Another consideration and potential con is that the more decorators that are made the less straightforward the overall design becomes. Having a small army of decorators on top of all the features the class already has can be a sizable barrier to understanding the program. Additionally, instantiating an object becomes more tedious when you also need to wrap it in any number of decorators. Lastly, the overhead associated with having the decorator pass through method calls to the wrapped object could be problematic for the runtime of the program.
 * 
 * The benefits of the Decorator pattern lie in its adherence to core object oriented programming design principles. These principles have been used to justify the existence of other design patterns used in this program. One such principle is called “low coupling, high cohesion”. While designers should be striving to achieve this principle, it’s not always possible. On one hand, the decorator class is highly coupled with the base class it decorates and on the other hand the base class it decorates is the only class its coupled with. So, in terms of the base class the decorator is highly coupled but then it exhibits low coupling with the rest of the program. Also, the coupling status of the decorator class is dependent on the coupling status of the class it decorates. If the base class is highly coupled with other parts of the program then the decorator class will as well. Decorator’s on their own should exhibit high cohesion by only containing the operations necessary to perform their new behavior without relying on many other classes or methods. With this definition in mind, the new decorator classes in the bus simulation are highly coupled with the bus class they decorate, but are lowly coupled with the rest of the program. Once decorated, the program can’t tell that the object its working with has changed. The behavior added by the decorators is highly cohesive by having all the operations necessary for the behavior made inside the decorator.
 * 
 * Another principle is called “open to extension, closed to change”. This principle specifies that classes should be easily extendable for new behavior or features while not allowing or requiring changes to their source code to support the extended behavior or features. The Decorator pattern fits this principle well. It doesn’t require changes to the base class it decorates and instead it adds or extends new behavior to the base class. To get the bus decorator class up and running in the simulation some changes had to be made to the bus class. First, the inheritance structure had to be changed so that both the bus and the bus decorator classes inherited the same interface. Secondly, two new methods had to be added to the bus class to support the necessary behavior of the decorator. One method, IsOutgoingRouteComplete(), returns true if the bus has completed its outgoing route. This is used to determine the color of the bus in the BusColorDecorator class. The other method, SetBusData, is a setter method for the bus_data_ private member variable. Both the decorator classes BusColorDecorator and BusIntensityDecorator use this method to save their respective changes to the bus_data_ private member variable. Beyond those additions to the bus class, the decorators provide the extension of the bus class we were looking for while leaving the bus class as closed to change as possible.
 * 
 * \subsection alt_des Design Decisions
 * 
 * While implementing the decorator pattern, there were several instances when I was faced with choosing between multiple design decisions. One of the design specifications for the decorator pattern was to change the color of a bus based on the route it is currently on; one color for the outgoing route and another color for the incoming route. I opted to place the logic for this decision inside the decorator because I wanted decisions that can alter the bus to be made by the bus. This also provided a host of simplifications for applying the decorator and actually changing the bus color. First, the color of the bus can change at any update tic of the server. To support this the bus decorator checks which route the bus is currently on for every update tic and sets the color accordingly. This means I only need one decorator to decide and set the color of the bus. 
 * 
 * An alternative location for the decision logic would be inside visualization simulator after a bus has been generated by the factory. This would simplify the decorator to only have to set the color. Now, we can have multiple decorators for multiple colors. With this, the decorator class becomes more extendable. However, we still must consider the update tics of the server and when the color needs to change. With the decision logic outside the decorator, will a new decorator be applied at every update tic? How will I guarantee that the outer layer has control of the color? Do I write more logic in visualization simulator that checks which decorator has been applied so that only when the color changes does a new decorator be applied? Questions like these and their complex solutions are what pushed me away from attempting this implementation.
 * 
 * 
 ******************************************************************************/

#endif  // SRC_MAINPAGE_H_
