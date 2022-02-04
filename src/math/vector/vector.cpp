#include "vector.hpp"

namespace Terrux::Math {

    /* VECTOR 2 */

    Vector2::Vector2(float x, float y):x(x), y(y) {}
    Vector2::Vector2(float val): x(val), y(val) {}

    Vector2::Vector2():x(0.0f), y(0.0f) {}

    void Vector2::Print() {
        std::cout << x << ", " << y << std::endl;
    }

    Vector2 Vector2::operator-(Vector2 vecToSubstract) {
        return Vector2(x - vecToSubstract.x, y - vecToSubstract.y);
    }  

    Vector2 Vector2::operator*(float val) {
        return Vector2(x * val, y * val);
    }

    Vector2 Vector2::operator+(Vector2 vecToAdd) {
        return Vector2(x + vecToAdd.x, y + vecToAdd.y);
    }

    Vector2 Vector2::operator*(Vector2 vecToMult) {
        return Vector2(x * vecToMult.x, y * vecToMult.y);
    }

    float Vector2::getLength() {
        return sqrt(x * x + y * y);
    }

    void Vector2::Normalize() {
        float mag = getLength();

        if (mag > 0) {
            x /= mag;
            y /= mag;
        }    
    }

    void Vector2::operator+=(Vector2 vecToAdd) {
        x += vecToAdd.x;
        y += vecToAdd.y;
    }

    void Vector2::operator-=(Vector2 vecToSub) {
        x -= vecToSub.x;
        y -= vecToSub.y;
    }

    Vector2 Vector2::Lerp(Vector2 source, Vector2 target, float speed) {
        return source * (1.0f - speed) + target * speed; 
    }




    /* VECTOR 3 */


    Vector3::Vector3(float xPos, float yPos, float zPos) :x(xPos), y(yPos), z(zPos) {}
    Vector3::Vector3(Vector2 vec, float zPos): x(vec.x), y(vec.y), z(zPos) {}
    Vector3::Vector3(float defVal): x(defVal), y(defVal), z(defVal) {}

    Vector3::Vector3() :x(0.0f), y(0.0f), z(0.0f) {}

    void Vector3::Print() {
        std::cout << x << ", " << y << ", " << z << std::endl;
    }

    Vector3 Vector3::operator-(Vector3 vecToSubstract) {
        return Vector3(x - vecToSubstract.x, y - vecToSubstract.y, z - vecToSubstract.z);
    }  

    Vector3 Vector3::operator*(float val) {
        return Vector3(x * val, y * val, z * val);
    }

    Vector3 Vector3::operator+(Vector3 vecToAdd) {
        return Vector3(x + vecToAdd.x, y + vecToAdd.y, z + vecToAdd.z);
    }

    Vector3 Vector3::operator*(Vector3 vecToMult) {
        return Vector3(x * vecToMult.x, y * vecToMult.y, z * vecToMult.z);
    }

    Vector3 Vector3::operator/(Vector3 vecToDivide) {
        return Vector3(x / vecToDivide.x, y / vecToDivide.y, z / vecToDivide.z);
    } 

    float Vector3::getLength() {
        return glm::sqrt(x * x + y * y + z * z);
    }

    void Vector3::Normalize() {
        float mag = getLength();

        if (mag > 0) {
            x /= mag;
            y /= mag;
            z /= mag;
        }    
    }

    float Vector3::Distance(Vector3 target) {
        float d = glm::sqrt((x - target.x) * (x - target.x) + (y - target.y) * (y - target.y) + (z - target.z) * (z - target.z));

        return sqrt(d);
    } 

    void Vector3::operator+=(Vector3 vecToAdd) {
        x += vecToAdd.x;
        y += vecToAdd.y;
        z += vecToAdd.z;
    }

    void Vector3::operator-=(Vector3 vecToSub) {
        x -= vecToSub.x;
        y -= vecToSub.y;
        z -= vecToSub.z;
    }

    Vector3 Vector3::Lerp(Vector3 source, Vector3 target, float speed) {
        return source * (1.0f - speed) + target * speed; 
    }
}
