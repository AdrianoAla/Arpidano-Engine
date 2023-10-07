//
// Created by Adriano Alasia on 2023-10-06.
//

#ifndef PROJECT_NAME_CAMERA_H
#define PROJECT_NAME_CAMERA_H

#include "../Utils/Vector2.h"

#include "../ECS/ECS.h"


class Camera {

    public:
        float speed = 2.5;
        Vector2 position;
        Entity *target;
        bool movable = true;

        Camera();

        Camera(Entity *target);
        Camera(bool m);

        void setTarget(Entity *target);

        void update();

        Vector2 getPos() const { return position; }

};


#endif //PROJECT_NAME_CAMERA_H

