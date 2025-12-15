#include "RunningState.h"
#include "GraSnake.h"

void RunningState::tick(GraSnake& game) {
    // 1. policz nową głowę
    Point newHead = game.getSnake().head();

    switch (game.getDirection()) {
    case Direction::Up:    newHead.y -= 1; break;
    case Direction::Down:  newHead.y += 1; break;
    case Direction::Left:  newHead.x -= 1; break;
    case Direction::Right: newHead.x += 1; break;
    }

    // 2. kolizja ze ścianą
    if (!game.getBoard().isInside(newHead)) {
        game.setStateGameOver();
        return;
    }

    // 3. jabłko
    bool grow = (newHead.x == game.getApple().x &&
                 newHead.y == game.getApple().y);

    // 4. ruch
    game.moveSnake(grow);

       // 5. kolizja z ciałem
    if (game.getSnake().selfCollision()) {
        game.setStateGameOver();
        return;
    }

    if (grow) {
        game.addScore(1);     // Zwiększamy wynik
        game.spawnApple();
    }

    // 6. nowe jabłko
    if (grow) {
        game.spawnApple();
    }
}
