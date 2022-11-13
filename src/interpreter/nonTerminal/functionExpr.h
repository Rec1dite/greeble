#pragma once
#include "../nonTerminalExpr.h"

class functionExpr : public nonTerminalExpr {
    public:
        void solve(std::string context);
};