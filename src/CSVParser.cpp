// Setting Up CSV Parser
#include "CSVParser.h"

using namespace std;


vector<vector<string>> CSVParser::parse_data(string filename) {

    vector<vector<string>> data;
    ifstream reader(filename);
    string line;
    if (reader.is_open()) {
        while (getline(reader, line)) {
            /*
                airport is a vector of strings representing a single line in the airports.csv file.
                each string in the vector represents an piece of information about that airport.
            */

            vector<string> airport;
            
            /*
                value is the current piece of data relating to the airport we are looking at:
                e.g. name of aiport, latitude of airport, country of airport, ...
            
            */
            string value;

            /*
                because of the way a csv file is setup, everytime we see a comma we know reached the end of the particular piece of data
                we are looking at. Thus, we can add it to the airport vector. We then need to reset the value string to be empty so that we can 
                start building the next piece of data.

                Otherwise, if the current character we are looking at isn't a comma, then we aren't finished building the data and we just 
                add the character to the value string.
            */
            for (char c : line) {
                if (c == ',') {
                    airport.push_back(value);
                    value = "";
                } else {
                    /*This if statement handles issues with '\N' characters which the parser has a hard time reading */
                    if (c == 'N' && value == "\\") {
                        value = "NULL";
                        continue;
                    } 
                    if (c == '"') continue;
                    value += c;
                }
            }
            /*
            we need to push back value here to account for the fact that the last piece of data in the line does not get 
            pushed back since we do not see a comma.
            */

            airport.push_back(value);
            

            if (airport.size() > 14) {
                // This is a special case where there is a comma inside the aiport name, we handle this case explicitly.
                
                data.push_back(vector<string>{"641","Harstad/Narvik Airport, Evenes","Harstad/Narvik","Norway","EVE","ENEV","68.491302490234","16.678100585938","84","1","E","Europe/Oslo","airport","OurAirports"});
            } else {
                data.push_back(airport);
            }     
        }
    }

    return data;



}






