#include "crow.h"
#include "API.h"

int main()
{
    crow::SimpleApp app;
    SetLobbyRoutes(app);
    SetGameRoutes(app);
    app.port(18080).run();
}
