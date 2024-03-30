#include <iostream>
#include <string>

using namespace std;

// *** DO NOT CHANGE THE StringKeyIntValuePair CLASS
// *** USE IT AS THE BASIS FOR A TEMPLATIZED VERSION, called KeyValuePair, BELOW

class StringKeyIntValuePair {
public:
  StringKeyIntValuePair(string key, int value) {
    _key = key;
    _value = value;
  }

  string key() const { return _key; }
  int value() const { return _value; }

  void print() {
    std::cout << "< " << _key << ", " << _value << " >\n";
  }

private:
  string _key;
  int _value;

  void setKey(string key) { _key = key; }
  void setValue(int value) { _value = value; }
};

// *** CODE A TEMPLATIZED VERSION OF StringKeyIntValuePair HERE
// NAME THE class KeyValuePair
//from practice exam question 4
template <typename keyT, typename valueT>
class KeyValuePair {
public:
KeyValuePair(keyT key, valueT value) {
    _key = key;
    _value = value;
  }

  keyT key() const { return _key; }
  valueT value() const { return _value; }

  void print() {
    std::cout << "< " << _key << ", " << _value << " >\n";
  }

private:
  keyT _key;
  valueT _value;

  void setKey(keyT key) { _key = key; }
  void setValue(valueT value) { _value = value; }
};

// DJH: 100