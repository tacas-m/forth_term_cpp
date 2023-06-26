#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() 
{
	ifstream inp("data_tsp/tsp_99_1");
	ofstream data;
	data.open("data.dzn");
    long long V, i, j, k = 0;
	inp >> V;
	data << "V = " << V << ';' << endl;
	data << "E_n = " << V * (V - 1) << ';' << endl;
	data << "E = array2d(1..E_n, 1..2,[" << endl;
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			if (i != j) 
				data << i + 1 << ',' << j + 1 << ',' << endl;
	
	data << "]);" << endl;
	data << endl;
	double xi, yi, dist;
	vector <double> x (V);
	vector <double> y (V);
	for (i = 0; i < V; i++) {
		inp >> xi >> yi;
		x[i] = xi;
		y[i] = yi;
	}
	data << "c = [" << endl;
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			if (i != j) 
				data << round(sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) * 1000) << ',' << endl;
	
	data << "];";
	data.close();
	inp.close();
	system("minizinc --solver Gecode minizinc_TSP.mzn data.dzn");
	return 0;
}