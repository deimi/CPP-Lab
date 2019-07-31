// Copyright (c) 2019 Matthias Deimbacher
// Licensed under MIT License

#pragma once

#include <iostream>
#include "final_act.h"

using namespace std;

void addExtraNodes(){
    cout << "Adding Node" << endl;
}

void removeExtraNodes() {
    cout << "Removing Node" << endl;
}


class ScannerGood {
    public:
        bool scanNodes(int aError) {
            cout << "ScanningGood...." << endl;

            // code...
            addExtraNodes();
            //auto _0 = finally([] { removeExtraNodes(); });      // < C++17
            final_act _0([] { removeExtraNodes(); });           // >= C++17

            // code...
            if(1 == aError) {
                return false;
            }

            addExtraNodes();
            auto _1 = finally([] { removeExtraNodes(); });

            // code...
            if(2 == aError) {
                return false;
            }

            addExtraNodes();
            auto _2 = finally([] { removeExtraNodes(); });

            // code...
            if(3 == aError) {
                return false;
            }

            addExtraNodes();
            auto _3 = finally([] { removeExtraNodes(); });

            // code...
            if(4 == aError) {
                return false;
            }

            addExtraNodes();
            auto _4 = finally([] { removeExtraNodes(); });

            // code...
            return true;
        }
};

class ScannerBad {
    public:
        bool scanNodes(int aError) {
            cout << "ScanningBad...." << endl;
            // code...
            addExtraNodes();

            // code...
            if(1 == aError) {
                removeExtraNodes();
                return false;
            }

            addExtraNodes();

            // code...
            if(2 == aError) {
                removeExtraNodes();
                removeExtraNodes();
                return false;
            }

            addExtraNodes();

            // code...
            if(3 == aError) {
                removeExtraNodes();
                removeExtraNodes();
                removeExtraNodes();
                return false;
            }

            addExtraNodes();

            // code...
            if(4 == aError) {
                removeExtraNodes();
                removeExtraNodes();
                removeExtraNodes();
                removeExtraNodes();
                return false;
            }

            addExtraNodes();



            // code...
            removeExtraNodes();
            removeExtraNodes();
            removeExtraNodes();
            removeExtraNodes();
            removeExtraNodes();
            return true;
        }
};