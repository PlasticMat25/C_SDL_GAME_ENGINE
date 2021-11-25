#include "Input.h"

int current_keys[KEY_NUM];
int last_keys[KEY_NUM];

void IUpdate() {
    for(int i = 0; i < KEY_NUM; i++)
    {
        last_keys[i] = current_keys[i];
    }
}

void SetKey(int key, int state)
{
    current_keys[key] = state;
}

int KeyDown(int key)
{
    return current_keys[key];
}

int KeyPress(int key)
{
    return current_keys[key] && !last_keys[key];
}

int KeyUp(int key)
{
    return !current_keys[key] && last_keys[key];
}
