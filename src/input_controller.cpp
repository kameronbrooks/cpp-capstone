#include "input_controller.h"


void InputController::setTarget(InputControllerTarget* target) {
    _target = target;
}

void InputController::pollEvents() {
    SDL_Event e;
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    while(SDL_PollEvent(&e) != 0) {
        switch (e.type)
        {
        case SDL_QUIT:
            if(_target != nullptr)
                _target->onExitApplication();
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(_target != nullptr)
                _target->onMouseDown(mx, my);
            break;
        case SDL_MOUSEBUTTONUP:
            if(_target != nullptr)
                _target->onMouseUp(mx, my);
            break;
        case SDL_MOUSEMOTION:
            if(_target != nullptr)
                _target->onMouseMove(mx, my);
            break;
        default:
            break;
        }
    }
}

InputController::InputController() {
    _target = nullptr;
}
InputController::InputController(const InputController& other) {
    _target = other._target;
}
InputController::~InputController() {

}