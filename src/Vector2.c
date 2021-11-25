#include "Vector2.h"

Vector2* AllocVector2() {
	Vector2* vec = NULL;
	vec = malloc(sizeof(Vector2));
	if(vec == NULL) {
		printf("Could not create a vector!");
		return NULL;	
	}

	return vec;
}

Vector2* InitializeVector2(float x, float y)
{
	Vector2* vec = AllocVector2();
	vec->x = x;
	vec->y = y;
	return vec;
}

Vector2* CloneVector2(Vector2* vector)
{
	Vector2* clone = AllocVector2();
	memcpy(clone, vector, sizeof(Vector2));
	return clone;
}

void Add(Vector2* this, const Vector2* other)
{
	this->x += other->x;
	this->y += other->y;
}

void Sub(Vector2* this, const Vector2* other)
{
	this->x -= other->x;
	this->y -= other->y;
}

void MulByScalar(Vector2* this, float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
}

float MagnitudeSquare(const Vector2* this)
{
	return this->x * this->x + this->y * this->y;
}
