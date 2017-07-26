#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

template<typename T>
class RectangleDataStructure {
public:
	typedef typename std::vector<T>::iterator iterator;
	typedef typename std::vector<T>::const_iterator const_iterator;
	RectangleDataStructure() {};



	void SetValueAt(int x, int y, T val) { data[y*(width_pr) + x] = val; }
	void InsertRowBefore(int y, T val);
	void InsertColBefore(int x, T val);
	void SetStructure(T val, int l, int w) { data.resize((l*w), val); length_pr = l; width_pr = w; }

	T valueAt(int x, int y) const { return data[y*(width_pr) + x]; }
	T& valueAt(int x, int y) { return data[y*width_pr + x]; }

	size_t size() const { return data.size(); }
	iterator begin() { return data.begin(); }
	iterator end() { return data.end(); }
	const_iterator begin() const { return data.begin(); }
	const_iterator end() const { return data.end(); }

	int width() { return width_pr; }
	int length() { return length_pr; }

private:
	std::vector<T> data;
	int length_pr = 0;
	int width_pr = 0;


};




template<typename T>
inline void RectangleDataStructure<T>::InsertRowBefore(int y, T val) {
	for (int it = 0; it < width_pr; it++)
	{
		data.insert(data.begin() + (width_pr * ((y)*2))-width_pr, val);
	}
	length_pr++;
}


template<typename T>
inline void RectangleDataStructure<T>::InsertColBefore(int x, T val) {
	for (int it = 0; it < length_pr; it++)
	{
		data.insert(data.begin() + ((x-1)*2) + (it * (width_pr +1)) +1 , val);
		
	}
	width_pr++;
}
