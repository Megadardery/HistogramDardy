#include <iostream>
#include <random>
#include <chrono>
#include "Histogram.h"

using namespace std;

const int N = 1000000;
double arr[N];
int arrint[N];

int main() {

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int mu = 15000, s = 3500;
	normal_distribution<double> nd(mu, s);
	for (int i = 0; i < N; i++) {
		arr[i] = nd(rng);
	}
	
	drawHistogram(cout, 254, arr, N, 3450, 26550, 30, 50);

	uniform_real_distribution<double> rd(-31, 59);
	for (int i = 0; i < N; i++) {
		arr[i] = rd(rng);
	}
	drawHistogram(cout, 254, arr, N, -31, 59, 30, 50);

	uniform_int_distribution<int> id(1, 8);
	for (int i = 0; i < N; i++) {
		arrint[i] = id(rng);
	}

	drawHistogram(cout, 254, arrint, N, 0, 9, 10, 50);
}
