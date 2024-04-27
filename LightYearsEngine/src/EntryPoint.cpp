#include "EntryPoint.h"
#include "framework/Application.h"

int main(void) {
    ly::Application* app = GetApplication();
    app->Run();

    delete app;
    return 0;
}
