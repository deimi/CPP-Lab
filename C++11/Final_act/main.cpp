// Core Guideline
// E.19: Use a final_action object to express cleanup if no suitable resource handle is available
//
// Based on the articles of Bartłomiej Filipek and Rainer Grimms
//
// https://www.bfilipek.com/2017/04/finalact.html 
// https://www.heise.de/developer/artikel/C-Core-Guidelines-finally-in-C-4133759.html
// http://www.modernescpp.com/index.php/c-core-guidelines-when-you-can-t-throw-an-exception
//

#include <iostream>

#include "scanner.h"

using namespace std;


int main() {
    ScannerBad scannerBad;
    ScannerGood scannerGood;

    cout << "Doing scan with 0 Error" << endl;
    scannerBad.scanNodes(0);
    scannerGood.scanNodes(0);

    cout << endl << endl << "Doing scan with 2 Error" << endl;
    scannerBad.scanNodes(2);
    scannerGood.scanNodes(2);

    return 0;
}