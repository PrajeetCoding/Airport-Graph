// TEST CASES
#define _USE_MATH_DEFINES
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <iostream>
#include "CSVParser.h"
#include "Utility.h"
#include "Graph.h"
#include "Traversals.h"

using namespace CSVParser;
using namespace std;
/*
    This is a DUMMY TEST to make sure "make test" runs correctly
*/
TEST_CASE("CATCH2 WORKS", "[weight=10]")
{
    REQUIRE(true == true);
}

//Parsing Tests
TEST_CASE("Parse Simple", "[weight=10]")
{
    vector<vector<string>> actual;
    actual = parse_data("../tests/ParseSimple.csv");
    vector<vector<string>> expected = {{"507","London Heathrow Airport","London","United Kingdom","LHR","EGLL","51.4706","-0.461941","83","0","E","Europe/London","airport","OurAirports"}};
    

    REQUIRE(expected.size() == actual.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        for (size_t j = 0; j < expected[i].size(); ++j) {
            REQUIRE(actual[i][j] == expected[i][j]);
        }
    }
    
    
}

TEST_CASE("Parse Hard", "[weight=10]")
{
    vector<vector<string>> actual;
    actual = parse_data("../tests/ParseMedium.csv");
    vector<vector<string>> expected = {
        {"22","Winnipeg / St. Andrews Airport","Winnipeg","Canada","NULL","CYAV","50.0564002991","-97.03250122070001","760","-6","A","America/Winnipeg","airport","OurAirports"},
    {"23","Halifax / CFB Shearwater Heliport","Halifax","Canada","NULL","CYAW","44.639702","-63.499401","144","-4","A","America/Halifax","airport","OurAirports"},
    {"24","St. Anthony Airport","St. Anthony","Canada","YAY","CYAY","51.3918991089","-56.083099365200006","108","-3.5","A","America/St_Johns","airport","OurAirports"},
    {"25","Tofino / Long Beach Airport","Tofino","Canada","YAZ","CYAZ","49.079833","-125.775583","80","-8","A","America/Vancouver","airport","OurAirports"},
    {"26","Kugaaruk Airport","Pelly Bay","Canada","YBB","CYBB","68.534401","-89.808098","56","-7","A","America/Edmonton","airport","OurAirports"},
    {"27","Baie Comeau Airport","Baie Comeau","Canada","YBC","CYBC","49.13249969482422","-68.20439910888672","71","-5","A","America/Toronto","airport","OurAirports"},
    {"28","CFB Bagotville","Bagotville","Canada","YBG","CYBG","48.33060073852539","-70.99639892578125","522","-5","A","America/Toronto","airport","OurAirports"},
    {"29","Baker Lake Airport","Baker Lake","Canada","YBK","CYBK","64.29889678960001","-96.077796936","59","-6","A","America/Winnipeg","airport","OurAirports"},
    {"30","Campbell River Airport","Campbell River","Canada","YBL","CYBL","49.950801849365234","-125.27100372314453","346","-8","A","America/Vancouver","airport","OurAirports"},
    {"31","Brandon Municipal Airport","Brandon","Canada","YBR","CYBR","49.91","-99.951897","1343","-6","A","America/Winnipeg","airport","OurAirports"},
    {"32","Cambridge Bay Airport","Cambridge Bay","Canada","YCB","CYCB","69.1081008911","-105.138000488","90","-7","A","America/Edmonton","airport","OurAirports"},
    {"33","Nanaimo Airport","Nanaimo","Canada","YCD","CYCD","49.054970224899996","-123.869862556","92","-8","A","America/Vancouver","airport","OurAirports"},
    {"34","Castlegar/West Kootenay Regional Airport","Castlegar","Canada","YCG","CYCG","49.2963981628","-117.632003784","1624","-8","A","America/Vancouver","airport","OurAirports"},
    {"35","Miramichi Airport","Chatham","Canada","YCH","CYCH","47.007801","-65.449203","108","-4","A","America/Halifax","airport","OurAirports"},
    {"36","Charlo Airport","Charlo","Canada","YCL","CYCL","47.990799","-66.330299","132","-4","A","America/Halifax","airport","OurAirports"},
    {"37","Kugluktuk Airport","Coppermine","Canada","YCO","CYCO","67.816704","-115.143997","74","-7","A","America/Edmonton","airport","OurAirports"},
    {"38","Coronation Airport","Coronation","Canada","YCT","CYCT","52.0750007629","-111.444999695","2595","-7","A","America/Edmonton","airport","OurAirports"},
    {"39","Chilliwack Airport","Chilliwack","Canada","YCW","CYCW","49.1528015137","-121.939002991","32","-8","A","America/Vancouver","airport","OurAirports"},
    {"40","Clyde River Airport","Clyde River","Canada","YCY","CYCY","70.4860992432","-68.5167007446","87","-5","A","America/Toronto","airport","OurAirports"},
    {"41","Coral Harbour Airport","Coral Harbour","Canada","YZS","CYZS","64.1932983398","-83.3593978882","210","-5","A","America/Coral_Harbour","airport","OurAirports"},
    {"42","Dawson City Airport","Dawson","Canada","YDA","CYDA","64.04309844970703","-139.1280059814453","1215","-8","A","America/Vancouver","airport","OurAirports"},
    {"43","Burwash Airport","Burwash","Canada","YDB","CYDB","61.37110137939453","-139.04100036621094","2647","-8","A","America/Vancouver","airport","OurAirports"},
    {"44","Princeton Airport","Princeton","Canada","NULL","CYDC","49.4681015015","-120.511001587","2298","-8","A","America/Vancouver","airport","OurAirports"},
    {"45","Deer Lake Airport","Deer Lake","Canada","YDF","CYDF","49.21080017089844","-57.39139938354492","72","-3.5","A","America/St_Johns","airport","OurAirports"},
    {"46","Dease Lake Airport","Dease Lake","Canada","YDL","CYDL","58.4221992493","-130.031997681","2600","-8","A","America/Vancouver","airport","OurAirports"},
    {"47","Dauphin Barker Airport","Dauphin","Canada","YDN","CYDN","51.100799560546875","-100.052001953125","999","-6","A","America/Winnipeg","airport","OurAirports"},
    {"48","Dawson Creek Airport","Dawson Creek","Canada","YDQ","CYDQ","55.7422981262207","-120.18299865722656","2148","-7","A","America/Dawson_Creek","airport","OurAirports"},
    {"49","Edmonton International Airport","Edmonton","Canada","YEG","CYEG","53.309700012200004","-113.580001831","2373","-7","A","America/Edmonton","airport","OurAirports"},
    {"50","Arviat Airport","Eskimo Point","Canada","YEK","CYEK","61.0942001343","-94.07080078119999","32","-6","A","America/Winnipeg","airport","OurAirports"},
    {"51","Estevan Airport","Estevan","Canada","YEN","CYEN","49.2103004456","-102.966003418","1905","-6","N","America/Regina","airport","OurAirports"},
    {"52","Edson Airport","Edson","Canada","YET","CYET","53.578899383499994","-116.464996338","3043","-7","A","America/Edmonton","airport","OurAirports"},
    {"53","Eureka Airport","Eureka","Canada","YEU","CYEU","79.9946975708","-85.814201355","256","-6","A","America/Winnipeg","airport","OurAirports"},
    {"54","Inuvik Mike Zubko Airport","Inuvik","Canada","YEV","CYEV","68.30419921880001","-133.483001709","224","-7","A","America/Edmonton","airport","OurAirports"},
    {"55","Iqaluit Airport","Iqaluit","Canada","YFB","CYFB","63.756402","-68.555801","110","-5","A","America/Toronto","airport","OurAirports"}};
    
    REQUIRE(expected.size() == actual.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        REQUIRE(expected[i].size() == actual[i].size());
        for (size_t j = 0; j < expected[i].size(); ++j) {
            REQUIRE(actual[i][j] == expected[i][j]);
        }
    }
    
    
}

