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

string readFileIntoString(const string& path)
 {
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
    set<string> s;
    vector<string> v; //storing  csv file names;
    v.push_back("p1718.csv");
    v.push_back("p1819.csv");
    v.push_back("p1920.csv");
    v.push_back("p2021.csv");
    
       string filename(v[0]);
        string file_contents;
        std::map<int, std::vector<string>> csv_contents;
        char delimiter = ',';
        file_contents = readFileIntoString(filename);
        istringstream sstream(file_contents);
        std::vector<string> items;
        string record;
        int counter = 0;
        while (std::getline(sstream, record)) {
            istringstream line(record);
            int count=1;
            while (std::getline(line, record, delimiter)) 
            {
                items.push_back(record);
                if(count==1)
                {
                      transform(record.begin(), record.end(), record.begin(), ::toupper);
                    s.insert(record);
                    count++;
                }
            }
            csv_contents[counter] = items;
            items.clear();
            counter += 1;
        }
        cout<<"end-----------------------------------\n";
        for(string st : s)
        {
            cout<<st<<"\n";
        }
        //-------------------------------------------------------------------------------
        string filename1(v[1]);
       file_contents="";
        csv_contents.clear();
        file_contents = readFileIntoString(filename1);
        istringstream sstream1(file_contents);
        items.clear();
         counter = 0;
        while (std::getline(sstream1, record)) {
            istringstream line1(record);
            int count=1;
            while (std::getline(line1, record, delimiter)) 
            {
                items.push_back(record);
                if(count==1)
                {
                    transform(record.begin(), record.end(), record.begin(), ::toupper);
                    s.insert(record);
                    count++;
                }
            }
            csv_contents[counter] = items;
            items.clear();
            counter += 1;
        }
        cout<<"end-------------------------------------------------------\n";
        for(string st : s)
        {
            cout<<st<<"\n";
        }
        //--------------------------------------------------------------------------
        string filename2(v[2]);
       file_contents="";
        csv_contents.clear();
        file_contents = readFileIntoString(filename2);
        istringstream sstream2(file_contents);
        items.clear();
         counter = 0;
        while (std::getline(sstream2, record)) {
            istringstream line2(record);
            int count=1;
            while (std::getline(line2, record, delimiter)) 
            {
                items.push_back(record);
                if(count==1)
                {
                    transform(record.begin(), record.end(), record.begin(), ::toupper);
                    s.insert(record);
                    count++;
                }
            }
            csv_contents[counter] = items;
            items.clear();
            counter += 1;
        }
        cout<<"end---------------------------------------------\n";
        for(string st : s)
        {
            cout<<st<<"\n";
        }
        //---------------------------------------------------------------------------
    string filename3(v[3]);
       file_contents="";
        csv_contents.clear();
        file_contents = readFileIntoString(filename3);
        istringstream sstream3(file_contents);
        items.clear();
         counter = 0;
        while (std::getline(sstream3, record)) {
            istringstream line3(record);
            int count=1;
            while (std::getline(line3, record, delimiter)) 
            {
                items.push_back(record);
                if(count==1)
                {
                    transform(record.begin(), record.end(), record.begin(), ::toupper);
                    s.insert(record);
                    count++;
                }
            }
            csv_contents[counter] = items;
            items.clear();
            counter += 1;
        }
        cout<<"end---------------------------------------------\n";
        for(string st : s)
        {
            cout<<st<<"\n";
        }



}


 



