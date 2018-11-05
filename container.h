#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Container
{

  public:
    typedef typename vector<T *>::iterator iterator;
    typedef typename vector<T *>::const_iterator const_iterator;

    Container();
    Container(const Container &container);
    ~Container();

    // assignment constructor
    Container &operator=(const Container &container);
    // Put the input value into the container
    Container &operator<<(T *value);

    const_iterator begin() const;
    iterator begin();

    const_iterator end() const;
    iterator end();

    vector<T *> getValues() const;
    int getSize() const;

    T *getValue(string name);
    bool hasValue(const T *value) const;
    void addValue(T *value);
    void removeValue(T *value, bool deletePointer);

    inline void printDetails() const
    {
        // cout<<"\nValues in container:"<<endl;
        const_iterator cit;
        int index;
        for (cit = values.begin(), index = 0; cit != values.end(); ++cit, ++index)
        {
            cout << "\tValue at " << index << ": " << endl;
            (*cit)->printDetails();
        }
    };

  private:
    vector<T *> values;
};

template <class T>
Container<T>::Container() : values(){}

template <class T>
Container<T>::Container(const Container &container){
    /*
    * Copy constructor of Container.
    * 
    * Make use of the vector iterators 'const_iterator' to deep copy the values 
    * from input container. 
    * 
    * Use std::vector functions begin(), end() and push_back().
    * 
    * Add your code here!
    */
	for (const_iterator p = container.values.begin(); p != container.values.end(); p++){
		values.push_back(new T(**p));
	}
}

template <class T>
Container<T>::~Container(){
    for (const_iterator cit = values.begin(); cit != values.end(); ++cit)
        delete *cit;
}

template <class T>
Container<T> &Container<T>::operator=(const Container &container)
{
    /*
    * Overloading the assignment operator.
    * 
    * You need to free the memory previously allocated for values and then
    * deep copy the input containers' values. Remember you need to check
    * whether the input container is this container itself, or you will wrongly
    * deallocate the memory for values.
    * 
    * Use std::vector functions begin(), end(), push_back() and clear().
    * 
    * Add your code here!
    */
	if (this==&container) {
		return *this;
	}
	for (const_iterator p = values.begin(); p!=values.end(); p++){
		delete *p;
	}
	values.clear();
	for (const_iterator q = container.values.begin(); q!=container.values.end(); q++){
		values.push_back(new T(**q));
	}
	return *this;
}

template <class T>
Container<T> &Container<T>::operator<<(T *value)
{
    /*
    * Overloading the left shift operator.
    * 
    * Store the input T* type value into the container's values vector.
    * Remember to check the existence of the input value in the container 
    * to avoid duplication.
    * 
    * Return the reference to the container itself.
    * 
    * Use std::vector push_back().
    * 
    * Add your code here!
    */
	for (const_iterator p = values.begin(); p != values.end(); p++){
		if (*p==value){return *this;}
	}
	values.push_back(value);
	return *this;

}

template <class T>
typename Container<T>::const_iterator Container<T>::begin() const {return values.begin();}

template <class T>
typename Container<T>::iterator Container<T>::begin(){return values.begin();}

template <class T>
typename Container<T>::const_iterator Container<T>::end() const{return values.end();}

template <class T>
typename Container<T>::iterator Container<T>::end(){return values.end();}

template <class T>
int Container<T>::getSize() const
{
    /*
    * Get the size of values of the container.
    * 
    * Return int type size of the values in the container.
    * 
    * Use std::vector size().
    * 
    * Add your code here!
    */
	return static_cast<int>(values.size());
}

template <class T>
vector<T *> Container<T>::getValues() const {return values;}

template <class T>
T *Container<T>::getValue(string name)
{
    /*
    * Extract the value from values in the container by name.
    * 
    * Go through the container by iterator.
    * 
    * Reture the stored content found by input name or return NULL
    * if not found.
    * 
    * Use std::vector begin() and end().
    * 
    * Add your code here!
    */
	for (iterator p = values.begin(); p != values.end(); p++){
		if (*p->name.compare(name)==0){
			return *p;
		}
	}
	return NULL;
}

template <class T>
bool Container<T>::hasValue(const T *value) const
{
    /*
    * Check whether the input value is already in the container.
    * 
    * Return bool indicating the existence of value in the container.
    * 
    * Use std::find() and std::vector begin(), end().
    * 
    * Add your code here!
    */
	for (const_iterator p = values.begin(); p!=values.end(); p++){
		if (*p==value){
			return true;
		}
	}
	return false;
}

template <class T>
void Container<T>::addValue(T *value)
{
    /*
    * Add value into the container.
    * 
    * Remember to ckeck the existence of input value in the container to
    * avoid duplication.
    * 
    * Reture void.
    * 
    * Use std::vector begin() and end().
    * 
    * Add your code here!
    */
	if (!hasValue(value)){
		values.push_back(new T(*value));
	}
}

template <class T>
void Container<T>::removeValue(T *value, bool deletePointer)
{
    /*
    * Remove the value from the container.
    * 
    * Go through the container by iterator and remove the input value from the
    * container. The second argument deletePointer indicates whether free the
    * memory allocated to value or not.
    * 
    * Reture void.
    * 
    * Use std::vector begin(), end(), erease().
    * 
    * Add your code here!
    */
	for (iterator p = values.begin(); p != values.end(); p++){
		if (*p==value){
			if (deletePointer) { values.erase(p); break;}
			else {delete *p;}
		}
	}
}

#endif /* CONTAINER_H */
