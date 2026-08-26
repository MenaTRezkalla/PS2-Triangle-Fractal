// Copyright 2025 Mena Rezkalla
#include <vector>
#include "triangle.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using TriManager::Triangle;
using sf::Color;
using sf::Vector2f;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Event::Closed;
using std::vector;
using std::stod;
using std::stoi;
using std::stof;

vector<Triangle> fractal(double L, int N, float R, int colorful);
void fractalHelper(vector<Triangle>& veT, float spX, float spY, float spR,
                                            double L, int N, int colorful);
Vector2f calcWindowSize(double L, int N);

const float degToRad = M_PI / 180.0;

int main(int argc, char* argv[]) {
      if (argc < 3 || argc > 5) {
        return -1;
    }

    double L = stod(argv[1]);
    int N = stoi(argv[2]);
    float R = 0;
    int colorful = 0;

    if (argc > 3)
        R = stof(argv[3]);
    if (argc > 4)
        colorful = stoi(argv[4]);

    vector<Triangle> TriTargets;
    TriTargets = fractal(L, N, R, colorful);
    vector<Triangle>::iterator it;

    Vector2f windowSize = calcWindowSize(L, N);

    RenderWindow window(VideoMode(windowSize.x, windowSize.y), "Sierpinski triangle");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Closed)
                window.close();
        }

        window.clear();
        for (it = TriTargets.begin(); it != TriTargets.end(); it++)
            window.draw(*it);
        window.display();
    }
    return 0;
}

vector<Triangle> fractal(double L, int N, float R, int colorful) {
    vector<Triangle> drawTriangles;

    Vector2f windowSize = calcWindowSize(L, N);

    int spawnX = (windowSize.x / 2.0) - (N * (L / ((N + 1.0) * 3.5)));
    int spawnY = (windowSize.y / 2.0) + ((L * (sqrt(3) / 2.0)) / 2.0);

    fractalHelper(drawTriangles, spawnX, spawnY, R, L, N, colorful);
    return drawTriangles;
}

void fractalHelper(vector<Triangle>& veT, float spX, float spY, float spR,
                                            double L, int N, int colorful) {
    Color p = Color::Transparent;
    if (colorful == 1) {
        p = Color(255, 255, 255);
        p.r = p.r + (N * 123) % 256;
        p.g = p.g + (N * 231) % 256;
        p.b = p.b + (N * 312) % 256;
    }

    Triangle myTri(spX, spY, L, spR, p);
    veT.push_back(myTri);

    if (N <= 0)
        return;

    float spawnX;
    float spawnY;

    for (int i = 0; i < 3; i++) {
        spawnX = myTri.getWorldPoint(i).x;
        spawnY = myTri.getWorldPoint(i).y;
        fractalHelper(veT, spawnX, spawnY, (spR + (240 * (i + 1))), (L / 2.0), (N - 1), colorful);
    }

    return;
}

Vector2f calcWindowSize(double L, int N) {
    float temp = L * (sqrt(3) / 2.0);
    float windowX = L * (3.0 - 2.0 / pow(2, N));
    float windowY = temp * (3.0 - 2.0 / pow(2, N));
    windowX -= (N * (L / ((N + 1.0) * 3.5))) - 20.0;
    windowY += 20.0;
    return Vector2f(windowX, windowY);
}
