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

StatusCode Snake::move(const Direction dir, const std::vector<Point> &obstacles, std::vector<Point> &powerUps) {
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

    for (const auto &o : obstacles) {
        if (o == newPos) {
            return StatusCode::SNAKE_DEAD;
        }
    }

    for (const auto &node : _snakeNodes) {
        if (node == newPos) {
            return StatusCode::SNAKE_DEAD;
        }
    }

    bool powerUpConsumed = false;
    for (auto it = powerUps.begin(); it != powerUps.end(); ++it) {
        if (*it == newPos) {
            powerUpConsumed = true;
            powerUps.erase(it);
            break;
        }
    }

    _snakeNodes.push_front(newPos);
    _currPos = newPos;

    if (!powerUpConsumed) {
        _snakeNodes.pop_back();
    }

    return powerUpConsumed ? StatusCode::SNAKE_GROWING : StatusCode::SNAKE_MOVING;
}
