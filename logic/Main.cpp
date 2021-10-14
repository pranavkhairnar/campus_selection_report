#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <bits/stdc++.h>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using namespace std;
 // this is class 
 
class Company
{
public:
    string name;
    double salary[4];
    int stud[4];
    double max_sal;
    Company()
    {
        name = "";
        for (int i = 0; i < 4; i++)
        {
            salary[i] = 0.0;
            stud[i] = 0;
        }
        max_sal=0;
    }
    void print()
    {
        cout<<name<<" ";
        for(int i=0;i<4;i++)
        {
            cout<<salary[i]<<"-"<<stud[i]<<" ";
            if(max_sal<salary[i])
            {
                max_sal=salary[i];
            }
        }

        cout<<"\n";
    }
};
bool comp(Company a,Company b )
{
    if(a.max_sal>b.max_sal)
    {
        return true;
    }
    return false;
}
string readFileIntoString(const string &path)
{
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}
int main()
{
    vector<string> companies;
    fstream newfile;

    newfile.open("temp.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;
        while (getline(newfile, tp))
        { //read data from file object and put it into string.
            companies.push_back(tp);
        }
    }
    cout << companies.size() << "\n";

    newfile.close(); //close the file object.

    Company obj[240];
    int i=0;
    for ( i = 0; i < 240; i++)
    {
        obj[i].name = companies[i];
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
        int tempo = 0;
        while (std::getline(sstream, record))
        {
            istringstream line(record);
            int count = 1;

            while (std::getline(line, record, delimiter))
            {
                items.push_back(record);
                if (count == 1)
                {
                    transform(record.begin(), record.end(), record.begin(), ::toupper);
                    if (record == companies[i])
                    {
                        tempo = 1;
                    }
                    count++;
                }
                else if (tempo == 1 && count == 2)
                {
                    int n=stoi(record);
                    obj[i].stud[0] = n;
                  count++;
                }
                else if (tempo == 1 && count == 3)
                {
                    obj[i].salary[0] = stof(record);
                    count++;
                }
            }
            if (tempo)
            {
                break;
            }
            csv_contents[counter] = items;
            items.clear();
            counter += 1;
        }
        if (!tempo)
        {
            obj[i].stud[0] = -1;
            obj[i].salary[0] = -1;
        }

        //-------------------------------------------------------------------------------
        string filename1(v[1]);
        file_contents = "";
        csv_contents.clear();
        file_contents = readFileIntoString(filename1);
        istringstream sstream1(file_contents);
        items.clear();
        record="";
        counter = 0;
        tempo = 0;
        while (std::getline(sstream1, record))
        {
            istringstream line1(record);
            int count = 1;
            while (std::getline(line1, record, delimiter))
            {
                items.push_back(record);
                if (count == 1)
                {
                    transform(record.begin(), record.end(), record.begin(), ::toupper);
                    if (record == companies[i])
                    {
                        tempo = 1;
                    }
                    count++;
                }
                else if (tempo == 1 && count == 2)
                {
                    int n=stoi(record);
                    obj[i].stud[1] = n;
                  count++;
                }
                else if (tempo == 1 && count == 3)
                {
                    obj[i].salary[1] = stof(record);
                    count++;
                }
            }
            if (tempo)
            {
                break;
            }
            csv_contents[counter] = items;
            items.clear();
            counter += 1;
        }
        if (!tempo)
        {
            obj[i].stud[1] = -1;
            obj[i].salary[1] = -1;
        }

    //--------------------------------------------------------------------------
    string filename2(v[2]);
    file_contents = "";
    csv_contents.clear();
    record="";
    file_contents = readFileIntoString(filename2);
    istringstream sstream2(file_contents);
    items.clear();
    counter = 0;
    tempo = 0;
    while (std::getline(sstream2, record))
    {
        istringstream line2(record);
        int count = 1;
        while (std::getline(line2, record, delimiter))
        {
            items.push_back(record);
            if (count == 1)
            {
                transform(record.begin(), record.end(), record.begin(), ::toupper);
                if (record == companies[i])
                {
                    tempo = 1;
                }
                count++;
            }
            else if (tempo == 1 && count == 2)
            {
                int n=stoi(record);
                obj[i].stud[2] =n;
                count++;
            }
            else if (tempo == 1 && count == 3)
            {
                obj[i].salary[2] = stof(record);
                count++;
            }
        }
        if (tempo)
        {
            break;
        }
        csv_contents[counter] = items;
        items.clear();
        counter += 1;
    }
    if (!tempo)
    {
        obj[i].stud[2] = -1;
        obj[i].salary[2] = -1;
    }

//---------------------------------------------------------------------------
string filename3(v[3]);
file_contents = "";
csv_contents.clear();
record="";
file_contents = readFileIntoString(filename3);
istringstream sstream3(file_contents);
items.clear();
counter = 0;
tempo = 0;
while (std::getline(sstream3, record))
{
    istringstream line3(record);
    int count = 1;
    while (std::getline(line3, record, delimiter))
    {
        items.push_back(record);
         if (count == 1)
            {
                transform(record.begin(), record.end(), record.begin(), ::toupper);
                if (record == companies[i])
                {
                    tempo = 1;
                }
                count++;
            }
            else if (tempo == 1 && count == 2)
            {
                int n=stoi(record);
                obj[i].stud[3] = n;
               count++;
            }
            else if (tempo == 1 && count == 3)
            {
                obj[i].salary[3] = stof(record);
                count++;
            }
        }
        if (tempo)
        {
            break;
        }
        csv_contents[counter] = items;
        items.clear();
        counter += 1;
    }
    if (!tempo)
    {
        obj[i].stud[3] = -1;
        obj[i].salary[3] = -1;
    }
    
    
    obj[i].print();
  //  cout<<"----------------------------------\n";
    
    

}
cout<<"--------------------------------SORTING--------------------------------\n";
    sort(obj,obj+240, comp);
    for(int i=0;i<240;i++)
    {
        cout<<i<<" "<<obj[i].max_sal<<" ";
        obj[i].print();
    }
// Writing into CSV
fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("final.csv", ios::out | ios::app);
  
     fout << "Name" << ", "
             <<"Salary 17-18"<< ", "
             <<"No. of Students 17-18"<< ", "
             <<"Salary 18-19"<< ", "
             <<"No. of Students 18-19"<< ", "
              <<"Salary 19-20"<< ", "
             <<"No. of Students 19-20"<< ", "
              <<"Salary 20-21"<< ", "
             <<"No. of Students 20-21"<< "\n";
    // Read the input
    for (i = 0; i < 240; i++) {
  
       
  
        // Insert the data to file
        fout << obj[i].name << ", "
             << obj[i].salary[0]<< ", "
             << obj[i].stud[0]<< ", "
             << obj[i].salary[1]<< ", "
             << obj[i].stud[1]<< ", "
              << obj[i].salary[2]<< ", "
             << obj[i].stud[2]<< ", "
              << obj[i].salary[3]<< ", "
             << obj[i].stud[3]<< "\n";
             
    }
    
}


