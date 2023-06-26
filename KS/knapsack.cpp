#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream inp("data_ks/ks_4_0");
	long long N, W;
	inp >> N >> W;
	vector <long long> v(N);
	vector <long long> w(N);
	for (int i = 0; i < N; i++) 
		inp >> v[i] >> w[i];
}