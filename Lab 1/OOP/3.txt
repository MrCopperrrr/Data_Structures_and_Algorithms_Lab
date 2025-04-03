Character::Character() {
    hp=x=y=0;
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
    this->hp = hp;
    this->x = x;
    this->y = y;

}

int Character::getHp() {
    // STUDENT ANSWER
    
    return hp;

}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return x;

}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() {
    // STUDENT ANSWER
    return y;

}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
    int distance = abs(this->x - other->x) + abs(this->y - other->y);
    return distance;
}