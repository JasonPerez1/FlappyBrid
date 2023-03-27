
#include "flappybird.h"

// Functions
void Birdgame::handleInput(){
if ( keyUpJustPressed()){
bird.setVelocity(Vatclick);
    }
}

void Birdgame::updateVals(){
    updateBird();
    updatePipes();
}

void Birdgame::updateBird(){
    bird.moveBird();
}

void Birdgame::updatePipes(){
    for (int i=0; i <= pipes.getSize(); i++){
        pipes.getFirst().pipeleft();
        pipes.add(pipes.remove());
    }
}

void Birdgame::plantPipe(){
    //randomize height, set height, add new pipe
    nextPipeLocation.setSecond(rand()%10+2);
    nextPipe.setBottomLeft(nextPipeLocation);
    pipes.add(nextPipe);
}

void Birdgame::removePipe(){
    if (pipes.getFirst().getBottomLeft().getFirst() >= 0){
        pipes.remove();
    }
}

void Birdgame::detectDeath(){
    if (pipes.getFirst().xinside(bird.getlocation())){
        if (pipes.getFirst().yinside(bird.getlocation)){
            // KILL BIRD
        }
    }
}

void Birdgame::paintBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == j % 2) {
                setBGColor(i, j, NamedColor::lightblue);
            } else {
                setBGColor(i, j, NamedColor::skyblue);
            }
        }
    }
}

void Birdgame::drawPipes(){
    for (int i=0; i <= pipes.getSize(); i++){
        currentPipe.setBottomLeft(pipes.getFirst().getBottomLeft());
        currentPipe.setGap(pipes.getFirst().getGap())
        currentPipe.setWidth(pipes.getFirst().getWidth())

        for(int width = 0; width <= currentPipe.getWidth(); width++){
            for(int height = 0; height <= BOARD_SIZE ; height++){
                if (height <= currentPipe.getBottomLeft().getSecond() || 
                    height >= currentPipe.getBottomLeft().getSecond() + currentPipe.getGap()){
                    setBGColor(currentPipe.getFirst().getBottomLeft().getFirst() + width, height, NamedColor::forrestgreen);
                    }
                }
            }
        pipes.add(pipes.remove());
    }
}

void Birdgame::drawBird(){
    setBGColor(bird.getLocation().getFirst(), bird.getLocation().getFirst(), NamedColor::red);
}

void Birdgame::paint(){
    paintBoard();
    drawPipes();
    drawBird();
}

void Birdgame::gameLoop() {
    frame += 1;
    handleInput();
    if (frame >= 5) {           // this could be changed to make the game run faster...
        updateVals();
        detectDeath();
        paint();
        frame = 0;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Usage: bird <bridges_username> <bridges_user_id>" << endl;
        exit(-1);
    }

    Birdgame game(1234, argv[1], argv[2]);

    game.start();
}