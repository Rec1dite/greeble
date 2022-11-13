#pragma once
#include <string>
#include "expression.h"

class terminalExpr : public expression
{
    public:
        void solve(std::string context);
};