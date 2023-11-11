#include <iostream>
#include <vector>
#include <exception>
#include "CSVParser.h"
#include "Graph.h"
#include "Traversals.h"
#include "Edge.h"
using namespace CSVParser;
using namespace std;

int Usage() {
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl;
    std::cout << "Usage: " << std::endl;
    std::cout << "For the shortest path between airports: ./main ShortestPath [airport_start] [airport_dest]" << std::endl;
    std::cout << "For the comparison of importance (using betweeness centrality) of two airports: ./main BC [airport1] [airport2]" << std::endl;
    std::cout << "For finding out what the top N most important airports are: ./main TopAirports [number_of_airports (N)] [sample_size]" << std::endl;
    std::cout << "IMPORTANT:" << std::endl;
    std::cout << "NOTE1: Make sure to encapsulate arguments with quotes such that (besides ./main) there are three separate string arguments entered." << std::endl;
    std::cout << "NOTE2: The betweeness centrality calculation, despite limiting the sample size, may still take some time to run (a few minutes at most)" << std::endl;
    std::cout << "NOTE3: Finding the top N airports is an EXTREMELY slow operation (could take 1-10 hours) because of how large the graph is, even with a small sample size" << std::endl;
    std::cout << std::endl;
    std::cout << "Sample airports: London Heathrow Airport, Chicago O'Hare International Airport, Gulkana Airport, Philadelphia International Airport, Four Corners Regional Airport, Hood Army Air Field" << std::endl;
    std::cout << "Goroka Airport, Madang Airport, Wewak International Airport, Thule Air Base, Brandon Municipal Airport, Miramichi Airport, Atikokan Municipal Airport, Schefferville Airport, Buttonville Municipal Airport" << std::endl;
    std::cout << std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    return -1;
}

int main(int argc, char **argv) {
    if (argc != 4){

        return Usage();
        

    } else {
        std::string first_arg = argv[1];
        if (first_arg == "ShortestPath") {

            Traversals t = Traversals("../entry/airports.csv", "../entry/routes.csv");
            Vertex start = t.convertNameToID(argv[2]);
            Vertex dest = t.convertNameToID(argv[3]);

            std::cout << "++++++++++++++++ BFS ++++++++++++++++++" << std::endl;
            t.printPath(t.BFS(start, dest));
            std::cout << "----------------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "+++++++ Dijkstra's Shortest Path +++++++" << std::endl;
            t.printPath(t.shortestPath(start, dest));
            std::cout << "----------------------------------------" << std::endl;
        } else if (first_arg == "BC") {
            Traversals t = Traversals("../entry/airports.csv", "../entry/routes.csv");
            Vertex one = t.convertNameToID(argv[2]);
            Vertex two  = t.convertNameToID(argv[3]);
            std::string result = t.moreImportant(one, two);
            if (result == "") {
                std::cout << "Invalid airport given, check spelling or use a sample airport" << std::endl;
                std::cout << std::endl;
                return Usage();
            }
            result = t.convertIDToName(result);
            std::cout << "----------------------------------------" << std::endl;
            std::cout << result << " is the more important airport" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        } else if (first_arg == "TopAirports") {

            Traversals t = Traversals("../entry/airports.csv", "../entry/routes.csv");
            
            string a_1 = argv[2];
            string a_2 = argv[3];
            for (char c : a_1) {
                if (!isdigit(c)) {
                    cout << endl;
                    cout << "ARGUMENTS WERE NOT NUMERIC OR CONTAINED FLOATING POINT/NEGATIVE VALUES" << endl;
                    cout << endl;
                    return -1;
                }
            }
            for (char c : a_2) {
                if (!isdigit(c)) {
                    cout << endl;
                    cout << "ARGUMENTS WERE NOT NUMERIC OR CONTAINED FLOATING POINT/NEGATIVE VALUES" << endl;
                    cout << endl;
                    return -1;
                }
            }

            int num_airports = stoi(argv[2]);
            int sample_size = stoi(argv[3]);

            cout << "SELECTED NUMBER OF AIRPORTS: " << num_airports << endl;
            cout << "SELECTED SAMPLE SIZE: " << sample_size << endl;
            cout << endl;

            vector<Vertex> airports = t.topAirports(num_airports, 1, sample_size);

            cout << "PRINTING TOP AIRPORTS..." << endl;
            for (Vertex v :airports) {
                cout << v << endl;
                cout << endl;
            }
            


        } else {
            return Usage();
        }
    }
}