//Distance Test
TEST_CASE("Distance", "[weight=10]") {
    std::pair<double, double> point1{0.592539 * (180/M_PI), 2.066470 * (180/M_PI)};
    std::pair<double, double> point2{0.709186 * (180/M_PI), 1.287762 * (180/M_PI)};
    REQUIRE(std::round(Utility::distance(point1, point2)) == std::round(.623585 * 6366.71));
}

//Graph Tests
TEST_CASE("Graph Simple", "[weight=10]") {
    Graph g = Graph("../tests/GraphSimpleAirports.csv", "../tests/GraphSimpleRoutes.csv");
    REQUIRE(g.getNumVertices() == 7);
    REQUIRE(g.getVertices().size() == g.getNumVertices());
    REQUIRE(g.getNumEdges() == 7);
}
TEST_CASE("Graph Full (HARD)", "[weight=20]") {
    Graph g = Graph("../tests/airports.csv", "../tests/routes.csv");
    REQUIRE(g.getNumVertices() == 7698);
    REQUIRE(g.getNumVertices() == g.getNumVertices());
    REQUIRE(g.getNumEdges() == 66623);
    int total_edges = 0;
    for (Vertex v : g.getVertices()) {
        total_edges += (int) g.getAdjacent(v).size();
    }
    REQUIRE(total_edges == (int) g.getNumEdges());
}

