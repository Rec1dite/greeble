#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "expression.h"

class nonTerminalExpr : public expression
{
    protected:
        std::vector<expression> children;
};