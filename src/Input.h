#pragma once

#define KEY_NUM 256

#define KEY_UP 0
#define KEY_DOWN 1

void IUpdate();
void SetKey(int key, int state);

int KeyDown(int key);
int KeyPress(int key);
int KeyUp(int key);
