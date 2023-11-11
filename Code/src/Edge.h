#include <string>
#pragma once 
using namespace std;

// string storing airport ID

typedef string Vertex;
        
struct Edge {
    // source airport

    Vertex source;

    // ending/destination airport

    Vertex dest;

    // weight which is going to be set as the distance between two airports
    
    double weight;
};