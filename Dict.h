#ifndef DICT_H
#define DICT_H
#include <string>

using namespace std;

template <typename V> 
class Dict {
    public:
    		//insetrar elemento
	virtual void insert(string key, V value) = 0;
		//buscar elemento
	virtual V search(string key) = 0;
		//eliminar elemento
	virtual V remove(string key) = 0;
		//número de entradas
	virtual int entries() const = 0;
};

#endif
