//Collection.h: Key Value Pair Container with CRUD methods.

#include <vector>

#include "searchVector.h"

using namespace std;

template <class Type, class Id_Type>
class Collection {
public:
	Collection() {}
	
	Type get( Id_Type Id ) {
		vector<int> Occurence = searchVector( Index, Id );
		if ( Occurence.size() <= 0 ) {
			throw "Error: Id does not exist.";
		} else {
			return Content.at( Occurence.at(0) );
		}

	}

	bool add( Id_Type Id, Type Value ) {
		bool bIdExists = true;
		bool bAdded = false;
		vector<int> Occurence = searchVector( Index, Id );
		if ( Occurence.size() == 0 ) {
		//if the id doesn't exist then...
			Index.push_back( Id );
			Content.push_back( Value );
			bAdded = true;
		} else {
		//otherwise it does exist so...
			cerr << "The Id, entered already exists." << endl;
		}
		return bAdded;
	}

	bool update( Id_Type Id, Type Value ) {
		vector<int> Occurence = searchVector( Index, Id );
		bool bUpdated = false;
		if ( Occurence.size() > 0 ) {
		//If the id exists thenn.
			//Update the element.
			Content.at( Occurence.at(0) ) = Value;
			bUpdated = true;
		} else {
		//otherwise the element does not exist so...
			cerr << "The Id entered does not exist." << endl; 
		}
	}

	void remove( Id_Type Id ) {
		//Remove the element, and update the index.
		vector<int> Occurence = searchVector( Index, Id );
		bool bRemoved = false;
		if ( Occurence.size() > 0 ) {
		//if the id exists then...
			//Delete that element in the index and the collection.
			Index.erase( Occurence.at(0) );
			Content.erase( Occurence.at(0) );
			bRemoved = true;
		} else {
		//otherwise the id does not exists so...
			cerr << "The Id entered does not exist." << endl;
		}
	}

	bool has( string Key ) {
		bool bHas = false;
		vector<int> Occurences = searchVector<Id_Type>( Index, Key );
		if ( Occurences.size() > 0 ) {
			bHas = true;
		} else {
			cout << "That element does not exist." << endl;
		}
		return bHas;
	}

	vector<Type> Content;
	vector<Id_Type> Index;
};
