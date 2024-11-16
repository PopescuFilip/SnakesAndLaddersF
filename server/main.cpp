#include "crow.h"
#include "API.h"

int main()
{
    crow::SimpleApp app;
    SetRoutes(app);
    app.port(18080).run();
}
