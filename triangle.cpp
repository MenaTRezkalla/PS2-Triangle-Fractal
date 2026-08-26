// Copyright 2025 Mena Rezkalla
#include "triangle.hpp"

namespace TriManager {
const float degToRad = M_PI / 180.0;
const float rad60 = 60 * degToRad;

Triangle::Triangle(float spawnX, float spawnY, float sideLen, float rot, Color color) {
    triangle = ConvexShape();
    triangle.setPointCount(3);
    triangle.setPoint(0, Vector2f(0, 0));

    float tempX = sideLen * cos(rad60);
    float tempY = sideLen * sin(rad60);
    tempY *= -1;
    triangle.setPoint(1, Vector2f(tempX, tempY));

    tempX *= -1;
    triangle.setPoint(2, Vector2f(tempX, tempY));

    triangle.setOrigin(0, 0);

    triangle.setPosition(spawnX, spawnY);

    triangle.setRotation(rot);

    if (color == Color::Transparent) {
        triangle.setFillColor(Color::Transparent);
        triangle.setOutlineColor(Color::White);
        triangle.setOutlineThickness(1);
    } else {
        triangle.setFillColor(color);
    }
}
Vector2f Triangle::getWorldPoint(int index) {
    Vector2f point = triangle.getPoint(index);
    Transform transform = triangle.getTransform();
    point = transform.transformPoint(point);
    return point;
}
float Triangle::getRot() {
    return triangle.getRotation();
}
void Triangle::draw(RenderTarget& target, RenderStates states) const {
    target.draw(triangle, states);
}
}  // namespace TriManager
