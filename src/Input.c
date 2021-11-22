#include "Input.h"

#define KEY_NUM 256

int keys_now[KEY_NUM];
int keys_before[KEY_NUM];

void IUpdate() {
    for(int i = 0; i < KEY_NUM; i++)
    {
        keys_before[i] = keys_now[i];    
    }
}

void AddKey(int key) {
    keys_now[key] = 1;
}

void RemoveKey(int key) {
    keys_now[key] = 0;
}

int KeyDown(int key){
    return keys_now[key];
}

int KeyPress(int key) {
    return keys_now[key] && !keys_before[key];
}

int KeyUp(int key) {
    return !keys_now[key] && keys_before[key];
}
