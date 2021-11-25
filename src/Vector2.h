#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float x;
	float y;
} Vector2;

Vector2* InitializeVector2(float x, float y);
Vector2* CloneVector2(Vector2* vector);
void Add(Vector2* this, const Vector2* other);
void Sub(Vector2* this, const Vector2* other);
void MulByScalar(Vector2* this, float scalar);
float MagnitudeSquare(const Vector2* this);
