#pragma once
#include "../Shape/index.h"
#include <vector>
#include <iostream>
using namespace std;

class Storage {
private:
    vector<Shape*> shapes;

public:
    Storage() {
        
    }

    ~Storage() {
        for (int i = 0; i < shapes.size(); i++) {
            delete shapes[i];
        }
    }

public:
    void addShapes(vector<Shape*> shapes) {
        this->shapes = shapes;
    }

    void draw() {
        for (int i = 0; i < shapes.size(); i++) {
            shapes[i]->draw();
        }
    }
};