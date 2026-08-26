// Copyright 2025 Mena Rezkalla
#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

using sf::Drawable;
using sf::ConvexShape;
using sf::Color;
using sf::Vector2f;
using sf::RenderTarget;
using sf::RenderStates;
using sf::Transform;

namespace TriManager {
class Triangle: public sf::Drawable {
 public:
    Triangle(float spawnX, float spawnY, float sideLen, float rot, Color color);
    Vector2f getWorldPoint(int index);
    float getRot();
    void draw(RenderTarget& target, RenderStates states) const override;
 private:
    ConvexShape triangle;
};
}  // namespace TriManager

