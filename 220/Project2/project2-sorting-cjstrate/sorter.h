/*
 * sorter.h
 *
 * Declares a template function:
 *    
 *   sorter() : k-way merge sort.
 * 
 * 
 * You may add other functions if you wish, but this template function
 * is the only one that need to be exposed for the testing code.
 * 
 * Authors: C. Painter-Wakefield & Tolga Can
 */

#ifndef _SORTER_H
#define _SORTER_H

#include <string>
#include <cstddef>
#include <vector>

using namespace std;

template <class T>
void sorter(vector<T> &vec, int k) {  
	//cout << "top of split" << endl;
	if (vec.size() <= 1){
		return;
	}
	
	// make all required vectors strored in another vector
	vector<vector<T>> vectors;
	for (int i = 0; i <= k; i++){
		vectors.push_back({});
	}

	// add appropriate values
	//cout << "adding stuff" << endl;
	for (unsigned int i = 0; i < vec.size(); i++){
		//cout << "adding stuff at " << i << endl;
		(vectors.at(i % k)).push_back(vec.at(i));
		//cout << "done adding stuff at " << i << endl;
	}
	//cout << "done adding stuff" << endl;
	// recurse
	for (int i = 0; i <= k; i++){
		//cout << "recursing " << i << endl;
		sorter(vectors.at(i),k);
	}

	// merge
	//cout << "top of merge" << endl;
	int index = 0;
	// move past all vecotors of size 0
	for (int i = vec.size() - 1; i >= 0; i--){
		for (int j = 0; j < k; j++){
			if (!(vectors.at(j).empty())){
			index = j;
			break;
			}
		}
		// find the largest value
		for (int j = index + 1; j < k; j++){
			if (!(vectors.at(j).empty()) && (vectors.at(index).back() < vectors.at(j).back())){
				index = j;
			}
		}
		// add the largest value to end of the orginal vector and remove said value from the k vector
		vec.at(i) = vectors.at(index).back();
		vectors.at(index).pop_back();
	}
	//cout << "bottom of merge" << endl;
	return;
}
#endif