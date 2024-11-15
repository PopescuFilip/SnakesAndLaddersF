#include "crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/").methods("GET"_method)([]() {
       return "Hello world!";
    });

    app.port(18080).run();
}