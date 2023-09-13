/*
 * hashtable.h
 *
 * A basic hashtable implementation.
 * 
 * Author: Carter Strates
 */

#ifndef _HASHTABLE_PROJECT_H
#define _HASHTABLE_PROJECT_H

#include <functional>   // for std::hash
#include <vector>

using namespace std;

template <class T, class H = std::hash<T>>
class hashtable {
public:
    // constructor
    hashtable(){
        list.resize(4);
        SizeVector = 4;
        SizeValues = 0;
    }

    // basic hashset operations
    void insert(const T& key){
        if (contains(key)){
            return;
        }
        size_t value = hash(key);
        if (((double)(SizeValues + 1)/(double)SizeVector) > 0.75){
            //cout << "hello" << endl;
            vector<vector<T>> temp;
            temp.swap(list);
            list.clear();
            list.resize(SizeVector * 2);
            for (size_t i = 0; i < SizeVector; i++){
                //cout << "start of loop " << i << endl;
                //cout << "Size " << temp.at(i).size() << endl;
                for (size_t j = 0; j < temp.at(i).size(); j++){
                    //cout << "one" << endl;
                    T newKey = temp.at(i).at(j);
                    size_t newValue = hash(newKey);
                    //cout << "two" << endl;
                    size_t newIndex = newValue % (SizeVector * 2);
                    //cout << "three" << endl;
                    list.at(newIndex).push_back(newKey);
                    //cout << "four" << endl;
                    //cout << endl;
                }
                //cout << "end of loop " << i << endl;
            }
            SizeVector = SizeVector * 2;
            temp.clear();
        }
        size_t index = value % SizeVector;
        list.at(index).push_back(key);
        SizeValues++;
    }
    void remove(const T& key){
        if (SizeValues != 0){
            size_t value = hash(key);
            size_t index = value % SizeVector;
            size_t location;

            if (contains(key)){
                for (size_t i = 0; i < list.at(index).size(); i++){
                    if (list.at(index).at(i) == key){
                        location = i;
                    }
                }
                list.at(index).erase(list.at(index).begin() + (location));
                SizeValues--;
            }
        }
    }
    bool contains(const T& key){
        size_t value = hash(key);
        size_t index = value % SizeVector;
        for (size_t i = 0; i < list.at(index).size(); i++){
            if (list.at(index).at(i) == key){
                return true;
            }
        }
        return false;
    }
    size_t size(){
        return SizeValues;
    }

    // diagnostic functions
    double load_factor(){
        double value = (double)SizeValues / (double)SizeVector;
        return value;
    }

    // convenience method, invokes the "hash" template parameter
    // function object to get a hash code
    static size_t hash(const T &key) {
        H h;
        return h(key);
    }

private:
    size_t SizeVector;
    size_t SizeValues;
    vector<vector<T>> list;
};

#endif
