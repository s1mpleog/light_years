#include <iostream>
#include <memory>
#include "framework/Application.h"

int main(void) {
    // old way of doing you manually need to free the memory from heap
    // ly::Application* old_way_app = new ly::Application();

    // modern way it will make sure that you have only one application
    std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();
    app->Run();
    return 0;
}
