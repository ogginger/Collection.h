//searchVector.h: Search a collection for the position of the values asked for.

#include <vector>

using namespace std;

template <class Type>
vector<int> searchVector( vector<Type> Collection, Type Value ) {
        vector<int> xMatchingElementPositions;
        for ( int Iterator = 0; Iterator < Collection.size(); Iterator++ ) {
                if ( Collection.at( Iterator ) == Value ) {
                        xMatchingElementPositions.push_back(Iterator);
                }
        }
        return xMatchingElementPositions;
}
