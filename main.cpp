

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<algorithm>
using namespace std;


void deleteColumn(vector<vector<string>> &content, int columnToDelete) {


	for (unsigned i = 0; i < content.size(); ++i)
	{
		if (content[i].size() > columnToDelete)
		{
			content[i].erase(content[i].begin() + columnToDelete);
		}
	}
}

void deleteRow(vector<vector<string>>& content, unsigned int rowToDelete) {



	for (unsigned i = 0; i < content.size(); ++i)
	{
		if (content[i].size() > rowToDelete)
		{
			content[i].erase(content[i].begin() + rowToDelete);
		}
	}
}
void printVec(vector<vector<string>>& content) {
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}
}
void remove(vector<vector<string>>& v)
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) {
		end = remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}
void readfile(vector<vector<string>>& content, vector<string> row, string fileName) {
	string line, word;


	ifstream file;
	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout << "Could not open the file\n";
}
void mergeCsv(vector<vector<string>> &merge, vector<vector<string>>& content, vector<vector<string>> &content2) {
	merge = content;
	merge.insert(merge.end(), content2.begin(), content2.end());

	/*for (const auto& row : merge)
	{
		
	}*/
	remove(merge);
}
int main()
{
	



	vector<vector<string>> content;
	vector<string> row;
	vector<vector<string>> content2;
	vector<string> row2;
	vector<vector<string>> totalCsv;
	string fileName1 = "student-por.csv";
	string fileName2 = "student-mat.csv";
	readfile(content,row,fileName1);


//	deleteColumn(content, 4);

	//printVec(content);
	readfile(content2, row2, fileName2);
	//printVec(content2);
	//deleteRow(content2, 0);
	mergeCsv(totalCsv,content,content2);
	
	printVec(totalCsv);
	return 0;
}