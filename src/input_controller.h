#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H
#include <SDL2/SDL.h>

class InputControllerTarget {
public:
    virtual void onExitApplication()=0;
    virtual void onMouseDown(int x, int y)=0;
    virtual void onMouseUp(int x, int y)=0;
    virtual void onMouseMove(int x, int y)=0;
    
};

class InputController {
private:
    InputControllerTarget* _target;
public:
    enum EventType {Exit = 0, MouseUp = 1, MouseDown = 2, MouseMove = 3};
    void setTarget(InputControllerTarget* target);

    void pollEvents();

    InputController();
    InputController(const InputController& other);
    ~InputController();
};

#endif