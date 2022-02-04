#pragma once

#include <iostream>
#include <cmath>

#include "../../../vendor/glm/glm/glm.hpp"
#include "../../../vendor/glm/glm/gtc/matrix_transform.hpp"
#include "../../../vendor/glm/glm/gtc/type_ptr.hpp"

namespace Terrux {
    namespace Math {
        struct Vector2 {
            float x;
            float y;

            Vector2(float x, float y);
            Vector2(float val);
            Vector2();

            void Print();

            void Normalize();
            float getLength();

            static Vector2 Lerp(Vector2 source, Vector2 target, float speed);

            Vector2 operator-(Vector2 vecToSubstract);

            Vector2 operator+(Vector2 vecToAdd);

            Vector2 operator*(float val);
            Vector2 operator*(Vector2 vecToMult);

            void operator+=(Vector2 vecToAdd);
            void operator-=(Vector2 vecToSub);
        };


        struct Vector3 {
            float x;
            float y;
            float z;

            Vector3(float xPos, float yPos, float zPos);
            Vector3(Vector2 vec, float zPos);
            Vector3(float defVal);
            Vector3();

            void Print();

            void Normalize();

            float getLength();

            float Distance(Vector3 target);

            static Vector3 Lerp(Vector3 source, Vector3 target, float speed);

            Vector3 operator+(Vector3 vecToAdd);
            Vector3 operator/(Vector3 vecToDivide);

            Vector3 operator-(Vector3 vecToSubstract);

            Vector3 operator*(float val);
            Vector3 operator*(Vector3 vecToMult);

            void operator+=(Vector3 vecToAdd);
            void operator-=(Vector3 vecToSub);    
        };
    }
}
