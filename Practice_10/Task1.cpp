#include<iostream>
#include<vector>
#include<list>
#include<iomanip>
#include<string>

using namespace std;

const int DISTANCE = 6;

vector<string> split_string(string);
vector<int> BFS(int n, int m, vector<vector<int>> edges, int s);

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string nm_temp;
		getline(cin, nm_temp);

		vector<string> nm = split_string(nm_temp);

		int n = stoi(nm[0]);

		int m = stoi(nm[1]);

		vector<vector<int>> edges(m);
		for (int i = 0; i < m; i++) {
			edges[i].resize(2);

			for (int j = 0; j < 2; j++) {
				cin >> edges[i][j];
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		int s;
		cin >> s;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<int> result = BFS(n, m, edges, s);

		for (int i = 0; i < result.size(); i++) {
			fout << result[i];

			if (i != result.size() - 1) {
				fout << " ";
			}
		}

		fout << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

vector<int> BFS(int n, int m, vector<vector<int>> edges, int s)
{
	int start, end;
	list<int>l;
	int length = n + 1;
	vector<vector<int>>graph(length, vector<int>(length));
	vector<int>matrix(length);

	for (int i = 0; i <length; i++)
	{
		matrix[i] = -1;;
	}

	for (int i = 0; i < edges.size(); i++)
	{
		start = edges[i][0];
		end = edges[i][1];
		graph[start][end] = 1;
		graph[end][start] = 1;
	}


	l.push_back(s);
	matrix[s] = 0;
	int element;
	while (!l.empty())
	{
		element = l.front();
		l.pop_front();
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[element][i] == 1 && matrix[i] == -1)
			{
				l.push_back(i);
				matrix[i] = matrix[element] + DISTANCE;
			}
		}
	}
	if (matrix[0] == -1)
	{
		matrix.erase(matrix.begin() + 0);
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i] == 0)
		{
			matrix.erase(matrix.begin() + i);
		}
	}
	return matrix;
}

