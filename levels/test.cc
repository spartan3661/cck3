
import <vector>;
import <iostream>;
import <fstream>;
void readLevel(std::vector<std::vector<char>> refBoard, std::vector<std::vector<char>> displayBoard){
    int iCounter = 0;
    int jCounter = 0;
    string file = "./levels/level" + to_string(currentLevel) + ".txt";
    ifstream levelFile(file);
    
    char ch;
    vector<char> tempVector;
    while (levelFile.get(ch)){

        if (ch == '\n'){
            refBoard.emplace_back(tempVector);
            displayBoard.emplace_back(tempVector);
            tempVector.clear();
            continue;
            jCounter++;
        }
        if (ch == '.'){
            validSpawn.push_back(tuple<iCounter, jCounter>)
        }
        tempVector.push_back(ch);
        iCounter++;

    }

    if (!tempVector.empty()) {
        refBoard.emplace_back(tempVector);
        displayBoard.emplace_back(tempVector);
    }
}


int main(){
    std::vector<std::vector<char>> refBoard;
    std::vector<std::vector<char>> displayBoard;
    readLevel(refBoard, displayBoard);



}
