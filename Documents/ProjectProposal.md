## Leading Question 
    Given a set of airport locations and routes between them, can we consistently find the closest path between two airports?  We will use the open flights data source and create a weighted graph of airports and the routes between them. We will then use Dijkstra’s Algorithm to find this shortest path, a BFS estimate of this distance will be compared against it.  Then the betweeness centrality algorithm will be used to determine the most "in-between" airport in the graph.
## Dataset Acquisition
    
   
## Data Format
    The source of our dataset is openflights.org and it is a csv file that contains the information of around 10,000 flights and the airports corresponding to them.  We will attempt to use all of the data available in the file so as to avoid having unconnected edges.  If this happens to be too much data we will cut the data in half and deal with the unconnected edges within our code.
    
    We also plan to use the open flight flights route data which contains routes between 3321 airports.  This data will be compared to the vertices we get from the first file in order to determine whether two vertices have an edge.

## Data Correction
    We will parse the csv file, putting the data in their respective vectors/lists using iteration.  We plan to check afterwards for any NULL/empty values, and then remove those values and any other data associated with them.
## Data Storage
    We plan on storing the information in a graph.  In this graph we plan to use an adjacency list to store all the data (including airport names and the distances between them).  We will compute the distance between two airports using the latitudinal and longitudinal values, and these will represent the edge weights.  We will examin the route data to determine if an edge exists between two vertices.  The space required will be O(V + E).

## Algorithm 
    We plan to use Dijkstra’s Algorithm in order to calculate the shortest path between two nodes in a weighted graph.  The inputs will be two airports, and our code will then output a console visualization showing something like "airport1 -> distance -> airport2".  The efficiency of this algorithm is O(E + V log(V)).
    
    We plan to use a BFS search for the graph to calculate the distance between two airports as well, and we will compare this value to the shortest path returned by Dijkstra's algorithm.  The runtime of this algorithm will be O(V + E).
    
    Finally we will implement the betweeness centrality algorithm not taught in class in order to find the most "in-between" airport (or the airport with the most paths leading to it, based on shortest paths).  The runtime of this algorithm in an weighted graph is O(V^3).  We understand this is a slow runtime, so we will limit the amount of vertices when running this algorithm if necessary.
## Timeline
    We at least will have the csv parser completed by the midpoint check-in.  We plan to complete the graph class by the end of Thanksgiving break. Then we will try to have Dijkstra's algorithm and the BFS completed the week after.  By completed, we mean to have a working implementation that is passing tests.  After this point, if we have met the schedule prescribed above, we will try to implement betweeness centrality to identify the most "between" airports.  
    