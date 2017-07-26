#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

template<typename T>
class SquareDataStructure {
public:
	typedef typename std::vector<T>::iterator iterator;
	typedef typename std::vector<T>::const_iterator const_iterator;
	SquareDataStructure() {};
	int len() { return length_pr; }
	void SetValueAt(int x, int y, T val) { data[y*(length_pr) + x] = val; }
	T valueAt(int x, int y) const { return data[y*(length_pr) + x]; }
	T& valueAt(int x, int y) { return data[y*length_pr + x]; }
	void SetStructure(T val, int l) {data.resize(((l)*(l)) , val);length_pr = l;}
	size_t size() const { return data.size(); }
	iterator begin() { return data.begin(); }
	iterator end() { return data.end(); }
	const_iterator begin() const { return data.begin(); }
	const_iterator end() const { return data.end(); }

private:
	std::vector<T> data;
	int length_pr = 0;


};