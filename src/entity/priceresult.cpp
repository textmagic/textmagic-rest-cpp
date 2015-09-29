#include <entity/priceresult.h>
#include <utils.h>


using namespace Textmagic;

void PriceResultModel::deserialize() {
	Json::Value root = this->asJsonValue();
	id = "";
	total = root.get("total", 0).asFloat();
	parts = root.get("parts", 0).asInt();
	countries = root["countries"];
};


float PriceResultModel::getPriceForCountry(const std::string& countryId)
{
	if (countries.empty())
	{
		return 0;
	}
	
	Json::Value country;
	if (countryId.empty())
	{
		country = *countries.begin();
	}
	else
	{
		country = countries.get(countryId, Json::Value ());
	}
	
	Json::Value value = country.get("sum", Json::Value ());
	return Utils::parseDouble(value);
}