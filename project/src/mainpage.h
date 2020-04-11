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

 * \subsection gen_over General Overview:
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
 * \section obs_patt Observer Pattern Discussion
 *
 *
 * \subsection over_view 
 *
 *
 *
 * \
 ******************************************************************************/

#endif  // SRC_MAINPAGE_H_
