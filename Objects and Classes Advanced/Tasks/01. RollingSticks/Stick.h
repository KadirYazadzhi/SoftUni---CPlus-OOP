


class Stick {
private:
    mutable char curStick;
    mutable int position;

public:
    Stick() : curStick('/'), postiton(0) {}

    char nextAnimation(void) const {

        switch (curStick) {
            case '/':
                curStick = "_";
                break;
            case '_':
                curStick = "\\";
                break;
            case '\\':
                curStick = "|";
                break;
            case '|':
                curStick = "/";
                position++;
                break;
        }
    }

    int getPosition(void) const {

        return position;
    }
};

