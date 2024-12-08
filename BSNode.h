#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

using namespace std;

template <typename T> 
class BSNode {
    public:
        T elem; //elemento tipo T almacenado en el Nodo
        BSNode<T>* left; //Puntero al nodo sucesor izquierdo
    	BSNode<T>* right; //Puntero al nodo sucesor derecho
    	
    	BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr){
    		this->elem = elem;
    		this->left = left;
    		this->right = right;
    	} //Constructor quew crea un nodo con elemento elem y punteros a los sucesores left y right(nulos por defecto)
    	friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
    	out << bsn.elem < endl;
    	return out;
    	}
    	
};

#endif
