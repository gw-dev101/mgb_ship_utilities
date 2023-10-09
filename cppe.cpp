
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


struct tree_node{
    int item_id;
    int item_orientation;
    tree_node* left;
    tree_node* right;
    tree_node* up;

};
struct Tree{
    tree_node* root;
    int path_count;
};
bool isValidShipExportCode(string shipExportCode){
    //check if the ship export code is in the correct format
    if (shipExportCode.length() != 1+16*2+14*14*3){
        return false;
    }
    //check if the first character is 1
    if (shipExportCode[0] != '1'){
        return false;
    }
    //check if the rest of the characters are digits
    for (int i=1; i<shipExportCode.length(); i++){
        if (!isdigit(shipExportCode[i])){
            return false;
        }
    }
    return true;
    //could and should be improved but no point for now
}
string getShipExportCode(){
    string shipExportCode="";
    while (isValidShipExportCode(shipExportCode) == false){
        cout << "Enter a valid ship export code: ";
        cin >> shipExportCode;
    }
    return shipExportCode;
}
//these are global variables
int tiles[16];
int items[14][14];
int itemOrientation[14][14];
int path[14][14];
float fireRate=3.0;

void processShipExportCode(string shipExportCode){
    //get the tiles
    for (int i=0; i<16; i++){
        tiles[i] = stoi(shipExportCode.substr(1+2*i, 2));
        fireRate -= 0.2(tiles[i] == 1);
    }
    //get the items
    for (int i=0; i<14; i++){
        for (int j=0; j<14; j++){
            items[i][j] = stoi(shipExportCode.substr(1+16*2+3*(14*i+j), 2));
            itemOrientation[i][j] = stoi(shipExportCode.substr(1+16*2+3*(14*i+j)+2, 1));
        }
    }
    //get the path
    //first get the emitter item it has id 02 and should have orientation 0
    int emitterItemRow, emitterItemCol;
    for (int i=0; i<12; i++){
        for (int j=0; j<12; j++){
            if (items[i][j] == 2 && itemOrientation[i][j] == 0){
                emitterItemRow = i;
                emitterItemCol = j;
            }
        }
    }
    int currentRow = emitterItemRow;
    int currentCol = emitterItemCol;
    int currentOrientation = 0;
    int pathCount = 0;
    Tree path=path_fill_function(currentRow, currentCol, currentOrientation, pathCount);

}

Tree path_fill_function(int currentRow, int currentCol, int currentOrientation, int pathCount) {
    Tree path;
    path.root = new tree_node;
    path.root->item_id = items[currentRow][currentCol];
    path.root->item_orientation = itemOrientation[currentRow][currentCol];
    int nextRow = currentRow;
    int nextCol = currentCol;
    int nextOrientation = currentOrientation;
    int nextPathCount = pathCount;
    int nextItem = items[currentRow][currentCol];
    switch (items[currentRow][currentCol])
    {
        ///what the fuck i am doing please help
        //i need to do something different based on if the item is a turn , a spliter or something else 
    case 5:// a left turn 
        //check if valid point of entry to next item then
        //do something if there is
        nextItem=
        if isValidentry(

        
            
            break;
    case 6:// a right turn
        //check if valid point of entry to next item then
        //do something if there is
        break;
    case 14:// a two way spliter 
        //check for a valid point of entry on both sides then
        //do something if there is 
        break;
    case 17:// a three way spliter 
        //check for valid entry on all 3 sides then 
        //do something if there is 
        break;
    case 22:// the random two way spliter 
        //check for a valid point of entry on both sides then
        //do something if there is 
        break;
    case default://continue in the same direction if next item has a valid entry point


    }
}
    bool isValidentry(int direction, int currentRow, int currentCol) {
        // Check for valid directions and adjust currentRow and currentCol accordingly
        switch (direction) {
        case 0: // Up
            currentRow--;
            break;
        case 1: // Right
            currentCol++;
            break;
        case 2: // Down
            currentRow++;
            break;
        case 3: // Left
            currentCol--;
            break;
        default:
            return false; // Invalid direction
        }

        // Check if the new position is out of bounds
        if (currentRow < 0 || currentRow >= numRows || currentCol < 0 || currentCol >= numCols) {
            return false;
        }

        // Check the item orientation
        int currentOrientation = itemOrientation[currentRow][currentCol];
        int currentItem = items[currentRow][currentCol];

        // Check the conditions based on the direction and orientation
        switch (direction) {
        case 0: // Up
            switch (currentOrientation) {
            case 0: // Up
                return (currentItem == 0 || currentItem == 29 || currentItem == 30 || currentItem == 3);
            case 2: // Down
                return (currentItem == 0 || currentItem == 3);
            default: // Left or Right
                return (currentItem == 0 || currentItem == 29 || currentItem == 30 || currentItem == 3);
            }
        case 1: // Right
            switch (currentOrientation) {
            case 1: // Right
                return (currentItem == 0 || currentItem == 29 || currentItem == 30 || currentItem == 3);
            case 3: // Left
                return (currentItem == 0 || currentItem == 3);
            default: // Up or Down
                return (currentItem == 0 || currentItem == 29 || currentItem == 30 || currentItem == 3);
            }
        case 2: // Down
            switch (currentOrientation) {
            case 0: // Up
                return (currentItem == 0 || currentItem == 3);
            case 2: // Down
                return (currentItem == 0 || currentItem == 29 || currentItem == 30 || currentItem == 3);
            default: // Left or Right
                return (currentItem == 0 || currentItem == 3);
            }
        case 3: // Left
            switch (currentOrientation) {
            case 1: // Right
                return (currentItem == 0 || currentItem == 3);
            case 3: // Left
                return (currentItem == 0 || currentItem == 29 || currentItem == 30 || currentItem == 3);
            default: // Up or Down
                return (currentItem == 0 || currentItem == 3);
            }
        }

        return false; // Default case, should not reach here
    }
