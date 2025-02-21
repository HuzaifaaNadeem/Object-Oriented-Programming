#include <iostream>
#include <string>

using namespace std;

const int GRID_SIZE = 4;

class Ball {
private:
    int x, y;
public:
    Ball(int startX = 0, int startY = 0) : x(startX), y(startY) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int dx, int dy) {
        int newX = x + dx;
        int newY = y + dy;
        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) {
            x = newX;
            y = newY;
        } else {
            cout << "Invalid move! Ball stays at (" << x << ", " << y << ").\n";
        }
    }
};

class Goal {
public:
    bool isGoalReached(int ballX, int ballY) {
        return (ballX == 3 && ballY == 3);
    }
};

class Robot {
private:
    string name;
    int hits;
public:
    Robot(string robotName) : name(robotName), hits(0) {}
    void hitBall(Ball &ball, const string &direction) {
        if (direction == "up") ball.move(0, 1);
        else if (direction == "down") ball.move(0, -1);
        else if (direction == "left") ball.move(-1, 0);
        else if (direction == "right") ball.move(1, 0);
        else {
            cout << "Invalid direction! Use up, down, left, or right.\n";
            return;
        }
        hits++;
    }
    int getHits() const { return hits; }
    string getName() const { return name; }
};

class Team {
private:
    string teamName;
    Robot *player;
public:
    Team(string name, Robot *robot) : teamName(name), player(robot) {}
    Robot* getPlayer() { return player; }
    string getTeamName() const { return teamName; }
};

class Game {
private:
    Team *teamOne, *teamTwo;
    Ball ball;
    Goal goal;
public:
    Game(Team *t1, Team *t2) : teamOne(t1), teamTwo(t2), ball(0, 0) {}
    void play(Team *team) {
        Robot *robot = team->getPlayer();
        string direction;
        cout << team->getTeamName() << "'s turn. Move the ball towards the goal (up, down, left, right):\n";
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            cout << "Enter direction: ";
            cin >> direction;
            robot->hitBall(ball, direction);
            cout << "Ball position: (" << ball.getX() << ", " << ball.getY() << ")\n";
        }
        cout << team->getTeamName() << " reached the goal in " << robot->getHits() << " hits.\n";
    }
    void startGame() {
        cout << "Starting the game...\n";
        play(teamOne);
        ball = Ball(0, 0);
        play(teamTwo);
        declareWinner();
    }
    void declareWinner() {
        int hits1 = teamOne->getPlayer()->getHits();
        int hits2 = teamTwo->getPlayer()->getHits();
        if (hits1 < hits2) cout << teamOne->getTeamName() << " wins!\n";
        else if (hits2 < hits1) cout << teamTwo->getTeamName() << " wins!\n";
        else cout << "It's a tie!\n";
    }
};

int main() {
    Robot robot1("Vini Jr"), robot2("Lewandowski");
    Team team1("Real Madrid", &robot1), team2("Barcelona", &robot2);
    Game game(&team1, &team2);
    game.startGame();
    return 0;
}
