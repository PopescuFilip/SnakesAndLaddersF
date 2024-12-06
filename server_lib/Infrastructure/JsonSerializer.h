#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include <crow/json.h>

class JsonSerializer
{
public:
	inline static void serializeSuccess(crow::json::wvalue& json, bool succes) { json["succes"] = succes; }
	inline static void serializeMessage(crow::json::wvalue& json, const std::string& message) { json["succes"] = message; }
};

#endif // JSONSERIALIZER_H