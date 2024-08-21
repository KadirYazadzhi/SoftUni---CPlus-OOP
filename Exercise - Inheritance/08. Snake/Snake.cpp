#include "Snake.h"

Snake::Snake(const int fieldRows, const int fieldCols, const Point &startPos)
: _FIELD_ROWS(fieldRows),
_FIELD_COLS(fieldCols),
_currPos(startPos),
_snakeNodes(1, startPos) {}

Snake::~Snake() {}

std::deque<Point> & Snake::getSnakeNodes() {
    return _snakeNodes;
}

StatusCode Snake::move(const Direction dir, const std::vector <Point> &obstacles, std::vector <Point> &powerUps) {
  Point newPos(_currPos);

    switch (dir) {
        case Direction::UP:
            newPos.row -= 1;
            break;
        case Direction::DOWN:
            newPos.row += 1;
            break;
        case Direction::LEFT:
            newPos.col -= 1;
            break;
        case Direction::RIGHT:
            newPos.col += 1;
            break;
    }

    if (newPos.row < 0 || newPos.col < 0 || newPos.row >= _FIELD_ROWS || newPos.col >= _FIELD_COLS) {
        return StatusCode::SNAKE_DEAD;
    }

    for (auto & o : obstacles) {
        if (o == newPos) {
            return StatusCode::SNAKE_DEAD;
        }
    }

    for (auto & o : _snakeNodes) {
        if (o == newPos) {
            return StatusCode::SNAKE_DEAD;
        }
    }

    bool powerUp = false;
    for (auto o = powerUps.begin(); o != powerUps.end(); o++) {
        if (*o == newPos) {
            powerUp = true;
            powerUps.erase(o);
            break;
        }
    }

    _snakeNodes.push_back(newPos);
    _currPos = newPos;
    if (!powerUp) {
        _snakeNodes.pop_back();
    }

    return powerUp == true ? StatusCode::SNAKE_GROWING : StatusCode::SNAKE_MOVING;
}