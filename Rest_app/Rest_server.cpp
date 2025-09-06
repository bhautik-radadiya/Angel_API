#include "crow.h"

int main() {
    crow::SimpleApp app;

    // root endpoint
    CROW_ROUTE(app, "/")([](){
        return "Hello, World!";
    });

    // another endpoint
    CROW_ROUTE(app, "/hello")([](){
        return "Hello from Crow!";
    });

    // endpoint with parameter
    CROW_ROUTE(app, "/user/<int>")([](int id){
        return "User ID: " + std::to_string(id);
    });

    app.port(8080).multithreaded().run();
}

