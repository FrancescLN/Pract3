#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree; //ABB con elementos para gestionar los elementos de un diccionario

    public:
        BSTreeDict(){ //Constructor 
        	tree = new BSTree<TableEntry<V>>;
        }
        
        ~BSTreeDict(){ //Destructor
		delete tree;        
        }
        
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){ //Sobrecarga para imprimir el contenido del diccionario
        out << bs.tree << endl;
        return out;
        }
        
        V operator[](std::string key){ //Sobrecarga del operador [] interfaz al método interfaz heredado
        	return tree->search(TableEntry<V>(key)).value;
        }
        
        // Implementación metodos abstractos clase Dict<V>
	void insert(string key, V value){	//Insert clave, valor
		tree->insert(TableEntry<V>(key,value));
	}

	V search(string key){	//Busqueda del valor teniendo clave
		return tree->search(TableEntry<V>(key)).value;	
	}

	V remove(string key){	// Eliminamos mediante clave y devolvemos el valor que tenia
		V valor = tree->search(TableEntry<V>(key)).value;
		tree->remove(TableEntry<V>(key));
		return valor;
	}

	int entries() const override {	// Implementamos metodo entries
        	return tree->size();
	}
};

#endif
