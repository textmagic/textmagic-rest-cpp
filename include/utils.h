#ifndef TEXTMAGIC_UTILS_H
#define TEXTMAGIC_UTILS_H

#include <sstream>
#include <typeinfo>
#include <vector>
#include <json/json.h>

namespace Textmagic {
	namespace Utils {
		template <class T>
		static std::string vectorJoin( const std::vector<T>& v, const std::string& token ){
		  std::ostringstream result;
		  for (typename std::vector<T>::const_iterator i = v.begin(); i != v.end(); i++){
			if (i != v.begin()) result << token;
			result << *i;
		  }
		  return result.str();
		};

		template <typename T>
		static std::string toString ( T data )
		{
			if (typeid(data) == typeid(bool)) {
				return data ? "true" : "false";
			}

			std::ostringstream ss;
			ss << data;
			return ss.str();
		};
		
		double parseDouble(const Json::Value& value);
		
	}
}
#endif /* TEXTMAGIC_UTILS_H */