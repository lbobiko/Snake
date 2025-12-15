#include "Snake.h"

Snake::Snake() {
    // Start: trzy segmenty w poziomie
    m_segments.push_front({5, 5}); // głowa
    m_segments.push_back({4, 5});
    m_segments.push_back({3, 5});  // ogon
}

const Point& Snake::head() const {
    return m_segments.front();
}

void Snake::move(Direction direction, bool grow) {
    // 1. bazujemy na obecnej głowie
    Point newHead = head();

    // 2. zmiana współrzędnych zależnie od kierunku
    switch (direction) {
    case Direction::Up:    newHead.y -= 1; break;
    case Direction::Down:  newHead.y += 1; break;
    case Direction::Left:  newHead.x -= 1; break;
    case Direction::Right: newHead.x += 1; break;
    }

    // 3. dodajemy nową głowę na początek
    m_segments.push_front(newHead);

    // 4. jeśli nie rośniemy, usuwamy ogon
    if (!grow) {
        m_segments.pop_back();
    }
}

bool Snake::collidesWith(const Point& p) const {
    for (const auto& seg : m_segments) {
        if (seg.x == p.x && seg.y == p.y) {
            return true;
        }
    }
    return false;
}

bool Snake::selfCollision() const {
    if (m_segments.empty()) return false;

    const Point& h = head();
    bool first = true;
    for (const auto& seg : m_segments) {
        if (first) { first = false; continue; } // pomijamy głowę
        if (seg.x == h.x && seg.y == h.y) {
            return true;
        }
    }
    return false;
}

const std::deque<Point>& Snake::segments() const {
    return m_segments;
}

void Snake::resetTo(const Point& headPos) {
    m_segments.clear();
    m_segments.push_front(headPos);
    m_segments.push_back({headPos.x - 1, headPos.y});
    m_segments.push_back({headPos.x - 2, headPos.y});
}