//Dijkstra's/BFS Test cases 
TEST_CASE("Dijkstra_vs_BFS Simple", "[weight=10]") {
    Traversals t = Traversals("../tests/GraphSimpleAirports.csv", "../tests/GraphSimpleRoutes.csv");
    Graph g = Graph("../tests/GraphSimpleAirports.csv", "../tests/GraphSimpleRoutes.csv");


    std::vector<Vertex> bfs = t.BFS("GKA", "POM");
    std::vector<Vertex> dijkstras = t.shortestPath("GKA", "POM");

    double total_distance_bfs = t.printPath(bfs);

    double total_distance_dijk = t.printPath(dijkstras);

    
    REQUIRE(total_distance_dijk <= total_distance_bfs);

}

TEST_CASE("Djikstra Explicit Path", "[weight=10]") {
    Traversals t = Traversals("../tests/GraphSimpleAirports.csv", "../tests/GraphSimpleRoutes.csv");
    std::vector<Vertex> dijkstras = t.shortestPath("GKA", "POM");
    std::vector<Vertex> ans = {"GKA", "MAG", "POM"};
    for (unsigned i = 0; i < dijkstras.size(); i++) {
        REQUIRE(ans[i] == dijkstras[i]);
    }
    REQUIRE(true);
}

TEST_CASE("BFS Explicit Path", "[weight=10]") {
    Traversals t = Traversals("../tests/GraphSimpleAirports.csv", "../tests/GraphSimpleRoutes.csv");
    std::vector<Vertex> bfs = t.BFS("GKA", "POM");
    std::vector<Vertex> ans = {"GKA", "MAG", "POM"};
    for (unsigned i = 0; i < bfs.size(); i++) {
        REQUIRE(ans[i] == bfs[i]);
    }
    REQUIRE(true);
}


TEST_CASE("Djikstra No Path", "[weight=10]") {
    Traversals t = Traversals("../tests/airports.csv", "../tests/routes.csv");
    std::vector<Vertex> dijkstras = t.shortestPath("WBG", "POM");
    REQUIRE(dijkstras.empty());
}

TEST_CASE("BFS No Path", "[weight=10]") {
    Traversals t = Traversals("../tests/airports.csv", "../tests/routes.csv");
    std::vector<Vertex> bfs = t.BFS("WBG", "POM");
    REQUIRE(bfs.empty());
}

TEST_CASE("Dijkstra_vs_BFS Hard", "[weight=10]") {
    Traversals t = Traversals("../tests/airports.csv", "../tests/routes.csv");

    Graph g = Graph("../tests/airports.csv", "../tests/routes.csv");

    vector<Vertex> vertices = g.getVertices();
    for (int i = 0; i < 30; i++) {
        Vertex start = vertices[rand() % (int) vertices.size()];
        Vertex end = vertices[rand() % (int) vertices.size()];
        std::vector<Vertex> bfs = t.BFS(start, end);
        std::vector<Vertex> dijkstras = t.shortestPath(start, end);
        double total_distance_bfs = t.printPath(bfs);

        double total_distance_dijk = t.printPath(dijkstras);

    
        REQUIRE(total_distance_dijk <= total_distance_bfs);
    }
    REQUIRE(true);

}


//Betweeness Centrality Test Cases 
TEST_CASE("Betweeness Simple", "[weight=10]") {
    Traversals t = Traversals("../tests/GraphSimpleAirports.csv", "../tests/BetweenSimpleRoutes.csv");
    //Goraka should have the highest centrality it is connected to everything and Wewack should have one of the lowest it is connected to nothing
    int centrality_goraka = t.centralityApproximation("GKA", 10);
    int centrality_wewack = t.centralityApproximation("WWK", 10);

    cout << "GORAKA: " << endl;
    cout << centrality_goraka << endl;
    cout << endl;

    cout << "WEWACK: " << endl;
    cout << centrality_wewack << endl;
    cout << endl;
    REQUIRE(centrality_goraka > centrality_wewack);
    // Thus, everytime we run this test case, GKA should always be the answer since centrality(GKA) >= 1 and centrality(WWK) == 0
    
    REQUIRE(t.moreImportant("GKA", "WWK") == "GKA");
}
TEST_CASE("Betweeness Hard", "[weight=10]") {
    Traversals t = Traversals("../tests/airports.csv", "../tests/Datasets/routes.csv");
    
    // licenciado is more connected with the rest of the graph, so in theory, it should be the more important node, but if no nodes are connected in sample expect both to be 0

    int centrality_xiang = t.centralityApproximation("XIY", 10);
    int centrality_licenciado = t.centralityApproximation("MEX", 10);

    cout << "XIANG: " << endl;
    cout << centrality_xiang << endl;
    cout << endl;

    cout << "LICENCIADO: " << endl;
    cout << centrality_licenciado << endl;
    cout << endl;
    REQUIRE(centrality_licenciado >= centrality_xiang);
    
    REQUIRE(t.moreImportant("XIY", "MEX") == "MEX");
}