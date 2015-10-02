#include <utils.h>
namespace Textmagic {
	namespace Utils {
		
		double parseDouble(const Json::Value& value)
		{
			
			float ret = 0;
			if (value.isDouble())
			{
				ret = value.asFloat();
			}
			else
			{
				ret = atof( value.asString().c_str());
			}
			return ret;
		}
		
	}
	
}