//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef PROJECT_NAME_VECTOR2_H
#define PROJECT_NAME_VECTOR2_H

class Vector2 {
public:
    float x;
    float y;

    Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector2() {
        this->x = 0;
        this->y = 0;
    }

    Vector2 add(const Vector2& v) const {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 sub(const Vector2& v) const {
        return Vector2(x - v.x, y - v.y);
    }

    Vector2 mul(const Vector2& v) const {
        return Vector2(x * v.x, y * v.y);
    }

    Vector2 div(const Vector2& v) const {
        return Vector2(x / v.x, y / v.y);
    }

    Vector2 add_v(const float& v) const {
        return Vector2(x + v, y + v);
    }

    Vector2 sub_v(const float& v) const {
        return Vector2(x - v, y - v);
    }

    Vector2 mul_v(const float& v) const {
        return Vector2(x * v, y * v);
    }

    Vector2 div_v(const float& v) const {
        return Vector2(x / v, y / v);
    }

    float sum() const {
        return x + y;
    }

    Vector2 unit() const {
        return Vector2(x / sum(), y / sum());
    }

    Vector2 round() {
        return Vector2((float)((int)(x)), (float)((int)(y)));
    }
};

#endif //PROJECT_NAME_VECTOR2_H
