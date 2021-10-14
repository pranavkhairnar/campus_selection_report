#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include<bits/stdc++.h>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;
using std::istringstream;
using namespace std;
 
vector<string> comp;
vector<int> stud;
vector<float> salary;


string readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

int main()
{
    string filename("p1718.csv");
    string file_contents;
    std::map<int, std::vector<string>> csv_contents;
    char delimiter = ',';

    file_contents = readFileIntoString(filename);
   // cout<<file_contents<<"\n";

    istringstream sstream(file_contents);
    std::vector<string> items;
    string record;

    int counter = 0;
    while (std::getline(sstream, record)) {
        istringstream line(record);
        string c;
        int n;
        float sal;
        int count=1;
        while (std::getline(line, record, delimiter)) {
            items.push_back(record);
           // cout<<record<<" ";
           if(count==1)
           {
               c=record;
               comp.push_back(record);

               count++;

           }
           else if(count==2)
           {
                n=stoi(record);
                stud.push_back(n);
                count++;
           }
           else
           {
               sal=stof(record);
               salary.push_back(sal);
               
           }

        }
   //     cout<<"\n";

        csv_contents[counter] = items;
        items.clear();
        counter += 1;
    }

    for(int i=0;i<comp.size();i++)
    {
        cout<<comp[i]<<" "<<stud[i]<<" "<<salary[i]<<"\n";
        
    }
    

    exit(EXIT_SUCCESS);
}