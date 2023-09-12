#include <map>
#include <iostream>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
public:
	V m_valBegin;
	std::map<K,V> m_map;
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{
        for (double i = -999.0; i <= 999.0; i++)
        {
            m_map[i] = val;
        }

    }
	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        // if keyBegin is not less than keyEnd, then this designates an empty interval, so
        // save processing time calling map:find below, and just do nothing and return.
        if (!(keyBegin < keyEnd ))
        {
            return;
        }
        for(auto it = m_map.find(keyBegin);  it != m_map.find(keyEnd); ++it)
        {
            // cannot dereference an end iterator, so if we met the end, just break as we are done assignment anyway
            if(it != m_map.end())
            {
                it->second = val;
            }
            else
            {
                break;
            }
        }
    }

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.