#include "input_controller.h"


void InputController::setTarget(InputControllerTarget* target) {
    _target = target;
}

void InputController::update() {
    SDL_GetMouseState(&_mx, &_my);
    if(_target != nullptr) {
        _target->setMousePos(_mx, _my);
    }
    
}

void InputController::pollEvents() {
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0) {
        switch (e.type)
        {
        case SDL_QUIT:
            if(_target != nullptr)
                _target->onExitApplication();
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(_target != nullptr)
                _target->onMouseDown(_mx, _my);
            break;
        case SDL_MOUSEBUTTONUP:
            if(_target != nullptr)
                _target->onMouseUp(_mx, _my);
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