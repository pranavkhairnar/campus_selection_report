
#include<bits/stdc++.h>
using namespace std;
void read_record()
{
	fstream fin;
	fin.open("p1718.csv", ios::in);
	int rollnum, roll2, count = 0;
	vector<string> row;
	string line, word, temp;
    cout<<"hi1\n";
	while (fin >> temp)
     {
		//row.clear();
		getline(fin, line);
		stringstream s(line);
        cout<<"hello world\n ";
		while (getline(s, word, ',')) 
        {
			row.push_back(word);
            cout<<word<<"\n";
            cout<<"hi3\n";
		}
		roll2 = stoi(row[0]);
		/*	cout << "Details of Company  " << row[0] << " : \n";
			cout << "Nubmer: " << row[1] << "\n";
			cout << "Salary: " << row[2] << "\n";*/
            cout<<"hi\n";
	}
	if (count == 0)
		cout << "Record not found\n";
}

int main()
{
    cout<<"hello\n";

    read_record();
    cout<<"hello2\n";
}