#pragma once
#include <iostream>
#include "../utils/logics.h"
#include "../utils/glUtils.h"
#include "../Storage/Storage.h"
#include "../macros.h"
using namespace std;

class Processor {
private:
    static Storage storage;

public:
    static void initShapes();
    static void display();
    static void reshape(GLsizei width, GLsizei height);
    static void timer(int value);
};
