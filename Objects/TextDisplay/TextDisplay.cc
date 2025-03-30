export module textDisplay;
import player;
import <vector>;
import <string>;
import <iostream>;

export class TextDisplay{
    std::vector<std::vector<char>> display;
    public:
        TextDisplay() = default;
        TextDisplay(const std::vector<std::vector<char>>& display);
        void printBoard(const Player *plr, std::string boardState) const;
        friend std::ostream& operator<<(std::ostream& os, const TextDisplay& td);

};
