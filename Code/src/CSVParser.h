// Setting Up CSV Parser
#pragma once

#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

namespace CSVParser {

    /*
        a CSV parsing function that returns a vector that stores each line in the csv as a vector of strings, with each string
        being a value in that line
    */
    vector<vector<string>> parse_data(string filename);

}
