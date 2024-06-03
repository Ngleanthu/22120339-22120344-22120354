#include <iostream>
#include <string>
#include "struct_definitions/Class.h"
#include "struct_definitions/Course.h"
#include "struct_definitions/Enums.h"
#include "struct_definitions/LinkedListNode.h"
#include "struct_definitions/User.h"

struct SchoolYear
{
    std::string school_year;
    LLNode *class_list;
};
