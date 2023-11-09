# fall-cs225-final-project

## Code

All of the code in this project will be stored in the Code directory. Inside the Code directory, we have the src directory containing the source code for our Graph implementation and related algorithms. There is also a test directory that contains the test cases we wrote for this particular project. The entry directory contains the main method which will be used to run the project for general use.

## Datasets

Any airport and route data will be stored inside the Datasets folder for use in the program.


## Documents

Documents, such as our development log, team contract, and project proposal can all be found in the Documents directory.

## Results and Deliverables

Final results and deliverables such as:
- The final presentation
- The written report (report.md and the PNGs)

are in the Deliverables directory

## Running the Code

First cd into the directory of your code and then run "mkdir build."  Then cd into build and run "cmake .." which should populate the build folder.  (**IMPORTANT**) Make sure to reinput/correct the paths (that are used in the test cases and main method) of the airport.csv and routes.csv (found in datasets) before compiling.  (**UPDATE**) The paths should be fixed such that you can simply run the code.

The code uses the OpenFlights data source of airports and corresponding routes, so it is only necessary to input to into the command line as follows:

For the shortest path between airports: ./main "ShortestPath" "[airport_start]" "[airport_dest]"

For the comparison of importance (using betweeness centrality) of two airports: ./main "BC" "[airport1]" "[airport2]"

For finding out what the top N most important airports are: ./main "TopAirports" "[number_of_airports (N)]" "[sample_size]" -NOTE: This function is EXTREMELY time consuming, the above input uses the same algorithm with much greater efficiency.

The names must be entered as found in the dataset, so you can either use airports you find in the file (it is provided in the datasets folder) or the sample airports printed out when you input ./main with no arguments.

## Running the Tests

In order to run the test cases you will have to correct the paths to match your local paths for the given datasets.  Every dataset used is provided in the dataset folder, so once the paths are corrected, the tests will work as they work for us.  Assuming you have created a build folder and ran cmake like above, you just need to run ./test to use the test cases.   



