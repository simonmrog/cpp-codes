#include <iostream>
using namespace std;

template <class T> class Dictionary {
   
   private:
   int size, top;
   string *keys;
   T *values;

   public: 
   //CONSTRUCTORS
   Dictionary () {
      this->size = 10e5;
      top = -1;
      keys = new string [size];
      values = new T [size];
   }

   Dictionary (int size) {
      this->size = size;
      top = -1;
      keys = new string [size];
      values = new T [size];
   }
   
   //DESTRUCTOR
   ~Dictionary () {
      delete []keys;
      delete []values;
   }

   int length () {
      return (top + 1);
   }

   bool is_full () {
      return (top == size - 1);
   }

   bool is_empty () {
      return (top == -1);
   }

   void print () {
      
      if (is_empty ()) cout << "Dictionary is empty" << endl;
      
      cout << "Dictionary: {" << endl;
      for (int i=0; i<=top; i++)
         cout << "  " << "[\"" << keys[i] << "\"] = " << values[i] << endl;
      cout << "}" << endl;   
   }

   T get (string key) {

      int index = search (key);
      return (values [index]);
   }

   bool exists (string key) {

      int index = search (key);
      return (index != -1);
   }

   void push (string key, T value) {

      if (is_full ()) cout << "Dictionary is full" << endl;

      else {
         keys[++top] = key;
         values[top] = value; 
      }  
   }

   void pop () {

      if (is_empty ()) cout << "Dictionary is empty." << endl;
      else top -= 1;
   }

   void remove (string key) {

      int index = search (key);

      for (int i=index; i<top; i++) {
         keys [i] = keys [i+1];
         values [i] = values [i+1];
      }
      top--;
   }

   T operator = (T data) {

      this = data;
      return *this;
   } 

   T operator [] (string key) {

      int index = search (key);
      return (values [index]);
   }

   //AUXILIARY FUNCTIONS 
   int search (string key) {

      int index;
      bool found = false;

      for (int i=0; i<size; i++) {

         if (keys [i] == key) {
            index = i;
            i = size+1;
            found = true;
         }
      }

      if (found) return (index);
      else return (-1);
   }
};