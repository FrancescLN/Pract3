#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

template <typename T> 
class BSTree {
    private:
        int nelem; //Número de elementos almacenados
        BSNode<T> *root; //Nodo raíz
        
        BSNode<T>* search(BSNode<T>* n, T e) const{ //Método recursivo para busqueda de elementos
        if(n == nullptr){	// En caso de que el puntero sea null
			throw runtime_error("Error search");
		}else if(n->elem < e){	// En caso de que n-> sea menor que e buscamos derecha
			return search(n->right, e);
		}else if(n->elem > e){	// En caso de que n-> sea mayor que e buscamos izq
			return search(n->left,e); 
		}else{			// En caso de que n sea == e devolvemos n, dado que lo hemos encontrado
			return n;
		}
        }
        BSNode<T>* insert(BSNode<T>* n, T e){ //metodo recursivo para le inserción ordenada de elementos
        	if(n != nullptr) {
			if((n->elem) == e) { //Si ya existe el elemento
				throw std::runtime_error("El elemento ya existe");
			} else if((n->elem) > e) {  //si valor elem es menor que el nodo actual
				n->left = insert(n->left, e);
			} else { // si el valor elem es mayor al nodo actual
				n->right = insert(n->right, e);
			}
			return n;
		} else {
			nelem++;
			return new BSNode<T>(e);
		}
        }
        void print_inorder(std::ostream &out, BSNode<T>* n) const{ //imprimir en orden los resultados
        	if(n !=nullptr){
			print_inorder(out,n->left);	// Primero miramos izq
			out << n->elem << " ";		// Si ya no hay izq imprimimos el elem actual
			print_inorder(out,n->right);	// Una vez mirado izq e impreso actual miramos drch
		}
        }
        
        BSNode<T>* remove(BSNode<T>* n, T e){ //Método recursivo para eliminar elementos
        	if(n == nullptr){ // en caso de que el puntero sea null
			throw runtime_error("Error remove");
		}else if(n->elem < e){	// En caso de que n-> sea menor que e buscamos derecha
			n->right = remove(n->right,e);
		}else if(n->elem > e){	// En caso de que n-> sea mayor que e buscamos izq
			n->left = remove(n->left,e);
		}else{// En caso de que hayamos encontrado
			if((n->left != nullptr) && (n->right != nullptr)){ // En caso de que tenga hijos tanto derecha como izq
				n->elem = max(n->left);
				n->left = remove_max(n->left);
			}else{	// En caso de que no tenga izq o derecha, elegimos uno u otro para que sea n
				if (n->left != nullptr) {
				    n = n->left;
				} else {
				    n = n->right;
				}
			}
		}
		return n;        	
        }
        T max(BSNode<T>* n) const{ //Método recusrivo que devuelve el elemento máximo 
        	if(n == nullptr){
			throw runtime_error("Error max");
		}else if(n->right != nullptr){	// En caso de que exista derecha, vamos hacia la derecha
			return max(n->right);
		}else{	// En caso contrario hemos llegado al valor maximo que sera elem actual
			return n->elem;
		}
        }
        BSNode<T>* remove_max(BSNode<T>* n){ // Método recursivo que elimina el elemento máximo
        	if(n->right == nullptr){	// En caso de que no exista un valor a la drch devolvemos izq
			return n->left;
		}else{
			n->right = remove_max(n->right); // En caso de que si exista derecha, seguimos yendo a la derecha a buscar el val max
			return n;
		}
        }
        void delete_cascade(BSNode<T>* n){ //Método recursivo liberación de memoria dinamica
        	if(n != nullptr){
			delete_cascade(n->left);
			delete_cascade(n->right);
			delete n;
		}
        }
    public:
        BSTree(){	// Constructor
		nelem = 0;
		root = nullptr;
	}

	int size() const{
		return nelem;
	}

	// Busqueda Elementos
	T search(T e) const{
		return search(this->root,e)->elem;	
	}

	T operator[](T e) const{
		return search(e);
	}

	// Insercción de elementos
	void insert(T e){
		root = insert(root,e);
	}
	
	// Recorrido e impresión del arbol
	friend ostream&operator<<(ostream &out, const BSTree<T> &bst){
		bst.print_inorder(out,bst.root);
	      	return out;
	}

	// Eliminación de elementos
	void remove(T e){
		root = remove(root,e);
		nelem--;
	}

	// Destruccion
	~BSTree(){
		delete_cascade(root);
	}
};

#endif
