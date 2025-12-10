#include "Snake.h"


Snake::Snake() {
    // tymczasowo trzy segmenty w poziomie
    segments.push_front({5, 5});
    segments.push_back({4, 5});
    segments.push_back({3, 5});
}

const Point& Snake::head() const {
    return segments.front();
}

void Snake::move(Direction, bool) {

}

bool Snake::collidesWith(const Point&) const {
    return false;
}

bool Snake::selfCollision() const {
    return false;
}
